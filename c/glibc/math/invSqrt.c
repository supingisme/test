/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:14 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:25 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 09:07:09 CST. */
#include <stdio.h>

float inv_sqrt(float x)
{
	int i = *(int*)&x;
	i = 1597463007-(i>>1);
	x = *(float*)&i;
	return x;
}

int main()
{
	printf(":%f\n", inv_sqrt(0.25));
	printf(":%f\n", inv_sqrt(16));
	printf(":%f\n", inv_sqrt(1.0/144));
	printf(":%f\n", inv_sqrt(121));
}
