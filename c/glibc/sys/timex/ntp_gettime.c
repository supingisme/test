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

int ntp_gettime (struct ntptimeval *tptr) [Function]
The ntp_gettime function sets the structure pointed to by tptr to current values.
The elements of the structure afterwards contain the values the timer implementation
in the kernel assumes. They might or might not be correct. If they are not a ntp_
adjtime call is necessary.
The return value is 0 on success and other values on failure. The following errno
error conditions are defned for this function:
TIME_ERROR
The precision clock model is not properly set up at the moment, thus
the clock must be considered unsynchronized, and the values should be
treated with care.


*/

#include <sys/timex.h>
#include <time.h>
#include <stdio.h>

/* struct ntptimeval{
    struct timeval time;
    long int maxerror;
    long int esterror;
}; */

int main()
{
    struct ntptimeval ntv;
    
    printf("%d\n", ntp_gettime(&ntv));
    
    printf("time.tv_sec = %d\n", ntv.time.tv_sec);
    printf("time.tv_usec = %d\n", ntv.time.tv_usec);
    printf("maxerror = %d\n", ntv.maxerror);
    printf("esterror = %d\n", ntv.esterror);
    
    
    return 0;
}