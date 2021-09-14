
#include <unistd.h>

//link to a file
int link(const char *path1, const char *path2);


SYSCALL_DEFINE5(linkat, int, olddfd, const char __user *, oldname,
		int, newdfd, const char __user *, newname, int, flags)
{
	return do_linkat(olddfd, oldname, newdfd, newname, flags);
}

SYSCALL_DEFINE2(link, const char __user *, oldname, const char __user *, newname)
{
	return do_linkat(AT_FDCWD, oldname, AT_FDCWD, newname, 0);
}

