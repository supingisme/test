/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:40 CST. */
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
/*
 *	#pragma GCC poison
 *	Sometimes, there is an identifer that you want to remove completely from your
 *	program, and make sure that it never creeps back in. To enforce this, you can
 *	poison the identifer with this pragma. #pragma GCC poison is followed by a
 *	list of identifers to poison. If any of those identifers appears anywhere in the
 *	source after the directive, it is a hard error. For example,
 *	#pragma GCC poison printf sprintf fprintf
 *	sprintf(some_string, "hello");
 *	will produce an error.
 *	If a poisoned identifer appears as part of the expansion of a macro which was
 *	defned before the identifer was poisoned, it will not cause an error. This lets
 *	you poison an identifer without worrying about system headers defning macros
 *	that use it.
 *	For example,
 *	#define strrchr rindex
 *	#pragma GCC poison rindex
 *	strrchr(some_string, ’h’);
 *	will not produce an error.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
}Cell;

Cell cells[123];

#pragma GCC poison cells

int fun()
{
	
}

int main()
{
	#pragma GCC poison printf fun
	printf("Hello\n");
	fun();

	Cell c = {12};

	cells[0].id = 1;

	return 0;
}
