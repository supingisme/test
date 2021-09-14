
#include <linux/unistd.h>
#include <asm/ldt.h>

//get_thread_area - get a thread-local storage (TLS) area
int get_thread_area(struct user_desc *u_info);


SYSCALL_DEFINE1(get_thread_area, struct user_desc __user *, u_info)
{
	return do_get_thread_area(current, -1, u_info);
}



SYSCALL_DEFINE1(get_thread_area, struct user_desc __user *, user_desc)
{
	struct user_desc info;
	int idx, ret;

	if (!host_supports_tls)
		return -ENOSYS;

	if (get_user(idx, &user_desc->entry_number))
		return -EFAULT;

	ret = get_tls_entry(current, &info, idx);
	if (ret < 0)
		goto out;

	if (copy_to_user(user_desc, &info, sizeof(info)))
		ret = -EFAULT;

out:
	return ret;
}

