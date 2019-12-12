#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

static int __init info_init(void)
{
	printk("info_init() incoked!\n");
	return 0;
}
static void __exit info_exit(void)
{
	printk("info_init() incoked!\n");
}
module_init(info_init);
module_exit(info_exit);

MODULE_AUTHOR("liuwei");
MODULE_ALIAS("Informations");
MODULE_DESCRIPTION("This is a test module for info");
MODULE_VERSION("2013.10.16.1");
MODULE_INFO(Serviece,"None");

