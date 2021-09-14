#include <sys/mount.h>

//umount, umount2 - unmount file system
int umount(const char *target);

int umount2(const char *target, int flags);



SYSCALL_DEFINE2(umount, char __user *, name, int, flags)
{
	return ksys_umount(name, flags);
}

#ifdef __ARCH_WANT_SYS_OLDUMOUNT

/*
 *	The 2.0 compatible umount. No flags.
 */
SYSCALL_DEFINE1(oldumount, char __user *, name)
{
	return ksys_umount(name, 0);
}

#endif


/*
 * Now umount can handle mount points as well as block devices.
 * This is important for filesystems which use unnamed block devices.
 *
 * We now support a flag for forced unmount like the other 'big iron'
 * unixes. Our API is identical to OSF/1 to avoid making a mess of AMD
 */

int ksys_umount(char __user *name, int flags)
{
	struct path path;
	struct mount *mnt;
	int retval;
	int lookup_flags = 0;

	if (flags & ~(MNT_FORCE | MNT_DETACH | MNT_EXPIRE | UMOUNT_NOFOLLOW))
		return -EINVAL;

	if (!may_mount())
		return -EPERM;

	if (!(flags & UMOUNT_NOFOLLOW))
		lookup_flags |= LOOKUP_FOLLOW;

	retval = user_path_mountpoint_at(AT_FDCWD, name, lookup_flags, &path);
	if (retval)
		goto out;
	mnt = real_mount(path.mnt);
	retval = -EINVAL;
	if (path.dentry != path.mnt->mnt_root)
		goto dput_and_out;
	if (!check_mnt(mnt))
		goto dput_and_out;
	if (mnt->mnt.mnt_flags & MNT_LOCKED) /* Check optimistically */
		goto dput_and_out;
	retval = -EPERM;
	if (flags & MNT_FORCE && !capable(CAP_SYS_ADMIN))
		goto dput_and_out;

	retval = do_umount(mnt, flags);
dput_and_out:
	/* we mustn't call path_put() as that would clear mnt_expiry_mark */
	dput(path.dentry);
	mntput_no_expire(mnt);
out:
	return retval;
}

