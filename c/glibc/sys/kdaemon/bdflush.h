#include <sys/kdaemon.h>

//bdflush - start, flush, or tune buffer-dirty-flush daemon
//Since Linux 2.6, this system call is deprecated and does nothing. ***啥也不干
int bdflush(int func, long *address);
int bdflush(int func, long data);

//see also:
//    fsync(2), sync(2), sync(8), update(8);



/*
 * There are no bdflush tunables left.  But distributions are
 * still running obsolete flush daemons, so we terminate them here.
 *
 * Use of bdflush() is deprecated and will be removed in a future kernel.
 * The `flush-X' kernel threads fully replace bdflush daemons and this call.
 */
SYSCALL_DEFINE2(bdflush, int, func, long, data)
{
	static int msg_count;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	if (msg_count < 5) {
		msg_count++;
		printk(KERN_INFO
			"warning: process `%s' used the obsolete bdflush"
			" system call\n", current->comm);
		printk(KERN_INFO "Fix your initscripts?\n");
	}

	if (func == 1)
		do_exit(0);
	return 0;
}

