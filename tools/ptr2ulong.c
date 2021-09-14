/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:14:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:23 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct msghead{
	uint16_t type;
	uint16_t code;
	uint32_t len;
}__attribute__((packed))Head;

typedef struct cell {
	uint32_t	id;	
}__attribute__((packed))Cell;

typedef struct msg{
	Head	head;
	Cell	cell;
	uint64_t	aulMsg[4];
}__attribute__((packed))Msg;

int main()
{
	struct msg {int a; int b; int c; int d;};
	struct msg m = {1,2,3,4};

	Msg M = {
		.head.type = 1,
		.head.code = 2,
		.head.len  = 3,
		.cell.id   = 4,
		.aulMsg[0] = 8,
		.aulMsg[1] = 5,
		.aulMsg[2] = 6,
		.aulMsg[3] = 7,
	};

	printf("%d, %d\n", 1, htons(1));

	return 0;
}
