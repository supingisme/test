/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 17:04:49 CST. */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "plug.h"

#define print() printf("%s:%s:%d\n", __FILE__, __func__, __LINE__)

int plug_open(){print();return 1;}
int plug_read(){print();return 1;}
int plug_write(){print();return 1;}
int plug_close(){print();return 1;}
