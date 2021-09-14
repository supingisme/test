#include <sys/timex.h>

//adjtimex - tune kernel clock
//调整内核时钟
int adjtimex(struct timex *buf);




#ifdef CONFIG_64BIT
SYSCALL_DEFINE1(adjtimex, struct __kernel_timex __user *, txc_p)
{
	struct __kernel_timex txc;		/* Local copy of parameter */
	int ret;

	/* Copy the user data space into the kernel copy
	 * structure. But bear in mind that the structures
	 * may change
	 */
	if (copy_from_user(&txc, txc_p, sizeof(struct __kernel_timex)))
		return -EFAULT;
	ret = do_adjtimex(&txc);
	return copy_to_user(txc_p, &txc, sizeof(struct __kernel_timex)) ? -EFAULT : ret;
}
#endif


SYSCALL_DEFINE1(adjtimex_time32, struct old_timex32 __user *, utp)
{
	struct __kernel_timex txc;
	int err, ret;

	err = get_old_timex32(&txc, utp);
	if (err)
		return err;

	ret = do_adjtimex(&txc);

	err = put_old_timex32(utp, &txc);
	if (err)
		return err;

	return ret;
}

