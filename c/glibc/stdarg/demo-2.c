/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
#include <stdarg.h>
#include <stdio.h>

#define __str __FILE__ 

#define print(fmt, ...) \
	fprintf(stderr, "[rongtao]"__str fmt, ##__VA_ARGS__)


struct A {
#define MAGIC	0xff11
	int magic;
	int id;
};

void va_struct(int n, ...)
{
	va_list va;
	va_start(va, n);
	struct A a;
	while(n--)
	{
		a = va_arg(va, struct A);
		printf("magic: %d, id: %d\n", a.magic, a.id);
	}
	va_end(va);
}

int main()
{
	print("rong %s\n", "tao, hello world");
	print("asdfadsf\n");

	struct A a = {MAGIC, 12}, b = {MAGIC, 11};
	va_struct(2, a, b);

}
