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
 *	void login (const struct utmp *entry) [Function]
 *	The login functions inserts an entry into the user accounting database. The ut_line
 *	member is set to the name of the terminal on standard input. If standard input is
 *	not a terminal login uses standard output or standard error output to determine
 *	the name of the terminal. If struct utmp has a ut_type member, login sets it to
 *	USER_PROCESS, and if there is an ut_pid member, it will be set to the process ID of
 *	the current process. The remaining entries are copied from entry.
 *	A copy of the entry is written to the user accounting log fle.
 */
