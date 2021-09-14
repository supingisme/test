#include <sys/vm86.h>

//vm86old, vm86 - enter virtual 8086 mode
int vm86old(struct vm86_struct *info);

int vm86(unsigned long fn, struct vm86plus_struct *v86);




SYSCALL_DEFINE1(vm86old, struct vm86_struct __user *, user_vm86)
{
	return do_sys_vm86((struct vm86plus_struct __user *) user_vm86, false);
}


SYSCALL_DEFINE2(vm86, unsigned long, cmd, unsigned long, arg)
{
	switch (cmd) {
	case VM86_REQUEST_IRQ:
	case VM86_FREE_IRQ:
	case VM86_GET_IRQ_BITS:
	case VM86_GET_AND_RESET_IRQ:
		return do_vm86_irq_handling(cmd, (int)arg);
	case VM86_PLUS_INSTALL_CHECK:
		/*
		 * NOTE: on old vm86 stuff this will return the error
		 *  from access_ok(), because the subfunction is
		 *  interpreted as (invalid) address to vm86_struct.
		 *  So the installation check works.
		 */
		return 0;
	}

	/* we come here only for functions VM86_ENTER, VM86_ENTER_NO_BYPASS */
	return do_sys_vm86((struct vm86plus_struct __user *) arg, true);
}

