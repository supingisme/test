/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*
 *	These functions are declared in ‘sys/wait.h’.
 *	union wait [Data Type]
 *	This data type represents program termination status values. It has the following
 *	members:
 *	int w_termsig
 *	The value of this member is the same as that of the WTERMSIG macro.
 *	int w_coredump
 *	The value of this member is the same as that of the WCOREDUMP macro.
 *	int w_retcode
 *	The value of this member is the same as that of the WEXITSTATUS macro.
 *	int w_stopsig
 *	The value of this member is the same as that of the WSTOPSIG macro.
 *	Instead of accessing these members directly, you should use the equivalent macros.
 *
 *
 */

#include <sys/wait.h>

union wait{
	int w_termsig;
	int w_coredump;
	int w_retcode;
	int w_stopsig;
};
