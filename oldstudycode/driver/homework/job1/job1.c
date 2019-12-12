/* ==================================================================
 *       Filename:  job1.c
 *    Description:  
 *        Created:  2013年10月17日 19时13分52秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/

#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual DSP/GPL");
int myadd(int num1, int num2)
{
	printk("add success!\n");
	return num1+num2;
}
int mysub(int num1, int num2)
{
	printk("sub success!\n");
	return num1-num2;
}
int mymulti(int num1, int num2)
{
	printk("multi success!\n");
	return num1*num2;
}
int mydivi(int num1, int num2)
{
	printk("divi success!\n");
	return num1/num2;
}
EXPORT_SYMBOL(myadd);
EXPORT_SYMBOL(mysub);
EXPORT_SYMBOL(mymulti);
EXPORT_SYMBOL(mydivi);
static int __init job1_init(void)
{
	printk(KERN_INFO"job1_init() invoked!\n");

	return 0;
}
static void __exit job1_exit(void)
{
	printk(KERN_INFO"job1_exit() invoked!\n");

}
module_init(job1_init);
module_exit(job1_exit);
