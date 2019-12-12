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
	//kmalloc/kfree
#define MAJOR_NUM 200
#define MINOR_NUM 0
#define DEV_NAME "chardev"
#define MAX_LEN  0x1000 //4kb
#include <asm/atomic.h>
#include <linux/spinlock.h>
#include <linux/delay.h>
   //ssleep
static int major_num = 0;

typedef struct
{
	struct cdev cdev;
	char data[MAX_LEN];
	atomic_t count;
	spinlock_t splock;
	//unsigned char   *data;
	

}global_dev;
global_dev* devp = NULL;

static int char_open(struct inode* inode, struct file* file)
{

	spin_lock(&devp->splock);
	if( atomic_read(&devp->count) <= 0)
	{
		return -EBUSY;
	}
	ssleep(10);
	atomic_dec(&devp->count);
	spin_unlock(&devp->splock);
	return 0;
}
static int char_close(struct inode* inode, struct file* file)
{
	printk(KERN_INFO"char_close() invoked\n");
	spin_lock(&devp->splock);
	if(atomic_read(&devp->count) > 2)
	{
		return -1;
	}
	atomic_inc(&devp->count);
	spin_unlock(&devp->splock);
	return 0;
}
//字符设备的文件操作方法的封装
static const struct file_operations fops={
	.owner   = THIS_MODULE, 
	.open    = char_open, 
	.release = char_close, 
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
	devp = (global_dev*)kmalloc(sizeof(global_dev), GFP_KERNEL);
	if(devp == NULL)
	{
		printk(KERN_ERR"kmalloc error!\n");
		return -ENOMEM;
	}
	printk(KERN_INFO"kmalloc successful!\n");

	//初始化设备描述结构体
	char_setup(devp, devno);

	//初始化自动变量
	atomic_set(&devp->count, 2);

	//初始化自旋锁
	spin_lock_init(&devp->splock);
	return 0;
}
static void __exit char_exit(void)
{
	cdev_del(&devp->cdev);
	kfree(devp);
	devp=NULL;
	unregister_chrdev_region(MKDEV(major_num, 0), 1);
	printk(KERN_INFO"char_exit successful!\n");
}



module_init(char_init);
module_exit(char_exit);
