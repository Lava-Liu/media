/* ==================================================================
 *       Filename:  virtual.c
 *    Description:  
 *        Created:  2013年10月23日 20时00分00秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/device.h>
#include "virtual.h"
typedef struct 
{
	struct   cdev cdev;
	struct   device *g_dev; 
	int      data[MAX_LEN];
	int      cur_len;
	dev_t    g_devno;


}global_dev;

global_dev *devp = NULL;

struct class *global_cls=NULL;

static struct file_operations ops=
{
	.owner=THIS_MODULE, 
};

void set_dev(global_dev *dev)
{
	cdev_init(&devp->cdev, &ops);
	cdev_add(&devp->cdev, devp->g_devno, 1);
	printk(KERN_INFO"cdev_add() success!\n");
}

static int __init virtual_init(void)
{
	int ret = 0;
	//创建设备号
	dev_t devno = MKDEV(MAJOR_NUM, MINOR_NUM);
	//手动注册设备号
	ret =register_chrdev_region(devno, 1, DEV_NAME);
	if(ret < 0)
	{
		printk(KERN_INFO"hand reg devno fail!\n");
		ret=alloc_chrdev_region(&devno, 0, 1, DEV_NAME);
		if(ret < 0)
		{
			printk(KERN_ERR"alloc devno fail!\n");
			goto err1;
		}
	}
	major_num = MAJOR(devno);
	printk(KERN_INFO"major_num:%d,minor_num: %d\n",major_num, MINOR(devno));
	//为自定义的结构体指针分配内存
	devp=(global_dev *)kmalloc(sizeof(global_dev), GFP_KERNEL);
	memset(devp, 0, sizeof(global_dev));
	devp->g_devno = devno;
	//激活设备
	set_dev(devp);
	//创建类属性
	global_cls=class_create(THIS_MODULE, DEV_NAME);
	if(global_cls==NULL)
	{
		return -ENOMEM;
	}
	//创建设备文件
	devp->g_dev=device_create(global_cls, NULL, devno, NULL, DEV_NAME"%d", 0);
	if(devp->g_dev == NULL)
	{
		return -EBUSY;
	}
	
	return 0;
err1:
	unregister_chrdev_region(MKDEV(major_num, 0), 1);
	return -EINVAL;
}

static void __exit virtual_exit(void)
{

	device_destroy(global_cls, 1);
	class_destroy(global_cls);
	cdev_del(&devp->cdev);
	kfree(devp);
	unregister_chrdev_region(MKDEV(major_num, 0), 1);
	printk(KERN_INFO"virtual_exit() invoked!\n");
}



MODULE_LICENSE("Dual BSD/GPL");
module_init(virtual_init);
module_exit(virtual_exit);
