#include <sched.h>

//disassociate parts of the process execution context
//分离进程的一部分执行上下文
int unshare(int flags);


//unshare():
//  Since glibc 2.14:
//      _GNU_SOURCE
//  Before glibc 2.14:
//      _BSD_SOURCE || _SVID_SOURCE
//          /* _GNU_SOURCE also suffices */
SYSCALL_DEFINE1(unshare, unsigned long, unshare_flags)
{
	return ksys_unshare(unshare_flags);
}

