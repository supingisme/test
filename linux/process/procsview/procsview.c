#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init_task.h>

int init_test( void )
{
	struct task_struct *task = &init_task;
	do {
		if(task->__state == TASK_RUNNING)
		printk( KERN_INFO "***RTOAX %s [%d] parent %s\n",
				task->comm, task->pid, task->parent->comm
			  );
	} while ( (task = next_task(task)) != &init_task );
	return 0;
}
void cleanup_test(void )
{
	return;
}

module_init(init_test);
module_exit(cleanup_test);

MODULE_AUTHOR("Rong Tao");
MODULE_LICENSE("GPL");
