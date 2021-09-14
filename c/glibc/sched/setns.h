#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <sched.h>

//setns - (再关联)reassociate thread with a namespace
int setns(int fd, int nstype);

//fd: argument  is  a  file  descriptor referring to one of the namespace entries in a /proc/[pid]/ns/ directory

//0:                Allow any type of namespace to be joined.
//CLONE_NEWIPC:     fd must refer to an IPC namespace.
//CLONE_NEWNET:     fd must refer to a network namespace.
//CLONE_NEWUTS:     fd must refer to a UTS namespace.

//例如： nstype==CLONE_NEWIPC，编译运行结果如下：
//
// [root@localhost sched]# ./a.out /proc/self/ns/time ls
// error setns.
// [root@localhost sched]# ./a.out /proc/self/ns/ipc ls
// a.out			  sched_getparam.c	    sched_rr_get_interval.man.txt  sched_yield.h
// bits-sched.h		  sched_getparam.h	    sched_setaffinity.c		   sched_yield.man.txt
// clone.h			  sched_get_priority_max.c  sched_setaffinity.h		   setns.c
// clone.man.txt		  sched_get_priority_max.h  sched_setaffinity-redis.c	   setns.h
// CPU_SETSIZE.c		  sched_get_priority_min.c  sched_setparam.c		   setns.man.txt
// CPU_ZERO_SET_CLR_ISSET.c  sched_get_priority_min.h  sched_setparam.h		   struct-sched_param.h
// demo-sched.c		  sched_getscheduler.c	    sched_setparam.man.txt	   type-cpu_set_t.h
// namespace-readme.txt	  sched_getscheduler.h	    sched_setscheduler.c	   uapi-linux-sched.h
// proc.man.5.txt		  sched.h		    sched_setscheduler.h	   unshare.c
// sched_getaffinity.c	  sched_rr_get_interval.c   sched_setscheduler.man.txt	   unshare.h
// sched_getaffinity.h	  sched_rr_get_interval.h   sched_yield.c		   unshare.man.txt




SYSCALL_DEFINE2(setns, int, fd, int, nstype)
{
	struct task_struct *tsk = current;
	struct nsproxy *new_nsproxy;
	struct file *file;
	struct ns_common *ns;
	int err;

	file = proc_ns_fget(fd);
	if (IS_ERR(file))
		return PTR_ERR(file);

	err = -EINVAL;
	ns = get_proc_ns(file_inode(file));
	if (nstype && (ns->ops->type != nstype))
		goto out;

	new_nsproxy = create_new_namespaces(0, tsk, current_user_ns(), tsk->fs);
	if (IS_ERR(new_nsproxy)) {
		err = PTR_ERR(new_nsproxy);
		goto out;
	}

	err = ns->ops->install(new_nsproxy, ns);
	if (err) {
		free_nsproxy(new_nsproxy);
		goto out;
	}
	switch_task_namespaces(tsk, new_nsproxy);

	perf_event_namespaces(tsk);
out:
	fput(file);
	return err;
}



/*
 * Create new nsproxy and all of its the associated namespaces.
 * Return the newly created nsproxy.  Do not attach this to the task,
 * leave it to the caller to do proper locking and attach it to task.
 */
static struct nsproxy *create_new_namespaces(unsigned long flags,
	struct task_struct *tsk, struct user_namespace *user_ns,
	struct fs_struct *new_fs)
{
	struct nsproxy *new_nsp;
	int err;

	new_nsp = create_nsproxy();
	if (!new_nsp)
		return ERR_PTR(-ENOMEM);

	new_nsp->mnt_ns = copy_mnt_ns(flags, tsk->nsproxy->mnt_ns, user_ns, new_fs);
	if (IS_ERR(new_nsp->mnt_ns)) {
		err = PTR_ERR(new_nsp->mnt_ns);
		goto out_ns;
	}

	new_nsp->uts_ns = copy_utsname(flags, user_ns, tsk->nsproxy->uts_ns);
	if (IS_ERR(new_nsp->uts_ns)) {
		err = PTR_ERR(new_nsp->uts_ns);
		goto out_uts;
	}

	new_nsp->ipc_ns = copy_ipcs(flags, user_ns, tsk->nsproxy->ipc_ns);
	if (IS_ERR(new_nsp->ipc_ns)) {
		err = PTR_ERR(new_nsp->ipc_ns);
		goto out_ipc;
	}

	new_nsp->pid_ns_for_children =
		copy_pid_ns(flags, user_ns, tsk->nsproxy->pid_ns_for_children);
	if (IS_ERR(new_nsp->pid_ns_for_children)) {
		err = PTR_ERR(new_nsp->pid_ns_for_children);
		goto out_pid;
	}

	new_nsp->cgroup_ns = copy_cgroup_ns(flags, user_ns,
					    tsk->nsproxy->cgroup_ns);
	if (IS_ERR(new_nsp->cgroup_ns)) {
		err = PTR_ERR(new_nsp->cgroup_ns);
		goto out_cgroup;
	}

	new_nsp->net_ns = copy_net_ns(flags, user_ns, tsk->nsproxy->net_ns);
	if (IS_ERR(new_nsp->net_ns)) {
		err = PTR_ERR(new_nsp->net_ns);
		goto out_net;
	}

	new_nsp->time_ns_for_children = copy_time_ns(flags, user_ns,
					tsk->nsproxy->time_ns_for_children);
	if (IS_ERR(new_nsp->time_ns_for_children)) {
		err = PTR_ERR(new_nsp->time_ns_for_children);
		goto out_time;
	}
	new_nsp->time_ns = get_time_ns(tsk->nsproxy->time_ns);

	return new_nsp;

out_time:
	put_net(new_nsp->net_ns);
out_net:
	put_cgroup_ns(new_nsp->cgroup_ns);
out_cgroup:
	if (new_nsp->pid_ns_for_children)
		put_pid_ns(new_nsp->pid_ns_for_children);
out_pid:
	if (new_nsp->ipc_ns)
		put_ipc_ns(new_nsp->ipc_ns);
out_ipc:
	if (new_nsp->uts_ns)
		put_uts_ns(new_nsp->uts_ns);
out_uts:
	if (new_nsp->mnt_ns)
		put_mnt_ns(new_nsp->mnt_ns);
out_ns:
	kmem_cache_free(nsproxy_cachep, new_nsp);
	return ERR_PTR(err);
}

