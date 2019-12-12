/* ==================================================================
 *       Filename:  bitset.c
 *    Description:  
 *        Created:  2013年10月17日 16时19分15秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <asm/bitops.h>

MODULE_LICENSE("Dual BSD/GPL");

static int __init bit_init(void)
{
	unsigned long value = 0;
	int ret =0;
	printk("bit_init() invoked!\n");
	set_bit(10, &value);
	printk("set_bit(10): %lu\n", value);
	ret = test_and_set_bit(5, &value);
	printk("1tasb(5): %lu, ret:%d\n", value, ret);

	ret = test_and_set_bit(5, &value);
	printk("2tasb(5): %lu, ret:%d\n", value, ret);

	clear_bit(5, &value);
	printk("clear_bit(5): %lu\n", value);
	change_bit(10, &value);
	printk("change_bit(10): %lu\n", value);
	return 0;
}
static void __exit bit_exit(void)
{
	printk("bit_exit() invoked!\n");
}

module_init(bit_init);
module_exit(bit_exit);

