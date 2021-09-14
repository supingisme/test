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

#include "init.h"

struct person_t person[];

struct person_t grp[2][3];

void init(){}

struct person_t person[] = {
		{"rongtao", 18},
		{"lihaiqiang", 18},
	};

struct person_t grp[2][3] = {
		{{"rt1", 1},{"rt2", 2},},
		{{"rt3", 3},{"rt4", 4},},
	};


int main()
{
	init();

	printf("person: %s, %d\n", person[1].name, person[1].age);

	printf("grp[0][0]: %s:%d\n", grp[0][0].name, grp[0][0].age);

	printf("grp[0][1]: %s:%d\n", grp[0][1].name, grp[0][1].age);

	printf("grp[1][0]: %s:%d\n", grp[1][0].name, grp[1][0].age);

	return 0;
}
