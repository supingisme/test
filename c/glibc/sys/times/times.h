#include <sys/times.h>

//get process and waited-for child process times
clock_t times(struct tms *buffer);



SYSCALL_DEFINE1(times, struct tms __user *, tbuf)
{
	if (tbuf) {
		struct tms tmp;

		do_sys_times(&tmp);
		if (copy_to_user(tbuf, &tmp, sizeof(struct tms)))
			return -EFAULT;
	}
	force_successful_syscall_return();
	return (long) jiffies_64_to_clock_t(get_jiffies_64());
}

