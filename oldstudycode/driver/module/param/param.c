#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
MODULE_LICENSE("Dual BSD/GPL");
int mynumber = 100;
char *myname = "emsd1304";
//将变量符号从模块内部导出
//赋予内核管理
module_param(mynumber,int,0644);
module_param(myname,charp,0644);

static int __init param_init(void)
{

	int i;
	printk("param_init() incoked!\n");
	i=9;
	printk("%d\n",i);
	printk("number:%d\n",mynumber);
	printk("name:%s\n",myname);
	return 0;
}
static void __exit param_exit(void)
{
	printk("param_exit() incoked!\n");
}


module_init(param_init);
module_exit(param_exit);
