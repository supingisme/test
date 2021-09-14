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
#include <math.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#define STR_LEN	32

typedef struct {
	char firstname[STR_LEN];
	unsigned int age;
}Father;

typedef struct {
	Father rxd;
	char lastname[STR_LEN];
	unsigned int age;
}Son;

Son sons[5];

#define indexofarray(type, startAddr, endAddr) \
	(abs(((long)endAddr)-((long)startAddr))/sizeof(type))

void func(son)
Son *son;
{
	const void const *p = (void *)sons;	
	unsigned long offset = abs(((long)p)-((long)son));
	unsigned int index = offset/sizeof(Son);
	
	printf("%p\n", p);
	printf("%p\n", son);
	printf("%ld\n", offset);
	printf("%d\n", index);
	printf("%d\n", indexofarray(Son, sons, son));
}

int main()
{
	func(&sons[2]);

	return 0;
}
