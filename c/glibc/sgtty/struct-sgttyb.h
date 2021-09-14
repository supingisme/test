/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/**
17.5 BSD Terminal Modes
The usual way to get and set terminal modes is with the functions described in Section 17.4
[Terminal Modes], page 435. However, on some systems you can use the BSD-derived
functions in this section to do some of the same thing. On many systems, these functions
do not exist. Even with the GNU C library, the functions simply fail with errno = ENOSYS
with many kernels, including Linux.
The symbols used in this section are declared in ‘sgtty.h’.
struct sgttyb [Data Type]
This structure is an input or output parameter list for gtty and stty.

char sg_ispeed Line speed for input
char sg_ospeed Line speed for output
char sg_erase Erase character
char sg_kill Kill character
int sg_flags Various ﬂags
*/
#include <sgtty.h>

struct sgttyb{
    char sg_ispeed;
    char sg_ospeed;
    char sg_erase;
    char sg_kill;
    int sg_flags;
};