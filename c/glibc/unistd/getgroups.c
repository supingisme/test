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
 *	int getgroups (int count, gid t *groups) [Function]
 *	The getgroups function is used to inquire about the supplementary group IDs of the
 *	process. Up to count of these group IDs are stored in the array groups; the return
 *	value from the function is the number of group IDs actually stored. If count is smaller
 *	than the total number of supplementary group IDs, then getgroups returns a value
 *	of -1 and errno is set to EINVAL.
 *	If count is zero, then getgroups just returns the total number of supplementary group
 *	IDs. On systems that do not support supplementary groups, this will always be zero.
 *	Here’s how to use getgroups to read all the supplementary group IDs:
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <malloc.h>
//#include <xmalloc.h>

gid_t *read_all_groups (void)
{
	int ngroups = getgroups (0, NULL);
	gid_t *groups
		= (gid_t *) malloc (ngroups * sizeof (gid_t));
	int val = getgroups (ngroups, groups);
	if (val < 0)
	{
		free (groups);
		return NULL;
	}
	return groups;
}

int main()
{
	gid_t *gid = read_all_groups();

	printf("%d\n", gid[0]);

	return 0;
}
