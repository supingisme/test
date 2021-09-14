/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:40 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:23 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
#include <stdio.h>
#include <stdlib.h>

struct mac {
	int pid;
	int sockfd;
};

struct phy {
	int pid;
	int sockfd;
};

typedef struct {
	int id;
	struct mac mac;
	struct phy phy;
}cell_t;

typedef struct {
	int id;
	const struct mac const *mac;
}msg_t;

void test_msg(msg_t *msg)
{
	printf("%d, %d, %d\n", msg->id, msg->mac->pid, msg->mac->sockfd);
	//msg->mac->pid = 12;
}

int main()
{
	cell_t cell[] = {
		{1, {11, 11}, {12, 12}},
		{2, {21, 21}, {22, 22}},
		{3, {31, 31}, {32, 32}},
	};

	msg_t msg = {
		.id = 1,
		.mac = &(cell[2].mac)
	};

	test_msg(&msg);

	return 0;
}
