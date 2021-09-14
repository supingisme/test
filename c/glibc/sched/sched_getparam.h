#include <sched.h>

int sched_setparam(pid_t pid, const struct sched_param *param);

int sched_getparam(pid_t pid, struct sched_param *param);

struct sched_param {
  ...
  int sched_priority;
  ...
};

/**
 * sys_sched_setparam - set/change the RT priority of a thread
 * @pid: the pid in question.
 * @param: structure containing the new RT priority.
 *
 * Return: 0 on success. An error code otherwise.
 */
SYSCALL_DEFINE2(sched_setparam, pid_t, pid, struct sched_param __user *, param)
{
	return do_sched_setscheduler(pid, SETPARAM_POLICY, param);
}

