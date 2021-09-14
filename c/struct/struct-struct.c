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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:24 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
#include <stdio.h>
#include <stdint.h>

struct cell{
	int8_t id;
	struct {
		int8_t a;
		int8_t b;
	}__attribute__((packed))mac[2], phy;
}__attribute__((packed));

struct rru {
	struct rru *rru;
	//struct rru rru;//error: 错误：字段‘rru’的类型不完全
};

int main()
{
	struct cell cell[] ={ {
		.id = 1,
		.mac[1].a = 2,
		.mac[0].b = 3,
		.phy.b = 9,
	}};
	
	printf("cell(%d): %d, %d, %d\n", sizeof(cell),cell[0].mac[1].a, cell[0].mac[0].b,
			cell[0].phy.b);

	return 0;
}
