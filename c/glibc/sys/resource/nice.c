/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
 *	int nice (int increment) [Function]
 *	Increment the nice value of the calling process by increment. The return value is the
 *	new nice value on success, and -1 on failure. In the case of failure, errno will be set
 *	to the same values as for setpriority.
 *	Here is an equivalent defnition of nice:
 *	int
 *	nice (int increment)
 *	{
 *	int result, old = getpriority (PRIO_PROCESS, 0);
 *	result = setpriority (PRIO_PROCESS, 0, old + increment);
 *	if (result != -1)
 *	return old + increment;
 *	else
 *	return -1;
 *	}
 */

#include <sys/resource.h>
#include <stdio.h>

int nice (int increment);

int nice_self (int increment)
{
	int result, old = getpriority (PRIO_PROCESS, 0);
	result = setpriority (PRIO_PROCESS, 0, old + increment);
	if (result != -1)
		return old + increment;
	else
		return -1;
}

int main()
{
	nice(1);
	nice_self(1);

	return 0;
}
