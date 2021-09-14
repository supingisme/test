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
 *	int seteuid (uid t neweuid) [Function]
 *	This function sets the eﬀective user ID of a process to newuid, provided that the
 *	process is allowed to change its eﬀective user ID. A privileged process (eﬀective user
 *	ID zero) can change its eﬀective user ID to any legal value. An unprivileged process
 *	with a fle user ID can change its eﬀective user ID to its real user ID or to its fle user
 *	ID. Otherwise, a process may not change its eﬀective user ID at all.
 *	The seteuid function returns a value of 0 to indicate successful completion, and a
 *	value of -1 to indicate an error. The following errno error conditions are defned for
 *	this function:
 *	EINVAL The value of the newuid argument is invalid.
 *	EPERM The process may not change to the specifed ID.
 *	Older systems (those without the _POSIX_SAVED_IDS feature) do not have this func
 *	tion.
 *
 *
 *	int setuid (uid t newuid) [Function]
 *	If the calling process is privileged, this function sets both the real and eﬀective user
 *	ID of the process to newuid. It also deletes the fle user ID of the process, if any.
 *	newuid may be any legal value. (Once this has been done, there is no way to recover
 *	the old eﬀective user ID.)
 *	If the process is not privileged, and the system supports the _POSIX_SAVED_IDS fea
 *	ture, then this function behaves like seteuid.
 *	The return values and error conditions are the same as for seteuid.
 *
 *
 *	int setreuid (uid t ruid, uid t euid) [Function]
 *	This function sets the real user ID of the process to ruid and the eﬀective user ID to
 *	euid. If ruid is -1, it means not to change the real user ID; likewise if euid is -1, it
 *	means not to change the eﬀective user ID.
 *
 *
 *
 */

#include <unistd.h>
#include <sys/types.h>

int seteuid (uid_t neweuid);
int setuid (uid_t newuid);
int setreuid (uid_t ruid, uid_t euid);


int main()
{

}


