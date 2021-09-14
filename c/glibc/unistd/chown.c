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
/*	int chown (const char *filename, uid t owner, gid t group) [Function]
 *	The chown function changes the owner of the fle flename to owner, and its group
 *	owner to group.
 *
 *	Changing the owner of the fle on certain systems clears the set-user-ID and set-group
 *	ID permission bits. (This is because those bits may not be appropriate for the new
 *	owner.) Other fle permission bits are not changed.
 *	The return value is 0 on success and -1 on failure. In addition to the usual fle name
 *	errors (see Section 11.2.3 [File Name Errors], page 224), the following errno error
 *	conditions are defned for this function:
 *	EPERM This process lacks permission to make the requested change.
 *	Only privileged users or the fle’s owner can change the fle’s group. On
 *	most fle systems, only privileged users can change the fle owner; some
 *	fle systems allow you to change the owner if you are currently the owner.
 *	When you access a remote fle system, the behavior you encounter is
 *	determined by the system that actually holds the fle, not by the system
 *	your program is running on.
 *	See Section 31.7 [Optional Features in File Support], page 783, for infor
 *	mation about the _POSIX_CHOWN_RESTRICTED macro.
 *	EROFS The fle is on a read-only fle system.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h> /*S_IRUSR*/

int main(int argc, char *argv[])
{
	chown(argv[1], S_ISUID, S_ISGID);

	return 0;
}
