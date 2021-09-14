
#include <sys/types.h>
#include <unistd.h>

//set group identity
int setgid(gid_t gid);



SYSCALL_DEFINE1(setgid, gid_t, gid)
{
	return __sys_setgid(gid);
}

/*
 * setgid() is implemented like SysV w/ SAVED_IDS
 *
 * SMP: Same implicit races as above.
 */
long __sys_setgid(gid_t gid)
{
	struct user_namespace *ns = current_user_ns();
	const struct cred *old;
	struct cred *new;
	int retval;
	kgid_t kgid;

	kgid = make_kgid(ns, gid);
	if (!gid_valid(kgid))
		return -EINVAL;

	new = prepare_creds();
	if (!new)
		return -ENOMEM;
	old = current_cred();

	retval = -EPERM;
	if (ns_capable(old->user_ns, CAP_SETGID))
		new->gid = new->egid = new->sgid = new->fsgid = kgid;
	else if (gid_eq(kgid, old->gid) || gid_eq(kgid, old->sgid))
		new->egid = new->fsgid = kgid;
	else
		goto error;

	return commit_creds(new);

error:
	abort_creds(new);
	return retval;
}

