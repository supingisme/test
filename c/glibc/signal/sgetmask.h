

//sgetmask, ssetmask - manipulation of signal mask (obsolete)
long sgetmask(void);

//sgetmask, ssetmask - manipulation of signal mask (obsolete)
//long ssetmask(long newmask);



#ifdef CONFIG_SGETMASK_SYSCALL

/*
 * For backwards compatibility.  Functionality superseded by sigprocmask.
 */
SYSCALL_DEFINE0(sgetmask)
{
	/* SMP safe */
	return current->blocked.sig[0];
}

#endif /* CONFIG_SGETMASK_SYSCALL */


