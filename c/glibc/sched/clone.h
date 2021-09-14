

/**
 *	NAME
 *	clone, __clone2 - create a child process
 *
 *	SYNOPSIS
 * /* Prototype for the glibc wrapper function */

#define _GNU_SOURCE
#include <sched.h>

int clone(int (*fn)(void *), void *child_stack,
		int flags, void *arg, ...
		/* pid_t *ptid, void *newtls, pid_t *ctid */ );


//clone(..., flags,...);
#ifdef __USE_GNU
        /* Cloning flags.  */
# define CSIGNAL       0x000000ff /* Signal mask to be sent at exit.  */
# define CLONE_VM      0x00000100 /* Set if VM shared between processes.  */
# define CLONE_FS      0x00000200 /* Set if fs info shared between processes.  */
# define CLONE_FILES   0x00000400 /* Set if open files shared between processes.  */
# define CLONE_SIGHAND 0x00000800 /* Set if signal handlers shared.  */
# define CLONE_PTRACE  0x00002000 /* Set if tracing continues on the child.  */
# define CLONE_VFORK   0x00004000 /* Set if the parent wants the child to
                             wake it up on mm_release.  */
# define CLONE_PARENT  0x00008000 /* Set if we want to have the same
                             parent as the cloner.  */
# define CLONE_THREAD  0x00010000 /* Set to add to same thread group.  */
# define CLONE_NEWNS   0x00020000 /* Set to create new namespace.  */
# define CLONE_SYSVSEM 0x00040000 /* Set to shared SVID SEM_UNDO semantics.  */
# define CLONE_SETTLS  0x00080000 /* Set TLS info.  */
# define CLONE_PARENT_SETTID 0x00100000 /* Store TID in userlevel buffer
                               before MM copy.  */
# define CLONE_CHILD_CLEARTID 0x00200000 /* Register exit futex and memory
                                location to clear.  */
# define CLONE_DETACHED 0x00400000 /* Create clone detached.  */
# define CLONE_UNTRACED 0x00800000 /* Set if the tracing process can't
                              force CLONE_PTRACE on this clone.  */
# define CLONE_CHILD_SETTID 0x01000000 /* Store TID in userlevel buffer in
                              the child.  */
# define CLONE_NEWUTS	0x04000000	/* New utsname group.  */
# define CLONE_NEWIPC	0x08000000	/* New ipcs.  */
# define CLONE_NEWUSER	0x10000000	/* New user namespace.  */
# define CLONE_NEWPID	0x20000000	/* New pid namespace.  */
# define CLONE_NEWNET	0x40000000	/* New network namespace.  */
# define CLONE_IO	0x80000000	/* Clone I/O context.  */
#endif


#ifdef __ARCH_WANT_SYS_CLONE
#ifdef CONFIG_CLONE_BACKWARDS
SYSCALL_DEFINE5(clone, unsigned long, clone_flags, unsigned long, newsp,
		 int __user *, parent_tidptr,
		 unsigned long, tls,
		 int __user *, child_tidptr)
#elif defined(CONFIG_CLONE_BACKWARDS2)
SYSCALL_DEFINE5(clone, unsigned long, newsp, unsigned long, clone_flags,
		 int __user *, parent_tidptr,
		 int __user *, child_tidptr,
		 unsigned long, tls)
#elif defined(CONFIG_CLONE_BACKWARDS3)
SYSCALL_DEFINE6(clone, unsigned long, clone_flags, unsigned long, newsp,
		int, stack_size,
		int __user *, parent_tidptr,
		int __user *, child_tidptr,
		unsigned long, tls)
#else
SYSCALL_DEFINE5(clone, unsigned long, clone_flags, unsigned long, newsp,
		 int __user *, parent_tidptr,
		 int __user *, child_tidptr,
		 unsigned long, tls)
#endif
{
	struct kernel_clone_args args = {
		.flags		= (clone_flags & ~CSIGNAL),
		.pidfd		= parent_tidptr,
		.child_tid	= child_tidptr,
		.parent_tid	= parent_tidptr,
		.exit_signal	= (clone_flags & CSIGNAL),
		.stack		= newsp,
		.tls		= tls,
	};

	if (!legacy_clone_args_valid(&args))
		return -EINVAL;

	return _do_fork(&args);
}
#endif

#ifdef __ARCH_WANT_SYS_CLONE3


/* For the prototype of the raw system call, see NOTES */
/**
 * DESCRIPTION
 * clone() creates a new process, in a manner similar to fork(2).
 */

 
 /**
  * clone3 - create a new process with specific properties
  * @uargs: argument structure
  * @size:  size of @uargs
  *
  * clone3() is the extensible successor to clone()/clone2().
  * It takes a struct as argument that is versioned by its size.
  *
  * Return: On success, a positive PID for the child process.
  *         On error, a negative errno number.
  */
 SYSCALL_DEFINE2(clone3, struct clone_args __user *, uargs, size_t, size)
 {
     int err;
 
     struct kernel_clone_args kargs;
     pid_t set_tid[MAX_PID_NS_LEVEL];
 
     kargs.set_tid = set_tid;
 
     err = copy_clone_args_from_user(&kargs, uargs, size);
     if (err)
         return err;
 
     if (!clone3_args_valid(&kargs))
         return -EINVAL;
 
     return _do_fork(&kargs);
 }
#endif //__ARCH_WANT_SYS_CLONE3