/* ==================================================================
 *       Filename:  job2.c
 *    Description:  
 *        Created:  2013年10月17日 19时42分00秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

extern int myadd(int num1, int num2);
extern int mysub(int num1, int num2);
extern int mymulti(int num1, int num2);
extern int mydivi(int num1, int num2);
extern int number1;
extern int number2;
static int __init job2_init(void)
{
	printk(KERN_INFO"job2_init() invoked\n");
	printk(KERN_INFO"add: %d\n", myadd(number1, number2));
	printk(KERN_INFO"sub: %d\n", mysub(number1, number2));
	printk(KERN_INFO"multi: %d\n", mymulti(number1, number2));
	printk(KERN_INFO"divi: %d\n", mydivi(number1, number2));
	return 0;
}
static void __exit job2_exit(void)
{
	printk(KERN_INFO"job2_exit() invoked\n");

}

module_init(job2_init);
module_exit(job2_exit);



