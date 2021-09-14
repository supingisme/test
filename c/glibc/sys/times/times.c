/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:31 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*
 *	clock_t times (struct tms *buffer) [Function]
 *	The times function stores the processor time information for the calling process in
 *	buﬀer.
 *	The return value is the calling process’ CPU time (the same value you get from
 *	clock(). times returns (clock_t)(-1) to indicate failure.
 */

#include <stdio.h>
#include <sys/times.h>

int main()
{
	struct tms buf;

	clock_t ct = times(&buf);

	printf("%d:%d:%d:%d, ct:%d\n", 
			buf.tms_utime, 
			buf.tms_stime,
			buf.tms_cutime,
			buf.tms_cstime,
			ct);


	return 0;
}
