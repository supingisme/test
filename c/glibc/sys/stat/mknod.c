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

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*	14.10 Making Special Files
 *	The mknod function is the primitive for making special fles, such as fles that correspond
 *	to devices. The GNU library includes this function for compatibility with BSD.
 *	The prototype for mknod is declared in ‘sys/stat.h’.
 *	int mknod (const char *filename, int mode, int dev) [Function]
 *	The mknod function makes a special fle with name flename. The mode specifes the
 *	mode of the fle, and may include the various special fle bits, such as S_IFCHR (for a
 *	character special fle) or S_IFBLK (for a block special fle). See Section 14.9.3 [Testing
 *	the Type of a File], page 367.
 *	The dev argument specifes which device the special fle refers to. Its exact interpre
 *	tation depends on the kind of special fle being created.
 *	The return value is 0 on success and -1 on error. In addition to the usual fle name
 *	errors (see Section 11.2.3 [File Name Errors], page 224), the following errno error
 *	conditions are defned for this function:
 *	EPERM The calling process is not privileged. Only the superuser can create spe
 *	cial fles.
 *	ENOSPC The directory or fle system that would contain the new fle is full and
 *	cannot be extended.
 *	EROFS The directory containing the new fle can’t be modifed because it’s on a
 *	read-only fle system.
 *	EEXIST There is already a fle named flename. If you want to replace this fle,
 *	you must remove the old fle explicitly frst.
 */
#include <stdio.h>
#include <sys/stat.h>

int main()
{
	/**
	 *	need root user
	 */
	printf("%d\n",mknod("tmp.out",  S_IFCHR, 0));
	perror("mknod");
	return 0;
}
