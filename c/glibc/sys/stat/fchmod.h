#include <sys/stat.h>

//chmod, fchmod - change permissions of a file
int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);


int ksys_fchmod(unsigned int fd, umode_t mode)
{
	struct fd f = fdget(fd);
	int err = -EBADF;

	if (f.file) {
		audit_file(f.file);
		err = chmod_common(&f.file->f_path, mode);
		fdput(f);
	}
	return err;
}

SYSCALL_DEFINE2(fchmod, unsigned int, fd, umode_t, mode)
{
	return ksys_fchmod(fd, mode);
}

