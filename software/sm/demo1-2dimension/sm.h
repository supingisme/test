/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 14:07:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 11:02:48 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:12 CST. 
*/
#ifndef _SM_H
#define _SM_H 1

#define SM_DIMENSION 3

typedef int (*sm_handler_t)(int id, void *arg);



struct sm_hdr_t {
	int state0;
	int state1;
	int state2;
	int event;
}__attribute__((packed));

struct sm_node_t {
	struct sm_hdr_t hdr;
	sm_handler_t handler;
}__attribute__((packed));


void show_sm();

#endif //_SM_H
