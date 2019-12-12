/* ==================================================================
 *       Filename:  register.c
 *    Description:  
 *        Created:  2013年10月17日 16时58分07秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
//register_chrdev_region
//alloc_chrdev_region
//unregister_chrdev_region
#include <linux/types.h>
#define DEV_NAME "chardev"
#define MAJOR_NUM 5
#define MINOR_NUM 0
MODULE_LICENSE("Dual BSD/GPL");
//保存主设备号
static int major_num=0;

static int __init res_init(void)
{
	int ret = 0;
	//1.手动制作设备编号
	dev_t devno;
	//利用系统的宏生成一个设备编号
	devno=MKDEV(MAJOR_NUM, MINOR_NUM);
	//第一个参数：自定义的设备编号
	//第二个参数，注册是被编号的数量
	//次设备编号的分配默认从0开始累加
	//第三个参数：自定义的设备名字
	//返回值：
	//fail：return -1
	//ok return 0
	ret=register_chrdev_region(devno,1, DEV_NAME);
	if(ret < 0)
	{
		printk("register_chrdev_region error\n");
		ret=alloc_chrdev_region(&devno,0, 1, DEV_NAME);
		if(ret < 0)
		{
			printk("alloc_chrdev_region error!\n");
			goto err1;
		}
	}
	major_num = MAJOR(devno);
	printk("Major: %d, Minor:%d\n", major_num, MINOR(devno));
	return 0;
err1:
	return -1;
}
static void __exit res_exit(void)
{
	//第一个参数：设备号
	//第二个参数：此类设备号的数量：
	unregister_chrdev_region(MKDEV(major_num, 0), 1);
	printk("res_exit() invoked!\n");
}
module_init(res_init);
module_exit(res_exit);
