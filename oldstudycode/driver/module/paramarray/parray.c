#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("Dual BSD/GPL");
int myarray[] = {1,2,3,4,5};
//static int len =sizeof(myarray)/sizeof(int);
static int len =0;
static int sum=0;
module_param_array(myarray,int,&len,0644);

static int __init pa_init(void)
{
	int i=0;
	printk(KERN_INFO"pa_init() invoked!\n");
	for(i;i<len;i++)
	{
		sum=sum+myarray[i];
	}

	return 0;
}
static void __exit pa_exit(void)
{
	printk("result: %d\n",sum);
	printk(KERN_INFO"pa_exit() invoked!\n");
}

module_init(pa_init);
module_exit(pa_exit);
