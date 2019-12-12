/* ==================================================================
 *       Filename:  chardev.c
 *    Description:  
 *        Created:  2013年10月18日 11时16分25秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
//struct cdev , cdev_init/cdev_add/cdev_del
#include <linux/types.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include "charioctl.h"
//获取ioctl操作指令

//kmalloc/kfree
#define MAJOR_NUM 200
#define MINOR_NUM 0
#define DEV_NAME "chardev"
//#define MAX_LEN  0x1000 //4kb
static int major_num = 0;

typedef struct
{
	struct  cdev cdev;
	char    data[MAX_LEN];
	size_t  cur_len;//记录当前的数据长度
	//unsigned char   *data;


}global_dev;
global_dev* global_devp = NULL;
static ssize_t char_read(struct file* file , char __user *buffer, size_t size, loff_t *offset)
{
	ssize_t ret = 0;
	unsigned long p = (unsigned long )*offset;
	size_t count = 0; //真正要移动的数据长度


	//将私有指针操作对象设备获取到
	global_dev* devp = file->private_data;
	if(size > devp->cur_len - p)
	{

		count = devp->cur_len -p;
	}else
	{
		count = size;
	}
	ret = copy_to_user(buffer, devp->data + p, count);
	if(ret >0) //failure
	{
		ret = count -ret;
	}else{
		ret = count ;
	}
	printk(KERN_INFO"read %d bytes data(%s) successful!\n", ret, devp->data);
	//移动文件操作的偏移量
	file->f_pos +=ret;
	*offset += ret;


	return ret;
}
static ssize_t char_write(struct file* file ,const char __user *buffer, size_t size, loff_t *offset)
{
	ssize_t ret = 0;
	unsigned long p = (unsigned long )*offset;
	size_t count = 0; //真正要移动的数据长度
	global_dev* devp = file->private_data;
	if(size > MAX_LEN - p)
	{

		count = MAX_LEN -p;
	}else
	{
		count = size;
	}
	ret = copy_from_user(devp->data + p,buffer,  count);
	if(ret >0) //failure
	{
		ret = count -ret;
	}else{
		ret = count ;
	}
	printk(KERN_INFO"write %d bytes data(%s) successful!\n", ret, devp->data);

	//移动文件操作的偏移量
	file->f_pos +=ret;
	*offset += ret;
	devp->cur_len+=ret;


	return ret;
}
/* 
 *offset:
 *  ==0-->不偏移  
 *  <0向前偏移        （不允许从文件头开始向前
 *  >0指定位置向后偏移  
 *cmd： 
 *		SEEK_SET（0）---> 文件的开头
 *		SEEK_CUR （1）--->文件的当前位置
 *		SEEK_END （2）--->文件的结尾位置
 * */
