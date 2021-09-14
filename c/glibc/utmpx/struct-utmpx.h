/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:37 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:37 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:09 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:21 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
/*
 *	struct utmpx [Data Type]
 *	The utmpx data structure contains at least the following members:
 *	short int ut_type
 *	Specifes the type of login; one of EMPTY, RUN_LVL, BOOT_TIME,
 *	OLD_TIME, NEW_TIME, INIT_PROCESS, LOGIN_PROCESS, USER_PROCESS or
 *	DEAD_PROCESS.
 *	pid_t ut_pid
 *	The process ID number of the login process.
 *	char ut_line[]
 *	The device name of the tty (without ‘/dev/’).
 *	char ut_id[]
 *	The inittab ID of the process.
 *	char ut_user[]
 *	The user’s login name.
 *	struct timeval ut_tv
 *	Time the entry was made. For entries of type OLD_TIME this is the time
 *	when the system clock changed, and for entries of type NEW_TIME this is
 *	the time the system clock was set to.
 *
 */

#include <utmpx.h>

struct utmpx{
	short int ut_type;
	pid_t ut_pid;
	char ut_line[];
	char ut_id[];
	char ut_user[];
	struct timeval ut_tv;
};
