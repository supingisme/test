#include <unistd.h> /* glibc uses <sys/fsuid.h> */

//set group identity used for file system checks
int setfsgid(uid_t fsgid);


SYSCALL_DEFINE1(setfsgid, gid_t, gid)
{
	return __sys_setfsgid(gid);
}

