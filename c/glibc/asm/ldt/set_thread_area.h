#include <linux/unistd.h>
#include <asm/ldt.h>

//The user_desc structure is defined in <asm/ldt.h> as:
struct user_desc {
    unsigned int  entry_number;
    unsigned long base_addr;
    unsigned int  limit;
    unsigned int  seg_32bit:1;
    unsigned int  contents:2;
    unsigned int  read_exec_only:1;
    unsigned int  limit_in_pages:1;
    unsigned int  seg_not_present:1;
    unsigned int  useable:1;
};


//set_thread_area - set a thread local storage (TLS) area
int set_thread_area(struct user_desc *u_info);


SYSCALL_DEFINE1(set_thread_area, struct user_desc __user *, u_info)
{
	return do_set_thread_area(current, -1, u_info, 1);
}


SYSCALL_DEFINE1(set_thread_area, struct user_desc __user *, user_desc)
{
	struct user_desc info;
	int idx, ret;

	if (!host_supports_tls)
		return -ENOSYS;

	if (copy_from_user(&info, user_desc, sizeof(info)))
		return -EFAULT;

	idx = info.entry_number;

	if (idx == -1) {
		idx = get_free_idx(current);
		if (idx < 0)
			return idx;
		info.entry_number = idx;
		/* Tell the user which slot we chose for him.*/
		if (put_user(idx, &user_desc->entry_number))
			return -EFAULT;
	}

	ret = do_set_thread_area(&info);
	if (ret)
		return ret;
	return set_tls_entry(current, &info, idx, 1);
}

