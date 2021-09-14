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
 *	int setegid (gid t newgid) [Function]
 *	This function sets the eﬀective group ID of the process to newgid, provided that the
 *	process is allowed to change its group ID. Just as with seteuid, if the process is
 *	privileged it may change its eﬀective group ID to any value; if it isn’t, but it has a
 *	fle group ID, then it may change to its real group ID or fle group ID; otherwise it
 *	may not change its eﬀective group ID.
 *	Note that a process is only privileged if its eﬀective user ID is zero. The eﬀective
 *	group ID only aﬀects access permissions.
 *	The return values and error conditions for setegid are the same as those for seteuid.
 *	This function is only present if _POSIX_SAVED_IDS is defned.
 *	int setgid (gid t newgid) [Function]
 *	This function sets both the real and eﬀective group ID of the process to newgid,
 *	provided that the process is privileged. It also deletes the fle group ID, if any.
 *	If the process is not privileged, then setgid behaves like setegid.
 *	The return values and error conditions for setgid are the same as those for seteuid.
 *	int setregid (gid t rgid, gid t egid) [Function]
 *	This function sets the real group ID of the process to rgid and the eﬀective group ID
 *	to egid. If rgid is -1, it means not to change the real group ID; likewise if egid is -1,
 *	it means not to change the eﬀective group ID.
 *	The setregid function is provided for compatibility with 4.3 BSD Unix, which does
 *	not support fle IDs. You can use this function to swap the eﬀective and real group
 *	IDs of the process. (Privileged processes are not limited to this usage.) If fle IDs are
 *	supported, you should use that feature instead of using this function. See Section 29.8
 *	[Enabling and Disabling Setuid Access], page 733.
 *	The return values and error conditions for setregid are the same as those for
 *	setreuid.
 *
 */

#include <unistd.h>
#include <sys/types.h>


int setegid (gid_t newgid);
int setgid (gid_t newgid);
int setregid (gid_t rgid, gid_t egid);


int main()
{

}
