/*
compile: gcc -c mybug.c -I/lib/modules/`uname -r`/build/include
insmod mybug.o
*/

#define __KERNEL__
#define MODULE
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/unistd.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

MODULE_AUTHOR("UNF/qobaiashi");
MODULE_LICENSE("GPL");

#define CALL_NR 35

extern void *sys_call_table[];

int (*old_call)(int, int);

/****************************\
|** overflow a slab object **|
\****************************/
int vuln(int addr)
{
	int *ptr = NULL;
	char *buffer = NULL;
	ptr = (int *)addr;
	buffer = kmalloc(120, GFP_KERNEL);
	if (buffer == NULL)
	{
		printk("[vuln] could not kmalloc(120)!\n");
		return 1;
	}
	printk("[
	vuln] got object at %p\n", buffer);
	if (copy_from_user(buffer, ptr,170) == 1)
	printk("[vuln] copy_from_user failed\n");
	kfree(buffer);
}
/**************************\
|** consume slab objects **|
\**************************/
int consume(int one)
{
	char *buffer = NULL;
	buffer = kmalloc(120, GFP_KERNEL);
	memset(buffer, 0x00, sizeof(buffer));
	if (buffer == NULL)
	{
		printk("[consume] could not kmalloc(120)!\n");
		return 1;
	}
	printk("[consume] got object at %p\n", buffer);
	printk("%s", buffer);
	if (one == 1)
	{
		kfree(buffer);
		printk("[consume] freed obj at %p\n", buffer);
	}
}
/**************************\
|** main call **|
\**************************/
int new_call(int one, int two)
{
	if (one == 1)
	{
		vuln(two);
		return 1;
	}
	if (one == 2)
	{
		consume(0);
		return 2;
	}
	if (one == 3)
	{
		consume(1);
		return 3;
	}
	return 0;
}
int init_module(void)
{
	printk("[*] vuln loaded!\n");
	old_call = sys_call_table[CALL_NR];
	sys_call_table[CALL_NR] = new_call;
	return 0;
}
void cleanup_module(void)
{
	sys_call_table[CALL_NR] = old_call;
	printk("[*] vuln unloaded!\n");
}
