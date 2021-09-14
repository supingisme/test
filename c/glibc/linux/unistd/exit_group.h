#include <linux/unistd.h>

void exit_group(int status);

//This  system call is equivalent to exit(2) except that it terminates not only the calling thread, but all
//threads in the calling process's thread group.

/*
 * this kills every thread in the thread group. Note that any externally
 * wait4()-ing process will get the correct exit code - even if this
 * thread is not the thread group leader.
 */
SYSCALL_DEFINE1(exit_group, int, error_code)
{
	do_group_exit((error_code & 0xff) << 8);
	/* NOTREACHED */
	return 0;
}

