/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

struct stat {
	//...
	mode_t st_mode; // mode: S_I{RW}{USR, GRP, OTH}
	uid_t st_uid;	// user ID of owner
	git_t st_gid;	// group ID of owner
	off_t st_size;	// size in bytes
	//...
};

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*	14.9.1 The meaning of the File Attributes
 *	When you read the attributes of a fle, they come back in a structure called struct stat.
 *	This section describes the names of the attributes, their data types, and what they mean.
 *	For the functions to read the attributes of a fle, see Section 14.9.2 [Reading the Attributes
 *	of a File], page 366.
 *	The header fle ‘sys/stat.h’ declares all the symbols defned in this section.
 *	struct stat [Data Type]
 *	The stat structure type is used to return information about the attributes of a fle.
 *	It contains at least the following members:
 *	mode_t st_mode
 *	Specifes the mode of the fle. This includes fle type information (see
 *	Section 14.9.3 [Testing the Type of a File], page 367) and the fle per
 *	mission bits (see Section 14.9.5 [The Mode Bits for Access Permission],
 *	page 370).
 *	ino_t st_ino
 *	The fle serial number, which distinguishes this fle from all other fles on
 *	the same device.
 *	dev_t st_dev
 *	Identifes the device containing the fle. The st_ino and st_dev, taken
 *	together, uniquely identify the fle. The st_dev value is not necessarily
 *	consistent across reboots or system crashes, however.
 *	nlink_t st_nlink
 *	The number of hard links to the fle. This count keeps track of how many
 *	directories have entries for this fle. If the count is ever decremented to
 *	zero, then the fle itself is discarded as soon as no process still holds it
 *	open. Symbolic links are not counted in the total.
 *	uid_t st_uid
 *	The user ID of the fle’s owner. See Section 14.9.4 [File Owner], page 369.
 *	gid_t st_gid
 *	The group ID of the fle. See Section 14.9.4 [File Owner], page 369.
 *	off_t st_size
 *	This specifes the size of a regular fle in bytes. For fles that are really
 *	devices this feld isn’t usually meaningful. For symbolic links this specifes
 *	the length of the fle name the link refers to.
 *	time_t st_atime
 *	This is the last access time for the fle. See Section 14.9.9 [File Times],
 *	page 375.
 *	unsigned long int st_atime_usec
 *	This is the fractional part of the last access time for the fle. See
 *	Section 14.9.9 [File Times], page 375.
 *	time_t st_mtime
 *	This is the time of the last modifcation to the contents of the fle. See
 *	Section 14.9.9 [File Times], page 375.
 *	unsigned long int st_mtime_usec
 *	This is the fractional part of the time of the last modifcation to the
 *	contents of the fle. See Section 14.9.9 [File Times], page 375.
 *	time_t st_ctime
 *	This is the time of the last modifcation to the attributes of the fle. See
 *	Section 14.9.9 [File Times], page 375.
 *	unsigned long int st_ctime_usec
 *	This is the fractional part of the time of the last modifcation to the
 *	attributes of the fle. See Section 14.9.9 [File Times], page 375.
 *	blkcnt_t st_blocks
 *	This is the amount of disk space that the fle occupies, measured in units
 *	of 512-byte blocks.
 *	The number of disk blocks is not strictly proportional to the size of the
 *	fle, for two reasons: the fle system may use some blocks for internal
 *	record keeping; and the fle may be sparse—it may have “holes” which
 *	contain zeros but do not actually take up space on the disk.
 *	You can tell (approximately) whether a fle is sparse by comparing this
 *	value with st_size, like this:
 *	(st.st_blocks * 512 < st.st_size)
 *	This test is not perfect because a fle that is just slightly sparse might
 *	not be detected as sparse at all. For practical applications, this is not a
 *	problem.
 *	unsigned int st_blksize
 *	The optimal block size for reading of writing this fle, in bytes. You might
 *	use this size for allocating the buﬀer space for reading of writing the fle.
 *	(This is unrelated to st_blocks.)
 *	The extensions for the Large File Support (LFS) require, even on 32-bit machines, types
 *	which can handle fle sizes up to 263. Therefore a new defnition of struct stat is necessary.
*
*
*
*
*	struct stat64 [Data Type]
*	The members of this type are the same and have the same names as those in struct
*	stat. The only diﬀerence is that the members st_ino, st_size, and st_blocks have
*	a diﬀerent type to support larger values.
*	mode_t st_mode
*	Specifes the mode of the fle. This includes fle type information (see
		*	Section 14.9.3 [Testing the Type of a File], page 367) and the fle per
