

//ioprio_get, ioprio_set - get/set I/O scheduling class and priority
int ioprio_get(int which, int who);
//int ioprio_set(int which, int who, int ioprio);
//Glibc does not provide a wrapper for these system calls; call them using syscall(2).
//#define _GNU_SOURCE         /* See feature_test_macros(7) */
//#include <unistd.h>
//#include <sys/syscall.h>   /* For SYS_xxx definitions */
//
//int syscall(int number, ...);

#define IOPRIO_WHO_PROCESS ????
//      who  is a process ID or thread ID identifying a single process or thread.  If who is 0, then oper‐
//      ate on the calling thread.

#define IOPRIO_WHO_PGRP ????
//      who is a process group ID identifying all the members of a process group.  If who is 0, then oper‐
//      ate on the process group of which the caller is a member.

#define IOPRIO_WHO_USER ????
//      who is a user ID identifying all of the processes that have a matching real UID.



SYSCALL_DEFINE2(ioprio_get, int, which, int, who)
{
	struct task_struct *g, *p;
	struct user_struct *user;
	struct pid *pgrp;
	kuid_t uid;
	int ret = -ESRCH;
	int tmpio;

	rcu_read_lock();
	switch (which) {
		case IOPRIO_WHO_PROCESS:
			if (!who)
				p = current;
			else
				p = find_task_by_vpid(who);
			if (p)
				ret = get_task_ioprio(p);
			break;
		case IOPRIO_WHO_PGRP:
			if (!who)
				pgrp = task_pgrp(current);
			else
				pgrp = find_vpid(who);
			do_each_pid_thread(pgrp, PIDTYPE_PGID, p) {
				tmpio = get_task_ioprio(p);
				if (tmpio < 0)
					continue;
				if (ret == -ESRCH)
					ret = tmpio;
				else
					ret = ioprio_best(ret, tmpio);
			} while_each_pid_thread(pgrp, PIDTYPE_PGID, p);
			break;
		case IOPRIO_WHO_USER:
			uid = make_kuid(current_user_ns(), who);
			if (!who)
				user = current_user();
			else
				user = find_user(uid);

			if (!user)
				break;

			for_each_process_thread(g, p) {
				if (!uid_eq(task_uid(p), user->uid) ||
				    !task_pid_vnr(p))
					continue;
				tmpio = get_task_ioprio(p);
				if (tmpio < 0)
					continue;
				if (ret == -ESRCH)
					ret = tmpio;
				else
					ret = ioprio_best(ret, tmpio);
			}

			if (who)
				free_uid(user);
			break;
		default:
			ret = -EINVAL;
	}

	rcu_read_unlock();
	return ret;
}

