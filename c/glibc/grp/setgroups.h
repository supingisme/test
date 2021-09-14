#include <sys/types.h>
#include <unistd.h>

//getgroups() returns the supplementary group IDs of the calling process in list.
int getgroups(int size, gid_t list[]);//get/set list of supplementary(额外的) group IDs

#include <grp.h>

//setgroups() sets the supplementary group IDs for the calling process. 
int setgroups(size_t size, const gid_t *list); //get/set list of supplementary(额外的) group IDs
//


SYSCALL_DEFINE2(getgroups, int, gidsetsize, gid_t __user *, grouplist)
{
	const struct cred *cred = current_cred();
	int i;

	if (gidsetsize < 0)
		return -EINVAL;

	/* no need to grab task_lock here; it cannot change */
	i = cred->group_info->ngroups;
	if (gidsetsize) {
		if (i > gidsetsize) {
			i = -EINVAL;
			goto out;
		}
		if (groups_to_user(grouplist, cred->group_info)) {
			i = -EFAULT;
			goto out;
		}
	}
out:
	return i;
}

