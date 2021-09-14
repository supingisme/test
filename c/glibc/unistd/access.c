/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*
int access (const char *filename, int how) [Function]
The access function checks to see whether the fle named by flename can be accessed
in the way specifed by the how argument. The how argument either can be the
bitwise OR of the ﬂags R_OK, W_OK, X_OK, or the existence test F_OK.
This function uses the real user and group IDs of the calling process, rather than the
eﬀective IDs, to check for access permission. As a result, if you use the function from
a setuid or setgid program (see Section 29.4 [How an Application Can Change
Persona], page 728), it gives information relative to the user who actually ran the
program.
The return value is 0 if the access is permitted, and -1 otherwise. (In other words,
treated as a predicate function, access returns true if the requested access is denied.)
In addition to the usual fle name errors (see Section 11.2.3 [File Name Errors],
page 224), the following errno error conditions are defned for this function:
EACCES The access specifed by how is denied.
ENOENT The fle doesn’t exist.
EROFS Write permission was requested for a fle on a read-only fle system.
These macros are defned in the header fle ‘unistd.h’ for use as the how argument to
the access function. The values are integer constants.
int R_OK [Macro]
Flag meaning test for read permission.
int W_OK [Macro]
Flag meaning test for write permission.
int X_OK [Macro]
Flag meaning test for execute/search permission.
int F_OK [Macro]
Flag meaning test for existence of the fle.


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
	mkdir("mkdir.out", 00);

	if(0 != access("mkadfdir.out", F_OK))
	{
		perror("access");
		printf("%s\n", strerror(errno));
	}

	return 0;
}
