/* ==================================================================
 *       Filename:  myled.c
 *    Description:  
 *        Created:  2013年10月22日 16时31分54秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/moduleparam.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <asm/io.h>
#include "myled.h"
MODULE_LICENSE("Dual BSD/GPL");

typedef struct led_dev
{
	struct cdev cdev;
	unsigned int* ctrl_reg;//0x56000010
	unsigned int* data_reg;//0x56000014
	struct class *cls;
	struct device *dev;

}global_dev;
global_dev* devp = NULL;

static int led_open(struct inode* inode, struct file* file)
{
	//获取描述设备的结构体
	global_dev *dev = container_of(inode->i_cdev, struct led_dev, cdev);
	//数据私有化
	file->private_data = dev;
	if((file->f_flags & O_ACCMODE)==O_WRONLY)
	{
		file->f_pos = 0;
	}
	printk(KERN_INFO"open led successful!\n");
	return 0;
}

static int led_close(struct inode* inode , struct file* file )
{	
	printk(KERN_INFO"led_close() invoke!\n");
	return 0;
}
static void led_setup(unsigned long num, int p)
{
	unsigned int t = ioread32(devp->data_reg);
	if(p)
	{//LED light
		unsigned int v = ~(0x1 << (num + 4));
		t &= v;
	}else
	{//LED shadow
		unsigned int v = 0x1<< (num+4) ;
		t |=v;

	}
	iowrite32(t, devp->data_reg);
}
static int led_ioctl(struct inode* inode, struct file* file , unsigned int cmd, unsigned long arg)
{
	int ret = 0;
	switch(cmd)
	{
		case LED_ON:
			led_setup(arg, 1);
             break;
		default:
			led_setup(arg, 0);
			 break;
	}
	return ret;
}
static const struct file_operations fops =
{
	.owner = THIS_MODULE, 
	.open  = led_open, 
	.release = led_close, 
	.ioctl   = led_ioctl, 
};

static int __init led_init(void)
{
	int ret = 0;
	//临时保存控制寄存器的控制数据
	unsigned int out = 0;
	dev_t devno = MKDEV(major, 0);
	//获取LED设备的设备编号
	ret = register_chrdev_region(devno, 1, led_name);
	if(ret < 0)
	{
		printk(KERN_ERR"register_chrdev_region error!\n");
		ret = alloc_chrdev_region(&devno, 0, 1, led_name);
		if(ret < 0)
		{
			printk(KERN_ERR"alloc error !\n");
			return -EBUSY;
		}
	}
	printk(KERN_INFO"register success!\n");
	major = MAJOR(devno);
	//为设备分配内存
	devp = (global_dev *)kmalloc(sizeof(global_dev), GFP_KERNEL);

	if(devp == NULL)
	{
		printk(KERN_ERR"kmalloc error!\n");
		goto err1;
	}else{
		printk(KERN_INFO"kmalloc success!\n");
	}

	//3、建立控制寄存器和数据寄存器的映射
	devp->ctrl_reg = (unsigned int *)ioremap(0x56000010, 4);
	devp->data_reg = (unsigned int* )ioremap(0x56000014, 4);
	//4、设置led的控制位
	out |=(0x01 << 10) | (0x01 << 12) | (0x01 << 14) | (0x01 << 16);
	iowrite32(out, devp->ctrl_reg);
	//5、初始化具体设备在系统中的通用描述
	cdev_init(&devp->cdev, &fops);
	devp->cdev.owner = THIS_MODULE;
	devp->cdev.ops   = &fops;
	//6、将通用设备描述添加到内核管理列表
	if(cdev_add(&devp->cdev, devno, 1))
	{
		printk(KERN_ERR"cdev_add error!\n");
		goto err2;
	}else{
		printk(KERN_INFO"cdev_add success!\n");
	}
	//7.在sysfs中自动创建设备类别
	devp->cls=class_create(THIS_MODULE, led_name);
	if(devp->cls == NULL)
	{
		printk(KERN_ERR"class_create error!\n");
		goto warn;
	}
	//8、在sysfs中自动创建设备个体并创建设备文件
	devp->dev = device_create(devp->cls, NULL, devno, NULL, "%s%d", led_name, MINOR(devno));
	if(NULL == devp->dev)
	{
		printk(KERN_ERR"device_create errpr!\n");
	}else{
		printk(KERN_INFO"auto create  success!\n");
	}
	return 0;
warn:
	return 0;
err2:
	iounmap(devp->ctrl_reg);
	iounmap(devp->data_reg);
	kfree(devp);
	devp = NULL;
err1:
	unregister_chrdev_region(devno, 1);
	return -ENOMEM;
}
static void __exit led_exit(void)
{
	device_destroy(devp->cls,MKDEV(major, 0) );
	class_destroy(devp->cls);
	cdev_del(&devp->cdev);
	iounmap(devp->ctrl_reg);
	iounmap(devp->data_reg);
	kfree(devp);
	devp = NULL;
	unregister_chrdev_region(MKDEV(major, 0), 1);
	
	printk("led_exit() invoked!\n");
}

module_param(counter, int , 0644);
module_param(led_name, charp, 0644);
module_param(major, int, 0644);
module_init(led_init);
module_exit(led_exit);
