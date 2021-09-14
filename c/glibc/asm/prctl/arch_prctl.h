#include <asm/prctl.h>
#include <sys/prctl.h>

//arch_prctl - set architecture-specific thread state
int arch_prctl(int code, unsigned long addr);
int arch_prctl(int code, unsigned long *addr);

//code --------------------
//ARCH_SET_FS
//      Set the 64-bit base for the FS register to addr.
//
//ARCH_GET_FS
//      Return  the  64-bit  base  value  for  the  FS register of the current thread in the unsigned long
//      pointed to by addr.
//
//ARCH_SET_GS
//      Set the 64-bit base for the GS register to addr.
//
//ARCH_GET_GS
//      Return the 64-bit base value for the GS register of  the  current  thread  in  the  unsigned  long
//      pointed to by addr.


//return -------------
//EFAULT addr points to an unmapped address or is outside the process address space.
//
//EINVAL code is not a valid subcommand.
//
//EPERM  addr is outside the process address space.


SYSCALL_DEFINE2(arch_prctl, int, option, unsigned long, arg2)
{
	return -EINVAL;
}

SYSCALL_DEFINE2(arch_prctl, int, option, unsigned long, arg2)
{
	long ret;

	ret = do_arch_prctl_64(current, option, arg2);
	if (ret == -EINVAL)
		ret = do_arch_prctl_common(current, option, arg2);

	return ret;
}

