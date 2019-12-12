#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");
//对设备进行相关的初始化工作
static int __init hello_init(void)
{
	printk("hello_init() incoked!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk("hello_exit) incoked!\n");
}

module_init(hello_init);
module_exit(hello_exit);

