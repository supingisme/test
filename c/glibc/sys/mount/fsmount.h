


/*
 * Create a kernel mount representation for a new, prepared superblock
 * (specified by fs_fd) and attach to an open_tree-like file descriptor.
 */
SYSCALL_DEFINE3(fsmount, int, fs_fd, unsigned int, flags,
		unsigned int, attr_flags)
{
	struct mnt_namespace *ns;
	struct fs_context *fc;
	struct file *file;
	struct path newmount;
	struct mount *mnt;
	struct fd f;
	unsigned int mnt_flags = 0;
	long ret;

	if (!may_mount())
		return -EPERM;

	if ((flags & ~(FSMOUNT_CLOEXEC)) != 0)
		return -EINVAL;

	if (attr_flags & ~(MOUNT_ATTR_RDONLY |
			   MOUNT_ATTR_NOSUID |
			   MOUNT_ATTR_NODEV |
			   MOUNT_ATTR_NOEXEC |
			   MOUNT_ATTR__ATIME |
			   MOUNT_ATTR_NODIRATIME))
		return -EINVAL;

	if (attr_flags & MOUNT_ATTR_RDONLY)
		mnt_flags |= MNT_READONLY;
	if (attr_flags & MOUNT_ATTR_NOSUID)
		mnt_flags |= MNT_NOSUID;
	if (attr_flags & MOUNT_ATTR_NODEV)
		mnt_flags |= MNT_NODEV;
	if (attr_flags & MOUNT_ATTR_NOEXEC)
		mnt_flags |= MNT_NOEXEC;
	if (attr_flags & MOUNT_ATTR_NODIRATIME)
		mnt_flags |= MNT_NODIRATIME;

	switch (attr_flags & MOUNT_ATTR__ATIME) {
	case MOUNT_ATTR_STRICTATIME:
		break;
	case MOUNT_ATTR_NOATIME:
		mnt_flags |= MNT_NOATIME;
		break;
	case MOUNT_ATTR_RELATIME:
		mnt_flags |= MNT_RELATIME;
		break;
	default:
		return -EINVAL;
	}

	f = fdget(fs_fd);
	if (!f.file)
		return -EBADF;

	ret = -EINVAL;
	if (f.file->f_op != &fscontext_fops)
		goto err_fsfd;

	fc = f.file->private_data;

	ret = mutex_lock_interruptible(&fc->uapi_mutex);
	if (ret < 0)
		goto err_fsfd;

	/* There must be a valid superblock or we can't mount it */
	ret = -EINVAL;
	if (!fc->root)
		goto err_unlock;

	ret = -EPERM;
	if (mount_too_revealing(fc->root->d_sb, &mnt_flags)) {
		pr_warn("VFS: Mount too revealing\n");
		goto err_unlock;
	}

	ret = -EBUSY;
	if (fc->phase != FS_CONTEXT_AWAITING_MOUNT)
		goto err_unlock;

	ret = -EPERM;
	if ((fc->sb_flags & SB_MANDLOCK) && !may_mandlock())
		goto err_unlock;

	newmount.mnt = vfs_create_mount(fc);
	if (IS_ERR(newmount.mnt)) {
		ret = PTR_ERR(newmount.mnt);
		goto err_unlock;
	}
	newmount.dentry = dget(fc->root);
	newmount.mnt->mnt_flags = mnt_flags;

	/* We've done the mount bit - now move the file context into more or
	 * less the same state as if we'd done an fspick().  We don't want to
	 * do any memory allocation or anything like that at this point as we
	 * don't want to have to handle any errors incurred.
	 */
	vfs_clean_context(fc);

	ns = alloc_mnt_ns(current->nsproxy->mnt_ns->user_ns, true);
	if (IS_ERR(ns)) {
		ret = PTR_ERR(ns);
		goto err_path;
	}
	mnt = real_mount(newmount.mnt);
	mnt->mnt_ns = ns;
	ns->root = mnt;
	ns->mounts = 1;
	list_add(&mnt->mnt_list, &ns->list);
	mntget(newmount.mnt);

	/* Attach to an apparent O_PATH fd with a note that we need to unmount
	 * it, not just simply put it.
	 */
	file = dentry_open(&newmount, O_PATH, fc->cred);
	if (IS_ERR(file)) {
		dissolve_on_fput(newmount.mnt);
		ret = PTR_ERR(file);
		goto err_path;
	}
	file->f_mode |= FMODE_NEED_UNMOUNT;

	ret = get_unused_fd_flags((flags & FSMOUNT_CLOEXEC) ? O_CLOEXEC : 0);
	if (ret >= 0)
		fd_install(ret, file);
	else
		fput(file);

err_path:
	path_put(&newmount);
err_unlock:
	mutex_unlock(&fc->uapi_mutex);
err_fsfd:
	fdput(f);
	return ret;
}

