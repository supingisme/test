/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */


//truncate a file to a specified length
//文件描述符指定的文件大小改为length，fd必须是以写入模式打开的文件，
//如果大于length，则删除
//
#include <unistd.h>
#include <sys/types.h>


int truncate(const char *path, off_t length);

//文件描述符指定的文件大小改为length，fd必须是以写入模式打开的文件，
int ftruncate(int fd, off_t length);


long do_sys_ftruncate(unsigned int fd, loff_t length, int small)
{
	struct inode *inode;
	struct dentry *dentry;
	struct fd f;
	int error;

	error = -EINVAL;
	if (length < 0)
		goto out;
	error = -EBADF;
	f = fdget(fd);
	if (!f.file)
		goto out;

	/* explicitly opened as large or we are on 64-bit box */
	if (f.file->f_flags & O_LARGEFILE)
		small = 0;

	dentry = f.file->f_path.dentry;
	inode = dentry->d_inode;
	error = -EINVAL;
	if (!S_ISREG(inode->i_mode) || !(f.file->f_mode & FMODE_WRITE))
		goto out_putf;

	error = -EINVAL;
	/* Cannot ftruncate over 2^31 bytes without large file support */
	if (small && length > MAX_NON_LFS)
		goto out_putf;

	error = -EPERM;
	/* Check IS_APPEND on real upper inode */
	if (IS_APPEND(file_inode(f.file)))
		goto out_putf;

	sb_start_write(inode->i_sb);
	error = locks_verify_truncate(inode, f.file, length);
	if (!error)
		error = security_path_truncate(&f.file->f_path);
	if (!error)
		error = do_truncate(dentry, length, ATTR_MTIME|ATTR_CTIME, f.file);
	sb_end_write(inode->i_sb);
out_putf:
	fdput(f);
out:
	return error;
}

SYSCALL_DEFINE2(ftruncate, unsigned int, fd, unsigned long, length)
{
	return do_sys_ftruncate(fd, length, 1);
}

#ifdef CONFIG_COMPAT
COMPAT_SYSCALL_DEFINE2(ftruncate, unsigned int, fd, compat_ulong_t, length)
{
	return do_sys_ftruncate(fd, length, 1);
}
#endif

