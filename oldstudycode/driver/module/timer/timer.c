#include <linux/module.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/kernel.h>
//系统提供的时间记录1秒的频率变量HZ
#define H  HZ/1
MODULE_LICENSE("Dual BSD/GPL");

struct timer_list mytimer;

void myfun(unsigned long d)
{
	printk("%lu seconds left ...\n",d);
	if(d > 0)
	{
		mytimer.expires = jiffies + H;
		mytimer.function=myfun;
		mytimer.data = d-1;
	    add_timer(&mytimer);
	}
}

static int __init timer_init(void)
{
	printk(KERN_INFO"timer_init() invoked!\n");
	//对定时器结构体进行初始化
	init_timer(&mytimer);
	//手动设置定时器延时
	mytimer.expires = jiffies +H;//设置时限5秒
	//手动设置定时器调度唤醒方法
	mytimer.function = myfun;
	//唤醒方法的传参
	mytimer.data =10;
	//将定时器调度权交给内核，相当于启动定时器
	add_timer(&mytimer);
	return 0;
}
static void __exit timer_exit(void)
{
	//删除定时器
	del_timer(&mytimer);
	printk(KERN_INFO"timer_exit() invoked!\n");

}

module_init(timer_init);
module_exit(timer_exit);
