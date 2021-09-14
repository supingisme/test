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
 *	To examine the attributes of fles, use the functions stat, fstat and lstat. They return
 *	the attribute information in a struct stat object. All three functions are declared in the
 *	header fle ‘sys/stat.h’.
 *	int stat (const char *filename, struct stat *buf) [Function]
 *	The stat function returns information about the attributes of the fle named by
 *	flename in the structure pointed to by buf.
 *	If flename is the name of a symbolic link, the attributes you get describe the fle
 *	that the link points to. If the link points to a nonexistent fle name, then stat fails
 *	reporting a nonexistent fle.
 *	The return value is 0 if the operation is successful, or -1 on failure. In addition to the
 *	usual fle name errors (see Section 11.2.3 [File Name Errors], page 224, the following
 *	errno error conditions are defned for this function:
 *	ENOENT The fle named by flename doesn’t exist.
 *	When the sources are compiled with _FILE_OFFSET_BITS == 64 this function is in fact
 *	stat64 since the LFS interface transparently replaces the normal implementation.
 *	int stat64 (const char *filename, struct stat64 *buf) [Function]
 *	This function is similar to stat but it is also able to work on fles larger then 231
 *	bytes on 32-bit systems. To be able to do this the result is stored in a variable of
 *	type struct stat64 to which buf must point.
 *	When the sources are compiled with _FILE_OFFSET_BITS == 64 this function is avail
 *	able under the name stat and so transparently replaces the interface for small fles
 *	on 32-bit machines.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 *	[rongtao@localhost stat]$ gcc stat.c 
 *	[rongtao@localhost stat]$ ./a.out $(pwd)/a.out
 *	mode:33277
 *	ino:71159680
 *	Owning user can write `/home/rongtao/test/c/glibc/sys/stat/a.out'.
 */

int main(int argc, char *argv[])
{
	struct stat buf;
	stat(argv[1], &buf);	

	printf("mode:%d\n", buf.st_mode);
	printf("ino:%d\n", buf.st_ino);

	const char* const filename = argv[1];
	//struct stat buf;
	/* Get file information. */
	stat (filename, &buf);
	/* If the permissions are set such that the file's owner can write
	 * to it, print a message. */
	if (buf.st_mode & S_IWUSR)
		printf ("Owning user can write `%s'.\n", filename);
	return 0;

	return 0;
}