*	mission bits (see Section 14.9.5 [The Mode Bits for Access Permission],
		*	page 370).
*	ino64_t st_ino
*	The fle serial number, which distinguishes this fle from all other fles on
*	the same device.
*	dev_t st_dev
*	Identifes the device containing the fle. The st_ino and st_dev, taken
*	together, uniquely identify the fle. The st_dev value is not necessarily
*	consistent across reboots or system crashes, however.
*	nlink_t st_nlink
*	The number of hard links to the fle. This count keeps track of how many
*	directories have entries for this fle. If the count is ever decremented to
*	zero, then the fle itself is discarded as soon as no process still holds it
*	open. Symbolic links are not counted in the total.
*	uid_t st_uid
*	The user ID of the fle’s owner. See Section 14.9.4 [File Owner], page 369.
*	gid_t st_gid
*	The group ID of the fle. See Section 14.9.4 [File Owner], page 369.
*
*	off64_t st_size
*	This specifes the size of a regular fle in bytes. For fles that are really
*	devices this feld isn’t usually meaningful. For symbolic links this specifes
*	the length of the fle name the link refers to.
*	time_t st_atime
*	This is the last access time for the fle. See Section 14.9.9 [File Times],
	*	page 375.
	*	unsigned long int st_atime_usec
	*	This is the fractional part of the last access time for the fle. See
	*	Section 14.9.9 [File Times], page 375.
	*	time_t st_mtime
	*	This is the time of the last modifcation to the contents of the fle. See
	*	Section 14.9.9 [File Times], page 375.
	*	unsigned long int st_mtime_usec
	*	This is the fractional part of the time of the last modifcation to the
	*	contents of the fle. See Section 14.9.9 [File Times], page 375.
	*	time_t st_ctime
	*	This is the time of the last modifcation to the attributes of the fle. See
	*	Section 14.9.9 [File Times], page 375.
	*	unsigned long int st_ctime_usec
	*	This is the fractional part of the time of the last modifcation to the
	*	attributes of the fle. See Section 14.9.9 [File Times], page 375.
	*	blkcnt64_t st_blocks
	*	This is the amount of disk space that the fle occupies, measured in units
	*	of 512-byte blocks.
	*	unsigned int st_blksize
	*	The optimal block size for reading of writing this fle, in bytes. You might
	*	use this size for allocating the buﬀer space for reading of writing the fle.
	*	(This is unrelated to st_blocks.)
	*	Some of the fle attributes have special data type names which exist specifcally for those
	*	attributes. (They are all aliases for well-known integer types that you know and love.) These
	*	typedef names are defned in the header fle ‘sys/types.h’ as well as in ‘sys/stat.h’. Here
	*	is a list of them.
	*
	*
	*
	*
	*
	*
	*	mode_t [Data Type]
	*	This is an integer data type used to represent fle modes. In the GNU system, this is
	*	equivalent to unsigned int.
	*	ino_t [Data Type]
	*	This is an arithmetic data type used to represent fle serial numbers. (In Unix jargon,
			*	these are sometimes called inode numbers.) In the GNU system, this type is equivalent
	*	to unsigned long int.
	*	If the source is compiled with _FILE_OFFSET_BITS == 64 this type is transparently
	*	replaced by ino64_t.
	*
	*
	*	ino64_t [Data Type]
	*	This is an arithmetic data type used to represent fle serial numbers for the use in
	*	LFS. In the GNU system, this type is equivalent to unsigned long long int.
	*	When compiling with _FILE_OFFSET_BITS == 64 this type is available under the name
	*	ino_t.
	*	dev_t [Data Type]
	*	This is an arithmetic data type used to represent fle device numbers. In the GNU
	*	system, this is equivalent to int.
	*	nlink_t [Data Type]
	*	This is an arithmetic data type used to represent fle link counts. In the GNU system,
	*	this is equivalent to unsigned short int.
	*	blkcnt_t [Data Type]
	*	This is an arithmetic data type used to represent block counts. In the GNU system,
	*	this is equivalent to unsigned long int.
	*	If the source is compiled with _FILE_OFFSET_BITS == 64 this type is transparently
	*	replaced by blkcnt64_t.
	*	blkcnt64_t [Data Type]
	*	This is an arithmetic data type used to represent block counts for the use in LFS. In
	*	the GNU system, this is equivalent to unsigned long long int.
	*	When compiling with _FILE_OFFSET_BITS == 64 this type is available under the name
	*	blkcnt_t.
 */
#include <sys/stat.h>
