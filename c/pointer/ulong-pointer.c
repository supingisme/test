/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:39 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>

struct Msg{
	uint16_t src;
	uint16_t dst;
	uint32_t code;
	int32_t  rslt;
};


int main()
{
	unsigned long ul[4], ulm[4];

	char *str = malloc(256);

	strcpy(str, "hello");

	ul[0] = 1;
	ul[1] = 0;
	ul[2] = 0;
	ul[3] = (unsigned long )str;

	
	struct Msg msg = {
		.src = 1,
		.dst = 2,
		.code = 3,
		.rslt = 0,
	};

	ul[4] = (unsigned long)(&msg);

	printf("%s\n", ul[3]);

	struct Msg msgdc;
	memcpy(&msgdc, (struct Msg*)ul[4], sizeof(struct Msg));

	printf("msg: %d, %d, %d, %d\n", msgdc.src, msgdc.dst, msgdc.code, msgdc.rslt);

	return 0;
}
