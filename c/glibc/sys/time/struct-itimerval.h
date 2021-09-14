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
/**
struct itimerval [Data Type]
This structure is used to specify when a timer should expire. It contains the following
members:
struct timeval it_interval
This is the period between successive timer interrupts. If zero, the alarm
will only be sent once.
struct timeval it_value
This is the period between now and the frst timer interrupt. If zero, the
alarm is disabled.
The struct timeval data type is described in Section 21.2 [Elapsed Time], page 540.


*/
#include <sys/time.h>

struct itimerval
{
    /* Value to put into `it_value' when the timer expires.  */
    struct timeval it_interval;
    /* Time to the next timer expiration.  */
    struct timeval it_value;
};


#ifdef __rtoax_debug

struct itimerval {
   struct timeval it_interval; /* next value */
   struct timeval it_value;    /* current value */
};

struct timeval {
   time_t      tv_sec;         /* seconds */
   suseconds_t tv_usec;        /* microseconds */
};
#endif//__rtoax_debug