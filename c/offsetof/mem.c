/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:38 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:21 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
#include <stdio.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#ifndef __packed
#define __packed __attribute__((packed))
#endif

typedef struct {
	int pid;
	int fd;
}__packed Mac;

typedef struct {
	int id;
	Mac mac;
}__packed Cell;


Cell cells[] = {
	{
		.id = 1,
		.mac.pid = 12,
		.mac.fd = 23,
	},
	{
		.id = 2,
		.mac.pid = 45,
		.mac.fd = 56,
	},
};

#define MEM_ADDR_OF_CELL(id) (void*)(&cells[id]) 

int main(int argc, int *argv[])
{
	printf("%p\n", &(cells[1].mac));
	printf("%p\n", MEM_ADDR_OF_CELL(1)+offsetof(Cell, mac));



	return 0;
}
