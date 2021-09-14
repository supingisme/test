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
 */

#include <sys/time.h>

#include <stdio.h>
/*
 *	n tm_hour, tm_min, tm_sec—The time of day, in hours, minutes, and seconds.
 *	n tm_year, tm_mon, tm_day—The year, month, and date.
 *	n tm_wday—The day of the week. Zero represents Sunday.
 *	n tm_yday—The day of the year.
 *	n tm_isdst—A flag indicating whether daylight savings time is in effect.
 *
 */
#include <time.h> //strftime
void print_time ()
{
	struct timeval tv;
	struct tm* ptm;
	char time_string[40];
	long milliseconds;
	/* Obtain the time of day, and convert it to a tm struct. */
	gettimeofday (&tv, NULL);
	ptm = localtime (&tv.tv_sec);
	/* Format the date and time, down to a single second. */
	strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
	/* Compute milliseconds from microseconds. */
	milliseconds = tv.tv_usec / 1000;
	/* Print the formatted time, in seconds, followed by a decimal point
	 * and the milliseconds. */
	printf ("%s.%03ld\n", time_string, milliseconds);
}

int main()
{
	print_time();

	struct timeval tv;
	struct timezone tz;

	printf("%d\n", gettimeofday(&tv, &tz));

	printf("tv_sec = %d\n", tv.tv_sec);
	printf("tv_usec = %d\n", tv.tv_usec);
	printf("tz_minuteswest = %d\n", tz.tz_minuteswest);
	printf("tz_dsttime = %d\n", tz.tz_dsttime);


	return 0;
}
