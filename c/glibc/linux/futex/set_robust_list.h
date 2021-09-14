#include <linux/futex.h> //futex - 快速的健壮的用户空间互斥
#include <syscall.h>

//get_robust_list, set_robust_list - get/set list of robust futexes
//long get_robust_list(int pid, struct robust_list_head **head_ptr, size_t *len_ptr);
long set_robust_list(struct robust_list_head *head, size_t len);



/**
 * sys_set_robust_list() - Set the robust-futex list head of a task
 * @head:	pointer to the list-head
 * @len:	length of the list-head, as userspace expects
 */
SYSCALL_DEFINE2(set_robust_list, struct robust_list_head __user *, head,
		size_t, len)
{
	if (!futex_cmpxchg_enabled)
		return -ENOSYS;
	/*
	 * The kernel knows only one size for now:
	 */
	if (unlikely(len != sizeof(*head)))
		return -EINVAL;

	current->robust_list = head;

	return 0;
}

