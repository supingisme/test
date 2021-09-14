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
/*	14.9.2 Reading the Attributes of a File

int lstat (const char *filename, struct stat *buf) [Function]
The lstat function is like stat, except that it does not follow symbolic links. If
flename is the name of a symbolic link, lstat returns information about the link
itself; otherwise lstat works like stat. See Section 14.5 [Symbolic Links], page 357.
When the sources are compiled with _FILE_OFFSET_BITS == 64 this function is in fact
lstat64 since the LFS interface transparently replaces the normal implementation.
int lstat64 (const char *filename, struct stat64 *buf) [Function]
This function is similar to lstat but it is also able to work on fles larger then 231
bytes on 32-bit systems. To be able to do this the result is stored in a variable of
type struct stat64 to which buf must point.
When the sources are compiled with _FILE_OFFSET_BITS == 64 this function is avail
able under the name lstat and so transparently replaces the interface for small fles
on 32-bit machines.

 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
	struct stat buf;
	lstat("/home/RongTao/", &buf);	

	printf("mode:%d\n", buf.st_mode);
	printf("ino:%d\n", buf.st_ino);

	return 0;
}
