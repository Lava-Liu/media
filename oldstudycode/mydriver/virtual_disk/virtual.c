/* ==================================================================
 *       Filename:  virtual.c
 *    Description:  the  c of the job
 *        Created:  2013年10月24日 19时24分44秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/typeds.h>
#include <linux/cdev.h>
#include <linux/moduleparam.h>
#include "virtual.h"

static struct 
{
	struct cdev    cdev;
	struct class   *cls;
	struct device  *dev;
	int    data[MAX_LEN];
	int    cur_len;
	dev_t  g_devno;

}global_dev;
global_dev *devp = NULL;
static struct class *global_cls;
static int counter = 1;
static struct file_operations ops =
{
	.owner   =  THIS_MODULE, 
	.open    =  char_open, 
	.release =  char_close, 
}
static void set_cdev(global_dev *dev);
{
	cdev_init(&dev->cdev, &ops);
	cdev_add(&dev->cdev,DEV_NAME, 1 );

	dev->dev=device_create(dev->cls, 0, MKDEV())

}
static int __init vir_init(void)
{
	int i=0;
	int ret=0;
	dev_t devno;
	devno=MKDEV(MAJOR_NUM, MINOR_NUM);
	ret = register_chrdev_region(devno, counter, DEV_NAME);
	if(ret < 0)
	{
		printk(KERN_INFO"register_chrdev_region error!\n");
		ret = alloc_chrdev_region(&devno, 0, counter, DEV_NAME);
		if(ret < 0)
		{
			printk(KERN_INFO"alloc_chrdev_region error!\n");
			return -EFAULT;
		}
	}
	major_num=MINOR(devno);
	printk(KERN_INFO"majornum:%d\n", major_num);
	devp=(global_dev *)kmalloc(sizeof(global_dev)*counter , GFP_KERNEL);
	if(devp == NULL)
	{
		printk(KERN_INFO"kmalloc error!\n");
		goto err1;
	}
	memset(devp, 0, sizeof(global_dev)*counter);
	global_cls=class_create(THIS_MODULE, DEV_NAME);
	for(i=0;i<counter;i++)
	{
		devp[i].cls=global_cls;
		devp[i].g_devno=MKDEV(major_num, 0);
		set_cdev(&daevp[i]);
	}
	
	return 0;
err1:
	unregister_chrdev_region(devno, counter);
	return -EAGAIN;
}

static void __exit vir_exit(void)
{ 
	
	printk(KERN_INFO"vir_exit() invoked!\n");

}



MODULE_LICENSE("Dual BSD/GPL");
module_param(counter);
module_init(vir_init);
module_exit(vir_exit);
