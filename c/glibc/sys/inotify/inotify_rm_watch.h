
#include <sys/inotify.h>

//remove an existing watch from an inotify instance
int inotify_rm_watch(int fd, int wd);



SYSCALL_DEFINE2(inotify_rm_watch, int, fd, __s32, wd)
{
	struct fsnotify_group *group;
	struct inotify_inode_mark *i_mark;
	struct fd f;
	int ret = 0;

	f = fdget(fd);
	if (unlikely(!f.file))
		return -EBADF;

	/* verify that this is indeed an inotify instance */
	ret = -EINVAL;
	if (unlikely(f.file->f_op != &inotify_fops))
		goto out;

	group = f.file->private_data;

	ret = -EINVAL;
	i_mark = inotify_idr_find(group, wd);
	if (unlikely(!i_mark))
		goto out;

	ret = 0;

	fsnotify_destroy_mark(&i_mark->fsn_mark, group);

	/* match ref taken by inotify_idr_find */
	fsnotify_put_mark(&i_mark->fsn_mark);

out:
	fdput(f);
	return ret;
}

