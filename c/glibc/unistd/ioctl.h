/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
#include <unistd.h>
int ioctl(int fd, int request, ... /* void *arg */ );
//Returns:0 if OK, -1 on error

//There is no standard for the header to include to define the function prototype for ioctl since it is not standardized by POSIX. Many systems define it in <unistd.h>, as we show, but traditional BSD systems define it in <sys/ioctl.h>.
//
//We can divide the requests related to networking into six categories:
//• Socket operations
//• File operations
//• Interface operations
//• ARP cache operations
//• Routing table operations
//• STREAMS system (Chapter 31(See 9.20))

