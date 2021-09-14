//NAME
//setfsuid - set user identity used for file system checks
//
//SYNOPSIS
#include <unistd.h> /* glibc uses <sys/fsuid.h> */

int setfsuid(uid_t fsuid);


SYSCALL_DEFINE1(setfsuid, uid_t, uid)
{
	return __sys_setfsuid(uid);
}

