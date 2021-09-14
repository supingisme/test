/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:31 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
 *	int umount2 (const char *file, int flags) [Function]
 *	umount2 unmounts a flesystem.
 *	You can identify the flesystem to unmount either by the device special fle that
 *	contains the flesystem or by the mount point. The eﬀect is the same. Specify either
 *	as the string fle.
 *	ﬂags contains the one-bit feld identifed by the following mask macro:
 *	MNT_FORCE
 *	This bit on means to force the unmounting even if the flesystem is busy,
 *	by making it unbusy frst. If the bit is oﬀ and the flesystem is busy,
 *	umount2 fails with errno = EBUSY. Depending on the flesystem, this
 *	may override all, some, or no busy conditions.
 *	All other bits in ﬂags should be set to zero; otherwise, the result is undefned.
 *	Example:
 *	#include <sys/mount.h>
 *	umount2("/mnt", MNT_FORCE);
 *	umount2("/dev/hdd1", 0);
 *	After the flesystem is unmounted, the directory that was the mount point is visible,
 *	as are any fles in it.
 *	As part of unmounting, umount2 syncs the flesystem.
 *	If the unmounting is successful, the return value is zero. Otherwise, it is -1 and errno
 *	is set accordingly:
 *	EPERM The process is not superuser.
 *	EBUSY The flesystem cannot be unmounted because it is busy. E.g. it contains
 *	a directory that is some process’s working directory or a fle that some
 *	process has open. With some flesystems in some cases, you can avoid
 *	this failure with the MNT_FORCE option.
 *	EINVAL fle validly refers to a fle, but that fle is neither a mount point nor a
 *	device special fle of a currently mounted flesystem.
 *	This function is not available on all systems.
 */

#include <sys/mount.h>

int umount2 (const char *file, int flags);

