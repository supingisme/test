#include <signal.h>

//return from signal handler and cleanup stack frame
int sigreturn(unsigned long __unused);


/*
 * Do a signal return; undo the signal stack.
 */
#ifdef CONFIG_X86_32
SYSCALL_DEFINE0(sigreturn)
{
	struct pt_regs *regs = current_pt_regs();
	struct sigframe __user *frame;
	sigset_t set;

	frame = (struct sigframe __user *)(regs->sp - 8);

	if (!access_ok(frame, sizeof(*frame)))
		goto badframe;
	if (__get_user(set.sig[0], &frame->sc.oldmask) || (_NSIG_WORDS > 1
		&& __copy_from_user(&set.sig[1], &frame->extramask,
				    sizeof(frame->extramask))))
		goto badframe;

	set_current_blocked(&set);

	/*
	 * x86_32 has no uc_flags bits relevant to restore_sigcontext.
	 * Save a few cycles by skipping the __get_user.
	 */
	if (restore_sigcontext(regs, &frame->sc, 0))
		goto badframe;
	return regs->ax;

badframe:
	signal_fault(regs, frame, "sigreturn");

	return 0;
}
#endif /* CONFIG_X86_32 */

