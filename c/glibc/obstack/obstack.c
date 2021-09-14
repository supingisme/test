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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:10 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <obstack.h>

/*
 *In file included from obstack.c:4:0:
 obstack.c: 在函数‘main’中:
 obstack.c:10:2: 错误：‘obstack_chunk_alloc’未声明(在此函数内第一次使用)
   obstack_init(obs);
     ^
	 obstack.c:10:2: 附注：每个未声明的标识符在其出现的函数内只报告一次
	 obstack.c:10:2: 错误：‘obstack_chunk_free’未声明(在此函数内第一次使用)
	   obstack_init(obs);

 */

#define obstack_chunk_alloc malloc
#define obstack_chunk_free free

#define debug() printf("%d\n", __LINE__)



int main()
{
	//有错误，再说吧，知道有这个GNU lib内存池就行了，先这样
	//2018.11.1 荣涛
	struct obstack *obs;
	debug();
	obstack_init(obs);
	debug();
	obstack_alloc(obs, 100);
	debug();
	char *addr = malloc(20);
	debug();
	obstack_copy(obs, addr, 20);
	debug();
	obstack_free(obs, addr);
	debug();
	return 0;
}
