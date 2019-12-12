#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

void myfunction(void)
{
	printk(KERN_INFO"myfunciton() invoked!\n");
}
EXPORT_SYMBOL(myfunction);
static int __init export1_init(void)
{
	printk(KERN_INFO"export1_init() invoked!\n");
	printk(KERN_INFO"In export1");
	myfunction();
	return 0;
}
static void __exit export1_exit(void)
{
	printk(KERN_INFO"export1_exit() invoked!\n");

}

module_init(export1_init);
module_exit(export1_exit);
