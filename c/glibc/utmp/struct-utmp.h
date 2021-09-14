/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:36 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:08 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:20 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
/*
 *	struct utmp [Data Type]
 *	The utmp data structure is used to hold information about entries in the user ac
 *	counting database. On the GNU system it has the following members:
 *	short int ut_type
 *	Specifes the type of login; one of EMPTY, RUN_LVL, BOOT_TIME, OLD_
 *	TIME, NEW_TIME, INIT_PROCESS, LOGIN_PROCESS, USER_PROCESS, DEAD_
 *	PROCESS or ACCOUNTING.
 *	pid_t ut_pid
 *	The process ID number of the login process.
 *	char ut_line[]
 *	The device name of the tty (without ‘/dev/’).
 *	char ut_id[]
 *	The inittab ID of the process.
 *	char ut_user[]
 *	The user’s login name.
 *	char ut_host[]
 *	The name of the host from which the user logged in.
 *	struct exit_status ut_exit
 *	The exit status of a process marked as DEAD_PROCESS.
 *	long ut_session
 *	The Session ID, used for windowing.
 *	struct timeval ut_tv
 *	Time the entry was made. For entries of type OLD_TIME this is the time
 *	when the system clock changed, and for entries of type NEW_TIME this is
 *	the time the system clock was set to.
 *	int32_t ut_addr_v6[4]
 *	The Internet address of a remote host.
 *
 */
#include <utmp.h>

struct utmp{
	short int ut_type;
	pid_t ut_pid;
	char ut_line[];
	char ut_id[];
	char ut_user[];
	char ut_host[];
	struct exit_status ut_exit;
	long ut_session;
	struct timeval ut_tv;
	int32_t ut_addr_v6[4];
};
