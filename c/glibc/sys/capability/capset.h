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
//int capget(cap_user_header_t hdrp, cap_user_data_t datap);

int capset(cap_user_header_t hdrp, const cap_user_data_t datap);




/**
 * sys_capset - set capabilities for a process or (*) a group of processes
 * @header: pointer to struct that contains capability version and
 *	target pid data
 * @data: pointer to struct that contains the effective, permitted,
 *	and inheritable capabilities
 *
 * Set capabilities for the current process only.  The ability to any other
 * process(es) has been deprecated and removed.
 *
 * The restrictions on setting capabilities are specified as:
 *
 * I: any raised capabilities must be a subset of the old permitted
 * P: any raised capabilities must be a subset of the old permitted
 * E: must be set to a subset of new permitted
 *
 * Returns 0 on success and < 0 on error.
 */
SYSCALL_DEFINE2(capset, cap_user_header_t, header, const cap_user_data_t, data)
{
	struct __user_cap_data_struct kdata[_KERNEL_CAPABILITY_U32S];
	unsigned i, tocopy, copybytes;
	kernel_cap_t inheritable, permitted, effective;
	struct cred *new;
	int ret;
	pid_t pid;

	ret = cap_validate_magic(header, &tocopy);
	if (ret != 0)
		return ret;

	if (get_user(pid, &header->pid))
		return -EFAULT;

	/* may only affect current now */
	if (pid != 0 && pid != task_pid_vnr(current))
		return -EPERM;

	copybytes = tocopy * sizeof(struct __user_cap_data_struct);
	if (copybytes > sizeof(kdata))
		return -EFAULT;

	if (copy_from_user(&kdata, data, copybytes))
		return -EFAULT;

	for (i = 0; i < tocopy; i++) {
		effective.cap[i] = kdata[i].effective;
		permitted.cap[i] = kdata[i].permitted;
		inheritable.cap[i] = kdata[i].inheritable;
	}
	while (i < _KERNEL_CAPABILITY_U32S) {
		effective.cap[i] = 0;
		permitted.cap[i] = 0;
		inheritable.cap[i] = 0;
		i++;
	}

	effective.cap[CAP_LAST_U32] &= CAP_LAST_U32_VALID_MASK;
	permitted.cap[CAP_LAST_U32] &= CAP_LAST_U32_VALID_MASK;
	inheritable.cap[CAP_LAST_U32] &= CAP_LAST_U32_VALID_MASK;

	new = prepare_creds();
	if (!new)
		return -ENOMEM;

	ret = security_capset(new, current_cred(),
			      &effective, &inheritable, &permitted);
	if (ret < 0)
		goto error;

	audit_log_capset(new, current_cred());

	return commit_creds(new);

error:
	abort_creds(new);
	return ret;
}

