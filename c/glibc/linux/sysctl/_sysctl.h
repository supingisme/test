#include <unistd.h>
#include <linux/sysctl.h>

struct __sysctl_args {
	int *name;
	int nlen;
	void *oldval;
	size_t *oldlenp;
	void *newval;
	size_t newlen;
	unsigned long __unused[4];
};


////Glibc  does  not  provide  a wrapper for this system call; call it using syscall(2).
int _sysctl(struct __sysctl_args *args);

//Or rather...  don't
//call it: use of this system call has long been discouraged, and it is so unloved that  it  is  likely  to
//disappear in a future kernel version.  Since Linux 2.6.24, uses of this system call result in warnings in
//the kernel log.  Remove it from your programs now; use the /proc/sys interface instead.

