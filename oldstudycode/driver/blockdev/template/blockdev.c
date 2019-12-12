/* ==================================================================
 *       Filename:  blockdev.c
 *    Description:  
 *        Created:  2013年10月25日 10时58分10秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/genhd.h>
#include <asm/uaccess.h>
#include <linux/spinlock.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>
#define BLK_NAME "blockdev"
#define KERNEL_SECT_SIZE 512


static int   blk_major = 0;
static int   hardsect_size = 512;
static int   nsectors = 1024;

struct blk_dev{
	unsigned char   *data; //数据缓冲
	short           users; //用户数量
	int             size;  //磁盘总大小
	short           media_change_flags; //可移动设备标志
	spinlock_t      spinlock;  //自旋锁
	struct request_queue* queue;//读写请求队列
	struct gendisk*  gd;//通用磁盘设备描述

};

struct blk_dev *devp=NULL;

static int blk_open(struct block_device* device, fmode_t mode)
{
	struct blk_dev *dev = device->bd_disk->private_data;
	//数据私有化操作
	spin_lock(&dev->spinlock);
	dev->users ++;
	spin_unlock(&dev->spinlock);
	printk(KERN_INFO"blk_open() invoked!\n");
	return 0;
}

static int blk_release(struct gendisk* gd , fmode_t mode )
{
	struct blk_dev* dev = gd->private_data;
	spin_lock(&dev->spinlock);
	dev->users --;
	spin_unlock(&dev->spinlock);
	printk(KERN_INFO"blk_release invoked!\n");
	return 0;

}
static int blk_media_changed(struct gendisk *gd)
{
	struct blk_dev *dev = gd->private_data;
	return dev->media_change_flags;
}
static int blk_revalidate_disk(struct gendisk *gd)
{
	struct blk_dev *dev = gd->private_data;
	if(dev->media_change_flags)
	{
		dev->media_change_flags = 0;
		memset(dev->data, 0, dev->size);
	}
	return 0;
}
static int blk_ioctl(struct block_device *device, fmode_t mode, unsigned   cmd, unsigned long arg)
{
	long size = 0;
	struct hd_geometry geo;
	struct blk_dev* dev= device->bd_disk->private_data;
	switch(cmd)
	{
          case HDIO_GETGEO:
			 size=dev->size *(hardsect_size/KERNEL_SECT_SIZE);
			 geo.cylinders = (size &~ 0x3f) >> 6;
			 geo.heads = 4;
			 geo.sectors = 16;
			 geo.start = 4;
			 if(copy_to_user((void __user *)arg, &geo, sizeof(geo)))
				 return -EFAULT;
			  break;
		  default:
			  return -ENOTTY; //未知类型
	}
	return 0;
}
static struct block_device_operations blk_fops = {
	.owner = THIS_MODULE, 
	.open  = blk_open, 
	.release = blk_release, 
	.media_changed = blk_media_changed, 
	.revalidate_disk = blk_revalidate_disk, 
	.ioctl            = blk_ioctl, 
};
static void transfer_data(struct blk_dev *dev, unsigned long sect,unsigned long nsect, char* buffer, int flags )
{
	//计算当前扇区位置
	unsigned long offset = sect * KERNEL_SECT_SIZE;
	//需要存储数据的空间大小
	unsigned long size=nsect * KERNEL_SECT_SIZE;
	//判断磁盘空间是否足够
	if((offset +size ) > dev->size)
	{
		printk(KERN_ERR"Have no enough space!\n");
		printk(KERN_INFO"Cur_pos: %ld, REQ_SIZE:%ld\n", offset, size);
		return ;
	}
	if(flags)
	{
		//写操作
		memcpy(dev->data + offset, buffer, size);

	}else{
		//读操作
		memcpy(buffer,dev->data+offset,  size);
		
	}
	printk(KERN_INFO"dev_data: %s\n", dev->data);

}
static void request_handler(struct request_queue* q)
{
	//存储获取到的每一个请求
	struct request* req;
	req = blk_fetch_request(q);
	while(req != NULL)
	{
		struct blk_dev * dev = req->rq_disk->private_data;
		//if(blk_fs_request(req))
		//{//2.6 KERNEL
		if(!(req->cmd_type == REQ_TYPE_FS))
		{//卸载
			printk(KERN_INFO"Not a fs request!\n");
			//结束所有请求操作
			__blk_end_request_all(req, -EIO);
			continue;
		}
		//文件请求操作 数据传输操作
		transfer_data(dev, blk_rq_pos(req), blk_rq_cur_sectors(req), req->buffer, rq_data_dir(req));
		//获取下一个操作请求
		if(!__blk_end_request_cur(req, 0))
		{
			req = blk_fetch_request(q);
		}
		printk(KERN_INFO"request_handler invoked!\n");
	}
}

static void blkdev_setup(struct blk_dev* dev)
{
	//设置磁盘总大小
	dev->size = hardsect_size * nsectors;
	//分配磁盘缓冲
	dev->data= (unsigned char *)vmalloc(dev->size);
	if(dev->data==NULL)
	{
		printk(KERN_ERR"vmalloc data error!\n");
		//return;
	}
	//初始化自旋锁
	spin_lock_init(&devp->spinlock);
	//初始化请求队列
	dev->queue=blk_init_queue(request_handler, &dev->spinlock);
	if(dev ->queue == NULL)
	{
		printk(KERN_ERR"blk_init  error!\n");
		//return;

	}
	//告知内核自定义设置的磁盘扇区尺寸
	blk_queue_logical_block_size(dev->queue, hardsect_size);
	//指定请求队列映射的目标
	dev->queue->queuedata = dev;
	//分配磁盘描述
	devp->gd=alloc_disk(1);
	//磁盘描述的初始化
	memset(dev->data, 0, dev->size);
	dev->gd->major = blk_major;
	dev->gd->first_minor = 0;
	dev->gd->minors = 1;
	strcpy(dev->gd->disk_name, BLK_NAME);
	dev->gd->fops = &blk_fops;
	dev->gd->queue=dev->queue;
	dev->gd->private_data=devp;
	//通知内核磁盘扇区数量
	set_capacity(dev->gd, nsectors);
	//将磁盘添加到内核
	add_disk(dev->gd);
}



static int __init blk_init(void)
{
	//注册主设备号
	blk_major = register_blkdev(blk_major, BLK_NAME);
	if(blk_major < 0)
	{
		printk(KERN_ERR"register_blkdev error!\n");
		return -EAGAIN;
	}
	printk(KERN_INFO"MAJOR:%d\n", blk_major);

	//分配内存
	devp = (struct blk_dev*)kmalloc(sizeof(struct blk_dev), GFP_KERNEL);
	if(NULL == devp)
	{
		printk(KERN_ERR"kmalloc error!\n");
		goto err1;
	}else
	{
		printk(KERN_ERR"kmalloc successfuly!\n");

	}
	memset(devp, 0, sizeof(struct blk_dev));
	//3.初始化设备
	blkdev_setup(devp);
	return 0;
err1:
	unregister_blkdev(blk_major, BLK_NAME);
	return -ENOMEM;
}
static void __exit blk_exit(void)
{
	printk(KERN_INFO"blk_exit invoked!\n");
}

MODULE_LICENSE("Dual BSD/GPL");
module_init(blk_init);
module_exit(blk_exit);





























