#include <unistd.h>

//get/set hostname
int gethostname(char *name, size_t len);


#ifdef __ARCH_WANT_SYS_GETHOSTNAME

SYSCALL_DEFINE2(gethostname, char __user *, name, int, len)
{
	int i;
	struct new_utsname *u;
	char tmp[__NEW_UTS_LEN + 1];

	if (len < 0)
		return -EINVAL;
	down_read(&uts_sem);
	u = utsname();
	i = 1 + strlen(u->nodename);
	if (i > len)
		i = len;
	memcpy(tmp, u->nodename, i);
	up_read(&uts_sem);
	if (copy_to_user(name, tmp, i))
		return -EFAULT;
	return 0;
}

#endif


