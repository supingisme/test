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
 *	int gettimeofday (struct timeval *tp, struct timezone *tzp) [Function]
 *	The gettimeofday function returns the current calendar time as the elapsed time
 *	since the epoch in the struct timeval structure indicated by tp. (see Section 21.2
 *	[Elapsed Time], page 540 for a description of struct timeval). Information about
 *	the time zone is returned in the structure pointed at tzp. If the tzp argument is a
 *	null pointer, time zone information is ignored.
 *	The return value is 0 on success and -1 on failure. The following errno error condition
 *	is defned for this function:
 *	ENOSYS The operating system does not support getting time zone information,
 *	and tzp is not a null pointer. The GNU operating system does not sup
 *	port using struct timezone to represent time zone information; that is
 *	an obsolete feature of 4.3 BSD. Instead, use the facilities described in
 *	Section 21.4.8 [Functions and Variables for Time Zones], page 567.
 *
 *
 *
 *	int settimeofday (const struct timeval *tp, const struct timezone [Function]
 *	*tzp)
 *	The settimeofday function sets the current calendar time in the system clock ac
 *	cording to the arguments. As for gettimeofday, the calendar time is represented
 *	as the elapsed time since the epoch. As for gettimeofday, time zone information is
 *	ignored if tzp is a null pointer.
 *	You must be a privileged user in order to use settimeofday.
 *	Some kernels automatically set the system clock from some source such as a hardware
 *	clock when they start up. Others, including Linux, place the system clock in an
 *	“invalid” state (in which attempts to read the clock fail). A call of stime removes
 *	the system clock from an invalid state, and system startup scripts typically run a
 *	program that calls stime.
 *	settimeofday causes a sudden jump forwards or backwards, which can cause a variety
 *	of problems in a system. Use adjtime (below) to make a smooth transition from one
 *	time to another by temporarily speeding up or slowing down the clock.
 *	With a Linux kernel, adjtimex does the same thing and can also make permanent
 *	changes to the speed of the system clock so it doesn’t need to be corrected as often.
 *	The return value is 0 on success and -1 on failure. The following errno error condi
 *	tions are defned for this function:
 *	EPERM This process cannot set the clock because it is not privileged.
 *	ENOSYS The operating system does not support setting time zone information,
 *	and tzp is not a null pointer.
 */

#include <sys/time.h>

#include <stdio.h>

int main()
{
	struct timeval tv;
	struct timezone tz;

	printf("%d\n", gettimeofday(&tv, &tz));

	printf("tv_sec = %d\n", tv.tv_sec);
	printf("tv_usec = %d\n", tv.tv_usec);
	printf("tz_minuteswest = %d\n", tz.tz_minuteswest);
	printf("tz_dsttime = %d\n", tz.tz_dsttime);

    /*need root user do this*/
	printf("%d\n", settimeofday(&tv, &tz));


	return 0;
}
