#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/timer.h>

#include <linux/kernel.h>

static void
time_handler(struct timer_list* data);

//struct timer_list stimer;
DEFINE_TIMER(stimer, time_handler);

static void 
time_handler(struct timer_list* data)
{
	mod_timer(&stimer, jiffies + HZ);
	printk("[RToax]current jiffies is %ld\n", jiffies);
}


static int __init timer_init(void)
{
	printk("[RToax]My module worked!\n");
#if 0
	init_timer(&stimer);
	stimer.data = 0;
	stimer.expires = jiffies + HZ;
	stimer.function = time_handler;
#endif
	add_timer(&stimer);
	return 0;
}

static void
__exit timer_exit(void)
{
	printk("[RToax]Unloading my module.\n");
	del_timer(&stimer);
	return;
}

module_init(timer_init);
module_exit(timer_exit);

MODULE_AUTHOR("fyf ReCode by [RToax]");
MODULE_LICENSE("GPL");

