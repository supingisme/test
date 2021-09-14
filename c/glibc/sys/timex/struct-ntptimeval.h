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
struct ntptimeval [Data Type]
This structure is used for information about the system clock. It contains the following
members:
struct timeval time
This is the current calendar time, expressed as the elapsed time since
the epoch. The struct timeval data type is described in Section 21.2
[Elapsed Time], page 540.
long int maxerror
This is the maximum error, measured in microseconds. Unless updated
via ntp_adjtime periodically, this value will reach some platform-specifc
maximum value.
long int esterror
This is the estimated error, measured in microseconds. This value can be
set by ntp_adjtime to indicate the estimated oﬀset of the system clock
from the true calendar time.
*/

#include <sys/timex.h>

struct ntptimeval{
    struct timeval time;
    long int maxerror;
    long int esterror;
};