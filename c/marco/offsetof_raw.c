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
#include <stdlib.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#define STRLEN	32
#ifndef __packed
#define __packed __attribute__((packed))
#endif

struct father{
	int money;
	char firstname[STRLEN];
}__packed;

struct son{
	struct father father;
	char lastname[STRLEN];
}__packed;

int main()
{
	struct son son[] = {
		{
			.father.money = 10000,
			.father.firstname = {"Jone"},
			.lastname = {"lennon"},
		},
		{
			.father.money = 20000,
			.father.firstname = {"Jone"},
			.lastname = {"Tao"},
		},
	};

	printf("sizeof: %d\n", sizeof(son));

	printf("offsetof: %d\n", offsetof(typeof(struct son), father.firstname[3]));
	printf("offsetof: %d\n", offsetof(struct son, father.firstname[2]));

	printf("I'm %s %s\n", son[1].father.firstname, son[1].lastname);

	

}
