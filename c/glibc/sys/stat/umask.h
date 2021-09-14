#include <sys/stat.h>

//umask - set and get the file mode creation mask
mode_t umask(mode_t cmask);


SYSCALL_DEFINE1(umask, int, mask)
{
	mask = xchg(&current->fs->umask, mask & S_IRWXUGO);
	return mask;
}

