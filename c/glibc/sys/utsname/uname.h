#include <sys/utsname.h>

//name - get the name of the current system
int uname(struct utsname *name);



SYSCALL_DEFINE1(newuname, struct new_utsname __user *, name)
{
	struct new_utsname tmp;

	down_read(&uts_sem);
	memcpy(&tmp, utsname(), sizeof(tmp));
	up_read(&uts_sem);
	if (copy_to_user(name, &tmp, sizeof(tmp)))
		return -EFAULT;

	if (override_release(name->release, sizeof(name->release)))
		return -EFAULT;
	if (override_architecture(name))
		return -EFAULT;
	return 0;
}

#ifdef __ARCH_WANT_SYS_OLD_UNAME
/*
 * Old cruft
 */
SYSCALL_DEFINE1(uname, struct old_utsname __user *, name)
{
	struct old_utsname tmp;

	if (!name)
		return -EFAULT;

	down_read(&uts_sem);
	memcpy(&tmp, utsname(), sizeof(tmp));
	up_read(&uts_sem);
	if (copy_to_user(name, &tmp, sizeof(tmp)))
		return -EFAULT;

	if (override_release(name->release, sizeof(name->release)))
		return -EFAULT;
	if (override_architecture(name))
		return -EFAULT;
	return 0;
}

SYSCALL_DEFINE1(olduname, struct oldold_utsname __user *, name)
{
	struct oldold_utsname tmp;

	if (!name)
		return -EFAULT;

	memset(&tmp, 0, sizeof(tmp));

	down_read(&uts_sem);
	memcpy(&tmp.sysname, &utsname()->sysname, __OLD_UTS_LEN);
	memcpy(&tmp.nodename, &utsname()->nodename, __OLD_UTS_LEN);
	memcpy(&tmp.release, &utsname()->release, __OLD_UTS_LEN);
	memcpy(&tmp.version, &utsname()->version, __OLD_UTS_LEN);
	memcpy(&tmp.machine, &utsname()->machine, __OLD_UTS_LEN);
	up_read(&uts_sem);
	if (copy_to_user(name, &tmp, sizeof(tmp)))
		return -EFAULT;

	if (override_architecture(name))
		return -EFAULT;
	if (override_release(name->release, sizeof(name->release)))
		return -EFAULT;
	return 0;
}
#endif

