
long sgetmask(void);

long ssetmask(long newmask);



#ifdef CONFIG_SGETMASK_SYSCALL

/*
 * For backwards compatibility.  Functionality superseded by sigprocmask.
 */
SYSCALL_DEFINE0(sgetmask)
{
	/* SMP safe */
	return current->blocked.sig[0];
}

SYSCALL_DEFINE1(ssetmask, int, newmask)
{
	int old = current->blocked.sig[0];
	sigset_t newset;

	siginitset(&newset, newmask);
	set_current_blocked(&newset);

	return old;
}
#endif /* CONFIG_SGETMASK_SYSCALL */

