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

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */
#include <stdio.h>
#include <signal.h>
#include <string.h>

#define STR "127.168.200.142"

void handler(int signum)
{
	int id = signum;
	printf("handler: %d\n", id);
	alarm(1);

	int i;
	for(i=1;i<=8; i++)
	{
		printf("%3d:%16s, ", i, STR);
		if(i%4 == 0)
		{
			printf("\n");
		}
	}
}

void fun(void *arg)
{	
	int *id = (int *)arg;

	printf("id = %d\n", *id);

	signal(SIGALRM, handler);

	alarm(1);
}

#define print(i) \
	do{\
		typeof(i) _i = i; \
		printf("%d\n", _i); \
	}while(0);

int main()
{
	printf("%d\n", 3/2);

	int id = 12;
	fun(&id);
	
	print(1);
	print(2);

	alarm(1);

	{
	int i = 0;
	printf("%d\n", i);
	}
	{
	int i = 1;
	printf("%d\n", i);
	}

	while(1);

	return 0;
}
