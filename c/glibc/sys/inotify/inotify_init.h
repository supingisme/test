
#include <sys/inotify.h>

//初始化一个文件系统变更通知描述符
int inotify_init(void);
int inotify_init1(int flags);



SYSCALL_DEFINE1(inotify_init1, int, flags)
{
	return do_inotify_init(flags);
}

SYSCALL_DEFINE0(inotify_init)
{
	return do_inotify_init(0);
}


/* inotify syscalls */
static int do_inotify_init(int flags)
{
	struct fsnotify_group *group;
	int ret;

	/* Check the IN_* constants for consistency.  */
	BUILD_BUG_ON(IN_CLOEXEC != O_CLOEXEC);
	BUILD_BUG_ON(IN_NONBLOCK != O_NONBLOCK);

	if (flags & ~(IN_CLOEXEC | IN_NONBLOCK))
		return -EINVAL;

	/* fsnotify_obtain_group took a reference to group, we put this when we kill the file in the end */
	group = inotify_new_group(inotify_max_queued_events);
	if (IS_ERR(group))
		return PTR_ERR(group);

	ret = anon_inode_getfd("inotify", &inotify_fops, group,
				  O_RDONLY | flags);
	if (ret < 0)
		fsnotify_destroy_group(group);

	return ret;
}

