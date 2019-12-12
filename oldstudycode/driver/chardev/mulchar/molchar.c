/* ==================================================================
 *       Filename:  molchar.c
 *    Description:  
 *        Created:  2013年10月22日 14时49分04秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/moduleparam.h>
#define DEV_NAME "mulchar"
#define MAJOR_NUM 200
#define MINOR_NUM 0
#define MAX_LEN   0x1000

static int major    = MAJOR_NUM;
static int counter  = 2;

typedef struct global_dev 
{
	struct cdev   gd_cdev;
	struct class  *gd_cls;
	struct device *gd_dev;
	char          data[MAX_LEN];
	dev_t         gd_devno;
}global_dev;

struct class *global_cls = NULL;
global_dev* devp;

static const struct file_operations fops =
{
	.owner = THIS_MODULE, 
};

MODULE_LICENSE("Dual BSD/GPL");

static void chardev_setup(global_dev* dev)
{
	cdev_init(&dev->gd_cdev, &fops);
	if(cdev_add(&dev->gd_cdev, dev->gd_devno, 1))
	{
		printk("cdev_add error!\n");
	}else{
		printk("cdev_add successfuly!\n");
	}
	dev->gd_dev = device_create(dev->gd_cls, NULL, dev->gd_devno, NULL, DEV_NAME"%d", MINOR(dev->gd_devno));
}

static int __init mul_init(void)
{
	int ret = 0 ;
	int i=0;
	dev_t devno = MKDEV(MAJOR_NUM, MINOR_NUM);
	ret = register_chrdev_region(devno, counter, DEV_NAME);
	if(ret < 0)
	{
		ret = alloc_chrdev_region(&devno, 0, counter, DEV_NAME);
		if(ret < 0)
		{
			return -EBUSY;
		}
	}
	major=MAJOR(devno);
	printk("major: %d\n", major);
	//注册设备编号成功之后开始分配内存
	devp = (global_dev*)kmalloc(sizeof(global_dev)*counter, GFP_KERNEL);
	if(devp == NULL)
	{
		printk(KERN_ERR"kmalloc failed\n");
		goto err1;
	}else{
		printk("kmallc successfuly!\n");
	}
	memset(devp, 0, sizeof(global_dev)*counter);
	//创建设备的类别子系统
	global_cls = class_create(THIS_MODULE, DEV_NAME);
	//初始化字符设备以及创建设备文件
	for(i=0;i<counter;i++)
	{
		devp[i].gd_cls = global_cls;
		devp[i].gd_devno =MKDEV(major, i);
		chardev_setup(&devp[i]);
	}

	return 0;
err1:
	unregister_chrdev_region(devno, counter);
	return -1;
}

static void __exit mul_exit(void)
{
	int i=0;
	for(i=0;i<counter;i++)
	{
		device_destroy(devp[i].gd_cls, devp[i].gd_devno);
		cdev_del(&devp[i].gd_cdev);
	}
	class_destroy(global_cls);
	global_cls=NULL;
	kfree(devp);
	devp=NULL;
	unregister_chrdev_region(MKDEV(major, 0), counter);

}


module_param(counter, int, 0644);
module_init(mul_init);
module_exit(mul_exit);
