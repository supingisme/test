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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
/**
 *	enum
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
	SYS_ERR = -1,
	POIN_NULL_ERR = -7,
	PARA_OVER_ERR = -8,
	SYS_UNUSUAL = -9,
	BUSS_UNUSUAL = -10,
	PPU_LOAD_TIME_OUT = -11,
	PPU_NO_EXE_FILE = -12,
	PPU_DISK_NO_SPACE = -13,
	PPU_SEGM_FAULT = -14,
	CLOSE_PPU_FAILED = -15,
	DELETE_PPU_FILE_FILED = -16,
	SEND_MSG_FAILED = -17,
	APPLY_MEMORY_FAILED = -18
	//TODO:
	
}error_type;

typedef enum
{
	a = -4,
	b,
	c = 5,
	d = -2,
	e = -3,
	f = -4,
	g = -5

}A;

typedef struct 
{
	A a;
}B;

int main()
{
	printf("%d, %d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f, g);

	B b;
	b.a = a;
	
	printf("%d\n", b.a);
	
	return 1;
}
