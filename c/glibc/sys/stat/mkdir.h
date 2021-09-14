#include <sys/stat.h>

int mkdir(const char *path, mode_t mode);



SYSCALL_DEFINE2(mkdir, const char __user *, pathname, umode_t, mode)
{
	return do_mkdirat(AT_FDCWD, pathname, mode);
}

