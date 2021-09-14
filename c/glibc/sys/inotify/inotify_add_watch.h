
#include <sys/inotify.h>

//inotify_add_watch - add a watch to an initialized inotify instance
int inotify_add_watch(int fd, const char *pathname, uint32_t mask);
//On success, inotify_add_watch() returns a nonnegative watch descriptor.  On  error  -1  is  returned  and
//       errno is set appropriately.



SYSCALL_DEFINE3(inotify_add_watch, int, fd, const char __user *, pathname,
		u32, mask)
{
	struct fsnotify_group *group;
	struct inode *inode;
	struct path path;
	struct fd f;
	int ret;
	unsigned flags = 0;

	/*
	 * We share a lot of code with fs/dnotify.  We also share
	 * the bit layout between inotify's IN_* and the fsnotify
	 * FS_*.  This check ensures that only the inotify IN_*
	 * bits get passed in and set in watches/events.
	 */
	if (unlikely(mask & ~ALL_INOTIFY_BITS))
		return -EINVAL;
	/*
	 * Require at least one valid bit set in the mask.
	 * Without _something_ set, we would have no events to
	 * watch for.
	 */
	if (unlikely(!(mask & ALL_INOTIFY_BITS)))
		return -EINVAL;

	f = fdget(fd);
	if (unlikely(!f.file))
		return -EBADF;

	/* IN_MASK_ADD and IN_MASK_CREATE don't make sense together */
	if (unlikely((mask & IN_MASK_ADD) && (mask & IN_MASK_CREATE))) {
		ret = -EINVAL;
		goto fput_and_out;
	}

	/* verify that this is indeed an inotify instance */
	if (unlikely(f.file->f_op != &inotify_fops)) {
		ret = -EINVAL;
		goto fput_and_out;
	}

	if (!(mask & IN_DONT_FOLLOW))
		flags |= LOOKUP_FOLLOW;
	if (mask & IN_ONLYDIR)
		flags |= LOOKUP_DIRECTORY;

	ret = inotify_find_inode(pathname, &path, flags,
			(mask & IN_ALL_EVENTS));
	if (ret)
		goto fput_and_out;

	/* inode held in place by reference to path; group by fget on fd */
	inode = path.dentry->d_inode;
	group = f.file->private_data;

	/* create/update an inode mark */
	ret = inotify_update_watch(group, inode, mask);
	path_put(&path);
fput_and_out:
	fdput(f);
	return ret;
}

