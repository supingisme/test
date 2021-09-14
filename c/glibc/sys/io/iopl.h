
#include <sys/io.h>

//change I/O privilege level
/* Set the I/O privilege level to LEVEL.  If LEVEL>3, permission to
   access any I/O port is granted.  This call requires root
   privileges. */
/**
 *	获取对 整个 IO 端口 操作权限
 */
int iopl(int level);




/*
 * The sys_iopl functionality depends on the level argument, which if
 * granted for the task is used to enable access to all 65536 I/O ports.
 *
 * This does not use the IOPL mechanism provided by the CPU as that would
 * also allow the user space task to use the CLI/STI instructions.
 *
 * Disabling interrupts in a user space task is dangerous as it might lock
 * up the machine and the semantics vs. syscalls and exceptions is
 * undefined.
 *
 * Setting IOPL to level 0-2 is disabling I/O permissions. Level 3
 * 3 enables them.
 *
 * IOPL is strictly per thread and inherited on fork.
 */
SYSCALL_DEFINE1(iopl, unsigned int, level)
{
	struct thread_struct *t = &current->thread;
	unsigned int old;

	if (level > 3)
		return -EINVAL;

	old = t->iopl_emul;

	/* No point in going further if nothing changes */
	if (level == old)
		return 0;

	/* Trying to gain more privileges? */
	if (level > old) {
		if (!capable(CAP_SYS_RAWIO) ||
		    security_locked_down(LOCKDOWN_IOPORT))
			return -EPERM;
	}

	t->iopl_emul = level;
	task_update_io_bitmap();

	return 0;
}

