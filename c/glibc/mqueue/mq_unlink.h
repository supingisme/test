/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:25 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 09:35:20 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 09:35:15 CST. */

#include <mqueue.h>

//remove a message queue
int mq_unlink(const char *name);
//-lrt


SYSCALL_DEFINE1(mq_unlink, const char __user *, u_name)
{
	int err;
	struct filename *name;
	struct dentry *dentry;
	struct inode *inode = NULL;
	struct ipc_namespace *ipc_ns = current->nsproxy->ipc_ns;
	struct vfsmount *mnt = ipc_ns->mq_mnt;

	name = getname(u_name);
	if (IS_ERR(name))
		return PTR_ERR(name);

	audit_inode_parent_hidden(name, mnt->mnt_root);
	err = mnt_want_write(mnt);
	if (err)
		goto out_name;
	inode_lock_nested(d_inode(mnt->mnt_root), I_MUTEX_PARENT);
	dentry = lookup_one_len(name->name, mnt->mnt_root,
				strlen(name->name));
	if (IS_ERR(dentry)) {
		err = PTR_ERR(dentry);
		goto out_unlock;
	}

	inode = d_inode(dentry);
	if (!inode) {
		err = -ENOENT;
	} else {
		ihold(inode);
		err = vfs_unlink(d_inode(dentry->d_parent), dentry, NULL);
	}
	dput(dentry);

out_unlock:
	inode_unlock(d_inode(mnt->mnt_root));
	if (inode)
		iput(inode);
	mnt_drop_write(mnt);
out_name:
	putname(name);

	return err;
}


