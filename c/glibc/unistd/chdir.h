
#include <unistd.h>

//change working directory
int chdir(const char *path);

//fchdir()  is  identical  to  chdir();  the only difference is that 
//the directory is given as an open file descriptor.
int fchdir(int fd);



SYSCALL_DEFINE1(chdir, const char __user *, filename)
{
	return ksys_chdir(filename);
}

SYSCALL_DEFINE1(fchdir, unsigned int, fd)
{
	struct fd f = fdget_raw(fd);
	int error;

	error = -EBADF;
	if (!f.file)
		goto out;

	error = -ENOTDIR;
	if (!d_can_lookup(f.file->f_path.dentry))
		goto out_putf;

	error = inode_permission(file_inode(f.file), MAY_EXEC | MAY_CHDIR);
	if (!error)
		set_fs_pwd(current->fs, &f.file->f_path);
out_putf:
	fdput(f);
out:
	return error;
}

