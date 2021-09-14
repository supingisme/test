/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*	14.2.1 Format of a Directory Entry
 *	This section describes what you fnd in a single directory entry, as you might obtain it from
 *	a directory stream. All the symbols are declared in the header fle ‘dirent.h’.
 *	struct dirent [Data Type]
 *	This is a structure type used to return information about directory entries. It contains
 *	the following felds:
 *	char d_name[]
 *	This is the null-terminated fle name component. This is the only feld
 *	you can count on in all POSIX systems.
 *	ino_t d_fileno
 *	This is the fle serial number. For BSD compatibility, you can also refer
 *	to this member as d_ino. In the GNU system and most POSIX systems,
 *	for most fles this the same as the st_ino member that stat will return
 *	for the fle. See Section 14.9 [File Attributes], page 362.
 *	unsigned char d_namlen
 *	This is the length of the fle name, not including the terminating null
 *	character. Its type is unsigned char because that is the integer type of
 *	the appropriate size
 *	unsigned char d_type
 *	This is the type of the fle, possibly unknown. The following constants
 *	are defned for its value:
 *	DT_UNKNOWN
 *	The type is unknown. On some systems this is the only value
 *	returned.
 *	DT_REG A regular fle.
 *	DT_DIR A directory.
 *	DT_FIFO A named pipe, or FIFO. See Section 15.3 [FIFO Special Files],
 *	page 387.
 *	DT_SOCK A local-domain socket.
 *
 *	DT_CHR A character device.
 *	DT_BLK A block device.
 *	This member is a BSD extension. The symbol _DIRENT_HAVE_D_TYPE is
 *	defned if this member is available. On systems where it is used, it corre
 *	sponds to the fle type bits in the st_mode member of struct statbuf.
 *	If the value cannot be determine the member value is DT UNKNOWN.
 *	These two macros convert between d_type values and st_mode values:
 *	int IFTODT (mode t mode) [Function]
 *	This returns the d_type value corresponding to mode.
 *	mode_t DTTOIF (int dtype) [Function]
 *	This returns the st_mode value corresponding to dtype.
 *
 *
 *	struct dirent 
 *	{
 *		char d_name[];
 *		ino_t d_fileno;
 *		unsigned char d_namlen;
 *		unsigned char d_type;
 *	}
 *
 */

#include <dirent.h>
