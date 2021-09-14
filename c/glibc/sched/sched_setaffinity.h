#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <sched.h>

int sched_setaffinity(pid_t pid, size_t cpusetsize,
                     cpu_set_t *mask);

int sched_getaffinity(pid_t pid, size_t cpusetsize,
                     cpu_set_t *mask);


/**
 * sys_sched_setaffinity - set the CPU affinity of a process
 * @pid: pid of the process
 * @len: length in bytes of the bitmask pointed to by user_mask_ptr
 * @user_mask_ptr: user-space pointer to the new CPU mask
 *
 * Return: 0 on success. An error code otherwise.
 */
SYSCALL_DEFINE3(sched_setaffinity, pid_t, pid, unsigned int, len,
		unsigned long __user *, user_mask_ptr)
{
	cpumask_var_t new_mask;
	int retval;

	if (!alloc_cpumask_var(&new_mask, GFP_KERNEL))
		return -ENOMEM;

	retval = get_user_cpu_mask(user_mask_ptr, len, new_mask);
	if (retval == 0)
		retval = sched_setaffinity(pid, new_mask);
	free_cpumask_var(new_mask);
	return retval;
}


/**
 * sys_sched_getaffinity - get the CPU affinity of a process
 * @pid: pid of the process
 * @len: length in bytes of the bitmask pointed to by user_mask_ptr
 * @user_mask_ptr: user-space pointer to hold the current CPU mask
 *
 * Return: size of CPU mask copied to user_mask_ptr on success. An
 * error code otherwise.
 */
SYSCALL_DEFINE3(sched_getaffinity, pid_t, pid, unsigned int, len,
        unsigned long __user *, user_mask_ptr)
{
    int ret;
    cpumask_var_t mask;

    if ((len * BITS_PER_BYTE) < nr_cpu_ids)
        return -EINVAL;
    if (len & (sizeof(unsigned long)-1))
        return -EINVAL;

    if (!alloc_cpumask_var(&mask, GFP_KERNEL))
        return -ENOMEM;

    ret = sched_getaffinity(pid, mask);
    if (ret == 0) {
        unsigned int retlen = min(len, cpumask_size());

        if (copy_to_user(user_mask_ptr, mask, retlen))
            ret = -EFAULT;
        else
            ret = retlen;
    }
    free_cpumask_var(mask);

    return ret;
}

