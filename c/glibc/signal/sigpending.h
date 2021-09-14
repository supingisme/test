
#include <signal.h>

//examine pending signals
//检查待解决的信号
//返回在送往进程的时候被阻塞挂起的信号合计
int sigpending(sigset_t *set);



/**
 *  sys_sigpending - examine pending signals
 *  @uset: where mask of pending signal is returned
 */
SYSCALL_DEFINE1(sigpending, old_sigset_t __user *, uset)
{
	sigset_t set;

	if (sizeof(old_sigset_t) > sizeof(*uset))
		return -EINVAL;

	do_sigpending(&set);

	if (copy_to_user(uset, &set, sizeof(old_sigset_t)))
		return -EFAULT;

	return 0;
}
#ifdef CONFIG_COMPAT
COMPAT_SYSCALL_DEFINE1(sigpending, compat_old_sigset_t __user *, set32)
{
	sigset_t set;

	do_sigpending(&set);

	return put_user(set.sig[0], set32);
}
#endif


/**
 *  sys_rt_sigpending - examine a pending signal that has been raised
 *			while blocked
 *  @uset: stores pending signals
 *  @sigsetsize: size of sigset_t type or larger
 */
SYSCALL_DEFINE2(rt_sigpending, sigset_t __user *, uset, size_t, sigsetsize)
{
	sigset_t set;

	if (sigsetsize > sizeof(*uset))
		return -EINVAL;

	do_sigpending(&set);

	if (copy_to_user(uset, &set, sigsetsize))
		return -EFAULT;

	return 0;
}

