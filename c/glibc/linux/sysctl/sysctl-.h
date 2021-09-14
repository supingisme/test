#include <unistd.h>
#include <linux/sysctl.h>

//sysctl - read/write system parameters
int _sysctl(struct __sysctl_args *args);
//Do not use this system call!  See NOTES.
//Glibc  does  not  provide  a wrapper for this system call; call it using syscall(2). 


SYSCALL_DEFINE1(sysctl, struct __sysctl_args __user *, args)
{
	struct __sysctl_args tmp;
	size_t oldlen = 0;
	ssize_t result;

	if (copy_from_user(&tmp, args, sizeof(tmp)))
		return -EFAULT;

	if (tmp.oldval && !tmp.oldlenp)
		return -EFAULT;

	if (tmp.oldlenp && get_user(oldlen, tmp.oldlenp))
		return -EFAULT;

	result = do_sysctl(tmp.name, tmp.nlen, tmp.oldval, oldlen,
			   tmp.newval, tmp.newlen);

	if (result >= 0) {
		oldlen = result;
		result = 0;
	}

	if (tmp.oldlenp && put_user(oldlen, tmp.oldlenp))
		return -EFAULT;

	return result;
}


#ifdef CONFIG_COMPAT

struct compat_sysctl_args {
	compat_uptr_t	name;
	int		nlen;
	compat_uptr_t	oldval;
	compat_uptr_t	oldlenp;
	compat_uptr_t	newval;
	compat_size_t	newlen;
	compat_ulong_t	__unused[4];
};

COMPAT_SYSCALL_DEFINE1(sysctl, struct compat_sysctl_args __user *, args)
{
	struct compat_sysctl_args tmp;
	compat_size_t __user *compat_oldlenp;
	size_t oldlen = 0;
	ssize_t result;

	if (copy_from_user(&tmp, args, sizeof(tmp)))
		return -EFAULT;

	if (tmp.oldval && !tmp.oldlenp)
		return -EFAULT;

	compat_oldlenp = compat_ptr(tmp.oldlenp);
	if (compat_oldlenp && get_user(oldlen, compat_oldlenp))
		return -EFAULT;

	result = do_sysctl(compat_ptr(tmp.name), tmp.nlen,
			   compat_ptr(tmp.oldval), oldlen,
			   compat_ptr(tmp.newval), tmp.newlen);

	if (result >= 0) {
		oldlen = result;
		result = 0;
	}

	if (compat_oldlenp && put_user(oldlen, compat_oldlenp))
		return -EFAULT;

	return result;
}

#endif /* CONFIG_COMPAT */

