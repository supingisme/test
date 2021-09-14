#include <unistd.h>

//set/get process group
int setpgid(pid_t pid, pid_t pgid);
pid_t getpgid(pid_t pid);

pid_t getpgrp(void);                 /* POSIX.1 version */
pid_t getpgrp(pid_t pid);            /* BSD version */

int setpgrp(void);                   /* System V version */
int setpgrp(pid_t pid, pid_t pgid);  /* BSD version */



SYSCALL_DEFINE1(getpgid, pid_t, pid)
{
	return do_getpgid(pid);
}

#ifdef __ARCH_WANT_SYS_GETPGRP

SYSCALL_DEFINE0(getpgrp)
{
	return do_getpgid(0);
}

#endif


