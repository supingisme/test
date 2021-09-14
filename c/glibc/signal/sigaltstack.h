#include <signal.h>

typedef struct {
   void  *ss_sp;     /* Base address of stack */
   int    ss_flags;  /* Flags */
   size_t ss_size;   /* Number of bytes in stack */
} stack_t;



//sigaltstack - set and/or get signal stack context
int sigaltstack(const stack_t *ss, stack_t *oss);


//SS_ONSTACK
//      The process is currently executing on the alternate signal stack.  (Note that it is  not  possible
//      to change the alternate signal stack if the process is currently executing on it.)
//
//SS_DISABLE
//      The alternate signal stack is currently disabled.



SYSCALL_DEFINE2(sigaltstack,const stack_t __user *,uss, stack_t __user *,uoss)
{
	stack_t new, old;
	int err;
	if (uss && copy_from_user(&new, uss, sizeof(stack_t)))
		return -EFAULT;
	err = do_sigaltstack(uss ? &new : NULL, uoss ? &old : NULL,
			      current_user_stack_pointer(),
			      MINSIGSTKSZ);
	if (!err && uoss && copy_to_user(uoss, &old, sizeof(stack_t)))
		err = -EFAULT;
	return err;
}

