#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

static int dummy_init(void)
{
	        printk("Hi, modul\n");
	        return 0;
}

static void dummy_exit(void)
{
	        printk("Bye, modul\n");
}

module_init(dummy_init);
module_exit(dummy_exit);
