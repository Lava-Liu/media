/* ==================================================================
 *       Filename:  myinter.c
 *    Description:  
 *        Created:  2013年10月24日 16时40分46秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/moduleparam.h>
static unsigned int irq_num = 140;
static char* irq_name = "myinter";

//中断处理函数
irqreturn_t handler(unsigned int irq, void *dev_id, struct pt_regs* reg)
{
	printk(KERN_INFO"irq%d occurd!", irq_num);
	return IRQ_HANDLED;
}

static int __init inter_init(void)
{
	int ret = 0;
	//申请中断号
	ret = request_irq(irq_num, (void *)handler, IRQF_SHARED, irq_name, NULL);
	if(ret < 0)
	{
		printk(KERN_ERR"request_irq error!\n");
		return -EBUSY;
	}

	return 0;
}
static void __exit inter_exit(void)
{
	free_irq(irq_num, NULL);
	printk(KERN_INFO"inter_exit invoked~\n");
}




MODULE_LICENSE("Dual BSD/GPL");
module_param(irq_num, uint, 0644);
module_param(irq_name, charp, 0644);
module_init(inter_init);
module_exit(inter_exit);
