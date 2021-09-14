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
int adjtime (const struct timeval *delta, struct timeval *olddelta) [Function]
This function speeds up or slows down the system clock in order to make a gradual
adjustment. This ensures that the calendar time reported by the system clock is
always monotonically increasing, which might not happen if you simply set the clock.
The delta argument specifes a relative adjustment to be made to the clock time.
If negative, the system clock is slowed down for a while until it has lost this much
elapsed time. If positive, the system clock is speeded up for a while.


If the olddelta argument is not a null pointer, the adjtime function returns informa
tion about any previous time adjustment that has not yet completed.
This function is typically used to synchronize the clocks of computers in a local
network. You must be a privileged user to use it.
With a Linux kernel, you can use the adjtimex function to permanently change the
clock speed.
The return value is 0 on success and -1 on failure. The following errno error condition
is defned for this function:
EPERM You do not have privilege to set the time.
Portability Note: The gettimeofday, settimeofday, and adjtime functions are derived
from BSD.
Symbols for the following function are declared in ‘sys/timex.h’.
*/


#include <sys/time.h>

#include <stdio.h>

int main()
{
	struct timeval tv, tv2;
	struct timezone tz;

	printf("%d\n", gettimeofday(&tv, &tz));

	printf("tv_sec = %d\n", tv.tv_sec);
	printf("tv_usec = %d\n", tv.tv_usec);
	printf("tz_minuteswest = %d\n", tz.tz_minuteswest);
	printf("tz_dsttime = %d\n", tz.tz_dsttime);

    /**/
	printf("%d\n", adjtime(&tv, &tv2));


	return 0;
}