static loff_t char_lseek(struct file* file, loff_t offset, int cmd)
{
	loff_t ret = 0;
	global_dev* devp = file->private_data;
	switch(cmd)
	{
		case 0:
			if(offset <0)
			{
				printk(KERN_ERR"lseek offset error!\n");
				ret = -EINVAL;
				break;
			}
			if(offset > MAX_LEN)
			{
				offset = MAX_LEN ;
			}
			ret=file->f_pos=0;
			file->f_pos+=offset;		
			ret += offset;
			break;
		case 1:
			//控制偏移量不允许超出文件的开始处
			if((-offset) > file->f_pos)
			{
				offset = 0-(file->f_pos);
			}
			if(offset > MAX_LEN -file->f_pos)
			{
				offset = MAX_LEN -file->f_pos;
			}
			ret = file->f_pos+=offset;
		case 2:
			//控制文件向前偏移不允许超出文件开始处
			if((0-offset)> devp->cur_len)
			{
				offset = 0-file->f_pos;
			}
			//控制文件向后偏移不允许超出最大容量位置
			if(offset> MAX_LEN - file->f_pos)
			{
				offset = MAX_LEN - file->f_pos;
			}
			file->f_pos=devp->cur_len;
			ret = file->f_pos += offset;
			break;
		default:
			printk("lseek cmd error!\n");
			ret = -EINVAL;
			break;

	}
	printk("after llseek: %lld\n", file->f_pos);
	return ret;
}
//cmd:
// 0-->清空设备内的数据
static long char_ioctl(struct file* file, unsigned int cmd,  unsigned long arg)
{
	long ret = 0;
	global_dev* devp = file->private_data;
	printk(KERN_INFO"char_ioctl() invoked!\n");
	switch(cmd)
	{
		case CLR_ALL:
			memset(devp->data, 0, MAX_LEN);
			break;
		case CLR_BEGIN:
			memset(devp->data, 0, arg);
			devp->cur_len-=arg;
			memcpy(devp->data, devp->data+arg, devp->cur_len);
			//清空拷贝后的遗留数据
			memset(devp->data +devp->cur_len, 0, MAX_LEN-devp->cur_len);
			break;
		case CLR_END:
			memset(devp->data + devp->cur_len -arg, 0, arg);
			break;
		case DATA_GET:
			//memset(arg, 0, sizeof(arg));
			//将设备内的所有文件全部反馈给用户
			copy_to_user((void *)arg, devp->data, devp->cur_len);
			//数据操作完成后，设备内部的数据不保留
			memset (devp->data, 0, MAX_LEN);
			break;
		default:
			printk(KERN_ERR"ioctl cmd error!\n");
			ret = -EINVAL;
			break;

	}
			return ret;
}
static int char_open(struct inode* inode, struct file* file)
{

	file->private_data = global_devp;
	return 0;
}
static int char_close(struct inode* inode, struct file* file)
{
	printk(KERN_INFO"char_close() invoked\n");
	return 0;
}
//字符设备的文件操作方法的封装
static const struct file_operations fops={
	.owner   = THIS_MODULE, 
	.open    = char_open, 
	.release = char_close, 
	.read    = char_read,
	.write   = char_write,
	.llseek  = char_lseek,
	.unlocked_ioctl = char_ioctl, 
};

MODULE_LICENSE("Dual BSD/GPL");
static void char_setup(global_dev* devp, dev_t devno)
{
	cdev_init(&devp->cdev,&fops );
	if(cdev_add(&devp->cdev,devno, 1))
	{
		printk(KERN_ERR"cdev_add error!\n");
	}else
	{
		printk(KERN_INFO"cdev_add successful!\n");
	}
}
static int __init char_init(void)
{
	//1、分配设备编号
	int ret = 0;
	dev_t devno;
	devno=MKDEV(MAJOR_NUM, MINOR_NUM);

	ret = register_chrdev_region(devno, 1, DEV_NAME);
	if(ret <0)
	{
		printk("register_chrdev_region error!\n");
		ret=alloc_chrdev_region(&devno, 0, 1, DEV_NAME);
		if(ret < 0)
		{
			printk("alloc_chrdev_region error!\n");
			return -EBADF;
		}
	}
	major_num = MAJOR(devno);
	//2/给自定义设备的描述分配内存
	global_devp = (global_dev*)kmalloc(sizeof(global_dev), GFP_KERNEL);
	if(global_devp == NULL)
	{
		printk(KERN_ERR"kmalloc error!\n");
		return -ENOMEM;
	}
	printk(KERN_INFO"kmalloc successful!\n");
	memset(global_devp, 0, sizeof(global_dev));
	//初始化设备描述结构体
	char_setup(global_devp, devno);

	return 0;
}
static void __exit char_exit(void)
{
	cdev_del(&global_devp->cdev);
	kfree(global_devp);
	global_devp=NULL;
	unregister_chrdev_region(MKDEV(major_num, 0), 1);
	printk(KERN_INFO"char_exit successful!\n");
}



module_init(char_init);
module_exit(char_exit);
