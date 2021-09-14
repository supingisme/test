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
 *	int mount (const char *special_file, const char *dir, const char [Function]
 *	*fstype, unsigned long int options, const void *data)
 *	mount mounts or remounts a flesystem. The two operations are quite diﬀerent and are
 *	merged rather unnaturally into this one function. The MS_REMOUNT option, explained
 *	below, determines whether mount mounts or remounts.
 *	For a mount, the flesystem on the block device represented by the device special
 *	fle named special fle gets mounted over the mount point dir. This means that the
 *	directory dir (along with any fles in it) is no longer visible; in its place (and still with
 *	the name dir) is the root directory of the flesystem on the device.
 *	As an exception, if the flesystem type (see below) is one which is not based on a
 *	device (e.g. “proc”), mount instantiates a flesystem and mounts it over dir and
 *	ignores special fle.
 *	For a remount, dir specifes the mount point where the flesystem to be remounted is
 *	(and remains) mounted and special fle is ignored. Remounting a flesystem means
 *	changing the options that control operations on the flesystem while it is mounted. It
 *	does not mean unmounting and mounting again.
 *	For a mount, you must identify the type of the flesystem as fstype. This type tells the
 *	kernel how to access the flesystem and can be thought of as the name of a flesystem
 *	driver. The acceptable values are system dependent. On a system with a Linux kernel
 *	and the proc flesystem, the list of possible values is in the fle ‘filesystems’ in the
 *	proc flesystem (e.g. type cat /proc/filesystems to see the list). With a Linux
 *	kernel, the types of flesystems that mount can mount, and their type names, depends
 *	on what flesystem drivers are confgured into the kernel or loaded as loadable kernel
 *	modules. An example of a common value for fstype is ext2.
 *	For a remount, mount ignores fstype.
 *	options specifes a variety of options that apply until the flesystem is unmounted or
 *	remounted. The precise meaning of an option depends on the flesystem and with some
 *	flesystems, an option may have no eﬀect at all. Furthermore, for some flesystems,
 *	some of these options (but never MS_RDONLY) can be overridden for individual fle
 *	accesses via ioctl.
 *	options is a bit string with bit felds defned using the following mask and masked
 *	value macros:
 *	MS_MGC_MASK
 *	This multibit feld contains a magic number. If it does not have the value
 *	MS_MGC_VAL, mount assumes all the following bits are zero and the data
 *	argument is a null string, regardless of their actual values.
 *	MS_REMOUNT
 *	This bit on means to remount the flesystem. Oﬀ means to mount it.
 *	MS_RDONLY
 *	This bit on specifes that no writing to the flesystem shall be allowed
 *	while it is mounted. This cannot be overridden by ioctl. This option is
 *	available on nearly all flesystems.
 *	S_IMMUTABLE
 *	This bit on specifes that no writing to the fles in the flesystem shall be
 *	allowed while it is mounted. This can be overridden for a particular fle
 *	access by a properly privileged call to ioctl. This option is a relatively
 *	new invention and is not available on many flesystems.
 *	S_APPEND This bit on specifes that the only fle writing that shall be allowed while
 *	the flesystem is mounted is appending. Some flesystems allow this to
 *	be overridden for a particular process by a properly privileged call to
 *	ioctl. This is a relatively new invention and is not available on many
 *	flesystems.
 *	MS_NOSUID
 *	This bit on specifes that Setuid and Setgid permissions on fles in the
 *	flesystem shall be ignored while it is mounted.
 *	MS_NOEXEC
 *	This bit on specifes that no fles in the flesystem shall be executed while
 *	the flesystem is mounted.
 *	MS_NODEV This bit on specifes that no device special fles in the flesystem shall be
 *	accessible while the flesystem is mounted.
 *	MS_SYNCHRONOUS
 *	This bit on specifes that all writes to the flesystem while it is mounted
 *	shall be synchronous; i.e., data shall be synced before each write com
 *	pletes rather than held in the buﬀer cache.
 *	MS_MANDLOCK
 *	This bit on specifes that mandatory locks on fles shall be permitted
 *	while the flesystem is mounted.
 *	MS_NOATIME
 *	This bit on specifes that access times of fles shall not be updated when
 *	the fles are accessed while the flesystem is mounted.
*	MS_NODIRATIME
*	This bit on specifes that access times of directories shall not be updated
*	when the directories are accessed while the flesystem in mounted.
*	Any bits not covered by the above masks should be set oﬀ; otherwise, results are
*	undefned.
*	The meaning of data depends on the flesystem type and is controlled entirely by the
*	flesystem driver in the kernel.
*	Example:
*	#include <sys/mount.h>
*	mount("/dev/hdb", "/cdrom", MS_MGC_VAL | MS_RDONLY | MS_NOSUID, "");
*	mount("/dev/hda2", "/mnt", MS_MGC_VAL | MS_REMOUNT, "");
*	Appropriate arguments for mount are conventionally recorded in the ‘fstab’ table.
*	See Section 30.3.1 [Mount Information], page 758.
*
*
*
*	The return value is zero if the mount or remount is successful. Otherwise, it is -1 and
*	errno is set appropriately. The values of errno are flesystem dependent, but here is
*	a general list:
*	EPERM The process is not superuser.
*	ENODEV The fle system type fstype is not known to the kernel.
*	ENOTBLK The fle dev is not a block device special fle.
*	EBUSY
*	• The device is already mounted.
*	• The mount point is busy. (E.g. it is some process’ working directory
		*	or has a flesystem mounted on it already).
*	• The request is to remount read-only, but there are fles open for
*	write.
*	EINVAL
*	• A remount was attempted, but there is no flesystem mounted over
*	the specifed mount point.
*	• The supposed flesystem has an invalid superblock.
*	EACCES
*	• The flesystem is inherently read-only (possibly due to a switch on
		*	the device) and the process attempted to mount it read/write (by
			*	setting the MS_RDONLY bit oﬀ).
		*	• special fle or dir is not accessible due to fle permissions.
		*	• special fle is not accessible because it is in a flesystem that is
		*	mounted with the MS_NODEV option.
		*	EM_FILE The table of dummy devices is full. mount needs to create a dummy
		*	device (aka “unnamed” device) if the flesystem being mounted is not
		*	one that uses a device.
		*

 */

#include <sys/mount.h>


int mount (const char *special_file, const char *dir, const char
		*fstype, unsigned long int options, const void *data);

