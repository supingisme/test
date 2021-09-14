/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:18 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:27 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 08:57:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:57:39 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:52:32 CST. */
#include <netinet/in.h>

int inet6_opt_init(void *extbuf, socklen_t extlen) ;
//Returns: number of bytes required to hold empty extension header, -1 on error
int inet6_opt_append(void *extbuf, socklen_t extlen, int offset, uint8_t type, 
						socklen_t len, uint_t align, void **databufp) ;
//Returns: updated length of overall extension header after adding option, -1 on error
int inet6_opt_finish(void *extbuf, socklen_t extlen, int offset) ;
//Returns: updated length of finished extension header, –1 on error
int inet6_opt_set_val(void *databuf, int offset, const void *val, socklen_t vallen) ;
//Returns: new offset inside databuf



