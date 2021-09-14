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
 *	struct timezone [Data Type]
 *	The struct timezone structure is used to hold minimal information about the local
 *	time zone. It has the following members:
 *	int tz_minuteswest
 *	This is the number of minutes west of UTC.
 *	int tz_dsttime
 *	If nonzero, Daylight Saving Time applies during some part of the year.
 *	The struct timezone type is obsolete and should never be used. Instead, use the fa
 *	cilities described in Section 21.4.8 [Functions and Variables for Time Zones], page 567.
 *
 */

#include <sys/time.h>

struct timezone{
	int tz_minuteswest;
	int tz_dsttime;

};
