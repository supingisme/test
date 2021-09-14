/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:39 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:23 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
#include <stdio.h>

void cb(char *s)
{
	static int a = 2;
	printf("s: %s:%d\n", s, a);
	a++;
}

#define __called_once \
	do{ \
		static int call_times =  0; \
		call_times++; \
		if(call_times>1) \
		{ \
			printf("Error: Must just call \"%s\" once.\n", __func__); \
		} \
	}while(0)


void print()
{
	__called_once;

	printf("%s:%d\n", __func__, __LINE__);
}

int main()
{
	//fun("rong", "tao");
	//fun("lala", "roor");

	cb("1");
	cb("2");
	cb("3");

	print();
	print();

	return 0;
}
