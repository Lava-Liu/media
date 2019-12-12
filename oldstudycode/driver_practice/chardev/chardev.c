/* ==================================================================
 *       Filename:  chardev.c
 *    Description:  
 *        Created:  2013年10月21日 19时10分38秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
//struct cdev cdev_init 
#include <linux/cdev.h>
//file_operations
#include <linux/fs.h>
#include <linux/types.h>
//kmalloc kfree
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include "chardev.h"
//兼容标准申明
MODULE_LICENSE("Dual BSD/GPL");
typedef struct 
{
	struct cdev cdev;
	struct class *gd_cls;
	struct device *gd_dev;
	int    data[MAX_LEN];
	int    cur_len;
}global_dev;
global_dev *global_devp=NULL;
static int major_num = 0;
struct class *global_cls =NULL;

static int char_open(struct inode* inode, struct file* file)
{
    global_dev *dev = container_of(inode->i_cdev,global_dev,cdev);
	file->private_data=dev;
	printk("open() invoked!\n");
	return 0;
}
static int char_release(struct inode *inode, struct file *file)
{
	printk("release() invoked\n");
	return 0;
}
struct file_operations ops=
{
	.owner     = THIS_MODULE, 
    .open      = char_open,
	.release   = char_release,
	
		
};
void cdev_set(global_dev *devp, dev_t devno)
{
	cdev_init(&devp->cdev,&ops );
	cdev_add(&devp->cdev, devno, 1);

}
static int  reg_dev(void )
{
	long ret = 0;
	dev_t devno = MKDEV(MAJOR_NUM,MINOR_NUM);
	ret = register_chrdev_region(devno,1, DEV_NAME);
	if(ret < 0)
	{
		ret = alloc_chrdev_region(&devno,0, 1,DEV_NAME);
		if(ret < 0)
		{
			printk(KERN_ERR"can not get the devno!\n");
			return -EAGAIN;
		}
	}
	major_num=MINOR(devno);
	return devno;
}
//模块初始化注册
static int __init chardev_init(void)
{
	dev_t devno;
	devno=reg_dev();
	global_devp=(global_dev *)kmalloc(sizeof(global_dev), GFP_KERNEL);
	memset(global_devp, 0, sizeof(global_dev));
	cdev_set(global_devp, devno);
	printk(KERN_INFO"chardev_init() invoked!\n");
	global_cls=class_create(THIS_MODULE, DEV_NAME);
	global_devp->gd_dev=device_create(global_cls, NULL,devno, NULL, DEV_NAME"%d", 1);
	return 0;
}


//模块卸载
static void __exit chardev_exit(void)
{
	device_destroy(global_cls,MKDEV(major_num, 0));
	class_destroy(global_cls);
	kfree(global_devp);
	cdev_del(&global_devp->cdev);
	unregister_chrdev_region(MKDEV(major_num, 0), 1);
	printk(KERN_INFO"chardev_exit() invoked!\n");
}



//调用注册和卸载函数
module_init(chardev_init);
module_exit(chardev_exit);
