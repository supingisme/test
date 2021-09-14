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
 *	int setgroups (size t count, gid t *groups) [Function]
 *	This function sets the process’s supplementary group IDs. It can only be called from
 *	privileged processes. The count argument specifes the number of group IDs in the
 *	array groups.
 *	This function returns 0 if successful and -1 on error. The following errno error
 *	conditions are defned for this function:
 *	EPERM The calling process is not privileged.
 *
 *
 *
 *	int initgroups (const char *user, gid t group) [Function]
 *	The initgroups function sets the process’s supplementary group IDs to be the normal
 *	default for the user name user. The group group is automatically included.
 *	This function works by scanning the group database for all the groups user belongs
 *	to. It then calls setgroups with the list it has constructed.
 *	The return values and error conditions are the same as for setgroups.
 */

#include <unistd.h>
#include <sys/types.h>


int setgroups (size_t count, gid_t *groups);
int initgroups (const char *user, gid_t group);

#include <grp.h>
int getgrouplist (const char *user, gid_t group, gid_t *groups, int *ngroups);

int main()
{


	return 0;
}
