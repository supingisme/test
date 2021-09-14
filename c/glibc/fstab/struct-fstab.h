/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
 *	struct fstab [Data Type]
 *	This structure is used with the getfsent, getfsspec, and getfsfile functions.
 *	char *fs_spec
 *	This element describes the device from which the flesystem is mounted.
 *	Normally this is the name of a special device, such as a hard disk partition,
 *	but it could also be a more or less generic string. For NFS it would be a
 *	hostname and directory name combination.
 *	Even though the element is not declared const it shouldn’t be modi
 *	fed. The missing const has historic reasons, since this function predates
 *	ISO C. The same is true for the other string elements of this structure.
 *	char *fs_file
 *	This describes the mount point on the local system. I.e., accessing any
 *	fle in this flesystem has implicitly or explicitly this string as a prefx.
 *	char *fs_vfstype
 *	This is the type of the flesystem. Depending on what the underlying
 *	kernel understands it can be any string.
 *	char *fs_mntops
 *	This is a string containing options passed to the kernel with the mount
 *	call. Again, this can be almost anything. There can be more than one
 *	option, separated from the others by a comma. Each option consists of a
 *	name and an optional value part, introduced by an = character.
 *	If the value of this element must be processed it should ideally be done us
 *	ing the getsubopt function; see Section 25.3.12.1 [Parsing of Suboptions],
 *	page 676.
 *	const char *fs_type
 *	This name is poorly chosen. This element points to a string (possibly in
 *	the fs_mntops string) which describes the modes with which the flesys
 *	tem is mounted. ‘fstab’ defnes fve macros to describe the possible
 *	values:
 *	FSTAB_RW The flesystems gets mounted with read and write enabled.
 *	FSTAB_RQ The flesystems gets mounted with read and write enabled.
 *	Write access is restricted by quotas.
 *	FSTAB_RO The flesystem gets mounted read-only.
 *	FSTAB_SW This is not a real flesystem, it is a swap device.
 *	FSTAB_XX This entry from the ‘fstab’ fle is totally ignored.
 *	Testing for equality with these value must happen using strcmp since
 *	these are all strings. Comparing the pointer will probably always fail.
 *	int fs_freq
 *	This element describes the dump frequency in days.
 *	int fs_passno
 *	This element describes the pass number on parallel dumps. It is closely
 *	related to the dump utility used on Unix systems.
 */

#include <fstab.h>


struct fstab{
	char *fs_spec;
	char *fs_file;
	char *fs_vfstype;
	char *fs_mntops;
	const char *fs_type;
	int fs_freq;
	int fs_passno;
};
