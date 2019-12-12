#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");
extern void myfunction(void);

static int __init export2_init(void)
{
	printk(KERN_INFO"export2_init() invoked!\n");
	printk(KERN_INFO"In export2:");
	myfunction();
	return 0;
}
static void __exit export2_exit(void)
{
	printk(KERN_INFO"export2_exit() invoked!\n");

}

module_init(export2_init);
module_exit(export2_exit);
