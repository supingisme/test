
//ioprio_get, ioprio_set - get/set I/O scheduling class and priority
//int ioprio_get(int which, int who);
int ioprio_set(int which, int who, int ioprio);
//Glibc does not provide a wrapper for these system calls; call them using syscall(2).
//#define _GNU_SOURCE         /* See feature_test_macros(7) */
//#include <unistd.h>
//#include <sys/syscall.h>   /* For SYS_xxx definitions */
//
//int syscall(int number, ...);

SYSCALL_DEFINE3(ioprio_set, int, which, int, who, int, ioprio)
{
	struct task_struct *p, *g;
	struct user_struct *user;
	struct pid *pgrp;
	kuid_t uid;
	int ret;

	ret = ioprio_check_cap(ioprio);
	if (ret)
		return ret;

	ret = -ESRCH;
	rcu_read_lock();
	switch (which) {
		case IOPRIO_WHO_PROCESS:
			if (!who)
				p = current;
			else
				p = find_task_by_vpid(who);
			if (p)
				ret = set_task_ioprio(p, ioprio);
			break;
		case IOPRIO_WHO_PGRP:
			if (!who)
				pgrp = task_pgrp(current);
			else
				pgrp = find_vpid(who);
			do_each_pid_thread(pgrp, PIDTYPE_PGID, p) {
				ret = set_task_ioprio(p, ioprio);
				if (ret)
					break;
			} while_each_pid_thread(pgrp, PIDTYPE_PGID, p);
			break;
		case IOPRIO_WHO_USER:
			uid = make_kuid(current_user_ns(), who);
			if (!uid_valid(uid))
				break;
			if (!who)
				user = current_user();
			else
				user = find_user(uid);

			if (!user)
				break;

			for_each_process_thread(g, p) {
				if (!uid_eq(task_uid(p), uid) ||
				    !task_pid_vnr(p))
					continue;
				ret = set_task_ioprio(p, ioprio);
				if (ret)
					goto free_uid;
			}
free_uid:
			if (who)
				free_uid(user);
			break;
		default:
			ret = -EINVAL;
	}

	rcu_read_unlock();
	return ret;
}

