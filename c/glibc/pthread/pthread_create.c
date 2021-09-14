/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 24日 星期一 08:52:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 09:02:19 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/**
 *	pthread_create		P535
 */

#include <pthread.h>

int pthread_create(pthread_t *tid, const pthread_attr_t *attr,
					void *(*func)(void *), void *arg);

#include <pthread.h>
#include <stdio.h>
/* Prints x's to stderr. The parameter is unused. Does not return. */
void* print_xs (void* unused)
{
	while (1)
		fputc ('x', stderr);
	return NULL;
}
/* The main program. */
int main ()
{
	pthread_t thread_id;
	/* Create a new thread. The new thread will run the print_xs
	 * function. */
	pthread_create (&thread_id, NULL, &print_xs, NULL);
	/* Print o's continuously to stderr. */
	while (1)
		fputc ('o', stderr);
	return 0;
}
