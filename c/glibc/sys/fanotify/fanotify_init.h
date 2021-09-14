#include <sys/fanotify.h>

//fanotify(fscking all notification and file access system)
//是一个notifier，对文件系统变化产生通知的机制。
extern int fanotify_init (unsigned int __flags, unsigned int __event_f_flags);


/* fanotify syscalls */
SYSCALL_DEFINE2(fanotify_init, unsigned int, flags, unsigned int, event_f_flags)
{
	struct fsnotify_group *group;
	int f_flags, fd;
	struct user_struct *user;
	struct fanotify_event *oevent;

	pr_debug("%s: flags=%x event_f_flags=%x\n",
		 __func__, flags, event_f_flags);

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

#ifdef CONFIG_AUDITSYSCALL
	if (flags & ~(FANOTIFY_INIT_FLAGS | FAN_ENABLE_AUDIT))
#else
	if (flags & ~FANOTIFY_INIT_FLAGS)
#endif
		return -EINVAL;

	if (event_f_flags & ~FANOTIFY_INIT_ALL_EVENT_F_BITS)
		return -EINVAL;

	switch (event_f_flags & O_ACCMODE) {
	case O_RDONLY:
	case O_RDWR:
	case O_WRONLY:
		break;
	default:
		return -EINVAL;
	}

	if ((flags & FAN_REPORT_FID) &&
	    (flags & FANOTIFY_CLASS_BITS) != FAN_CLASS_NOTIF)
		return -EINVAL;

	user = get_current_user();
	if (atomic_read(&user->fanotify_listeners) > FANOTIFY_DEFAULT_MAX_LISTENERS) {
		free_uid(user);
		return -EMFILE;
	}

	f_flags = O_RDWR | FMODE_NONOTIFY;
	if (flags & FAN_CLOEXEC)
		f_flags |= O_CLOEXEC;
	if (flags & FAN_NONBLOCK)
		f_flags |= O_NONBLOCK;

	/* fsnotify_alloc_group takes a ref.  Dropped in fanotify_release */
	group = fsnotify_alloc_group(&fanotify_fsnotify_ops);
	if (IS_ERR(group)) {
		free_uid(user);
		return PTR_ERR(group);
	}

	group->fanotify_data.user = user;
	group->fanotify_data.flags = flags;
	atomic_inc(&user->fanotify_listeners);
	group->memcg = get_mem_cgroup_from_mm(current->mm);

	oevent = fanotify_alloc_event(group, NULL, FS_Q_OVERFLOW, NULL,
				      FSNOTIFY_EVENT_NONE, NULL);
	if (unlikely(!oevent)) {
		fd = -ENOMEM;
		goto out_destroy_group;
	}
	group->overflow_event = &oevent->fse;

	if (force_o_largefile())
		event_f_flags |= O_LARGEFILE;
	group->fanotify_data.f_flags = event_f_flags;
	init_waitqueue_head(&group->fanotify_data.access_waitq);
	INIT_LIST_HEAD(&group->fanotify_data.access_list);
	switch (flags & FANOTIFY_CLASS_BITS) {
	case FAN_CLASS_NOTIF:
		group->priority = FS_PRIO_0;
		break;
	case FAN_CLASS_CONTENT:
		group->priority = FS_PRIO_1;
		break;
	case FAN_CLASS_PRE_CONTENT:
		group->priority = FS_PRIO_2;
		break;
	default:
		fd = -EINVAL;
		goto out_destroy_group;
	}

	if (flags & FAN_UNLIMITED_QUEUE) {
		fd = -EPERM;
		if (!capable(CAP_SYS_ADMIN))
			goto out_destroy_group;
		group->max_events = UINT_MAX;
	} else {
		group->max_events = FANOTIFY_DEFAULT_MAX_EVENTS;
	}

	if (flags & FAN_UNLIMITED_MARKS) {
		fd = -EPERM;
		if (!capable(CAP_SYS_ADMIN))
			goto out_destroy_group;
		group->fanotify_data.max_marks = UINT_MAX;
	} else {
		group->fanotify_data.max_marks = FANOTIFY_DEFAULT_MAX_MARKS;
	}

	if (flags & FAN_ENABLE_AUDIT) {
		fd = -EPERM;
		if (!capable(CAP_AUDIT_WRITE))
			goto out_destroy_group;
	}

	fd = anon_inode_getfd("[fanotify]", &fanotify_fops, group, f_flags);
	if (fd < 0)
		goto out_destroy_group;

	return fd;

out_destroy_group:
	fsnotify_destroy_group(group);
	return fd;
}

