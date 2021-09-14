#include <sys/capability.h>

#ifdef __rtoax_kernel
typedef struct __user_cap_header_struct {
	__u32 version;
	int pid;
} __user *cap_user_header_t;

typedef struct __user_cap_data_struct {
        __u32 effective;
        __u32 permitted;
        __u32 inheritable;
} __user *cap_user_data_t;
#endif //__rtoax_kernel


//capget, capset - set/get capabilities of thread(s)
int capget(cap_user_header_t hdrp, cap_user_data_t datap);

//int capset(cap_user_header_t hdrp, const cap_user_data_t datap);



/**
 * sys_capget - get the capabilities of a given process.
 * @header: pointer to struct that contains capability version and
 *	target pid data
 * @dataptr: pointer to struct that contains the effective, permitted,
 *	and inheritable capabilities that are returned
 *
 * Returns 0 on success and < 0 on error.
 */
SYSCALL_DEFINE2(capget, cap_user_header_t, header, cap_user_data_t, dataptr)
{
	int ret = 0;
	pid_t pid;
	unsigned tocopy;
	kernel_cap_t pE, pI, pP;

	ret = cap_validate_magic(header, &tocopy);
	if ((dataptr == NULL) || (ret != 0))
		return ((dataptr == NULL) && (ret == -EINVAL)) ? 0 : ret;

	if (get_user(pid, &header->pid))
		return -EFAULT;

	if (pid < 0)
		return -EINVAL;

	ret = cap_get_target_pid(pid, &pE, &pI, &pP);
	if (!ret) {
		struct __user_cap_data_struct kdata[_KERNEL_CAPABILITY_U32S];
		unsigned i;

		for (i = 0; i < tocopy; i++) {
			kdata[i].effective = pE.cap[i];
			kdata[i].permitted = pP.cap[i];
			kdata[i].inheritable = pI.cap[i];
		}

		/*
		 * Note, in the case, tocopy < _KERNEL_CAPABILITY_U32S,
		 * we silently drop the upper capabilities here. This
		 * has the effect of making older libcap
		 * implementations implicitly drop upper capability
		 * bits when they perform a: capget/modify/capset
		 * sequence.
		 *
		 * This behavior is considered fail-safe
		 * behavior. Upgrading the application to a newer
		 * version of libcap will enable access to the newer
		 * capabilities.
		 *
		 * An alternative would be to return an error here
		 * (-ERANGE), but that causes legacy applications to
		 * unexpectedly fail; the capget/modify/capset aborts
		 * before modification is attempted and the application
		 * fails.
		 */
		if (copy_to_user(dataptr, kdata, tocopy
				 * sizeof(struct __user_cap_data_struct))) {
			return -EFAULT;
		}
	}

	return ret;
}

