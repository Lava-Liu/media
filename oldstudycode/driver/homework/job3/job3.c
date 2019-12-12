/* ==================================================================
 *       Filename:  job3.c
 *    Description:  
 *        Created:  2013年10月17日 19时50分11秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>


MODULE_LICENSE("Dual BSD/GPL");

int number1;
int number2;

module_param(number1,int, 0644);
module_param(number2,int, 0644);
EXPORT_SYMBOL(number1);
EXPORT_SYMBOL(number2);

static int __init job3_init(void)
{
	printk(KERN_INFO"job3_init() invoked\n");
	printk(KERN_INFO"we get the number:%d %d\n", number1, number2);
	return 0;
}
static void __exit job3_exit(void)
{
	printk(KERN_INFO"job3_exit() invoked\n");
}


module_init(job3_init);
module_exit(job3_exit);

