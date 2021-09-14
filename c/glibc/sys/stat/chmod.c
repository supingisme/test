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
/*
int chmod (const char *filename, mode t mode) [Function]
The chmod function sets the access permission bits for the fle named by flename to
mode.
If flename is a symbolic link, chmod changes the permissions of the fle pointed to by
the link, not those of the link itself.
This function returns 0 if successful and -1 if not. In addition to the usual fle name
errors (see Section 11.2.3 [File Name Errors], page 224), the following errno error
conditions are defned for this function:
ENOENT The named fle doesn’t exist.
EPERM This process does not have permission to change the access permissions
of this fle. Only the fle’s owner (as judged by the eﬀective user ID of
the process) or a privileged user can change them.
EROFS The fle resides on a read-only fle system.
EFTYPE mode has the S_ISVTX bit (the “sticky bit”) set, and the named fle is
not a directory. Some systems do not allow setting the sticky bit on

non-directory fles, and some do (and only some of those assign a useful
meaning to the bit for non-directory fles).
You only get EFTYPE on systems where the sticky bit has no useful mean
ing for non-directory fles, so it is always safe to just clear the bit in mode
and call chmod again. See Section 14.9.5 [The Mode Bits for Access Per
mission], page 370, for full details on the sticky bit.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	//mkdir("rong.out", 0777);

	chmod(argv[1], 04244);

	return 0;
}
