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
 *
 */

#include <pthread.h>

/**
 *	To handle the possibility of being canceled, any thread can install (push) and
 *	remove (pop) cleanup handlers.
 *
 *	These handlers are just fundions that are called
 *	1.when the thread is canceled (by some thread calling pthread-cancel), or
 *	2.when the thread voluntarily terminates (either by calling pthread-exit or
 *		returning from its thread start function).
 *
 *	类似于进程中使用的signal
 */
//推和弹出线程取消清理处理程序
//int pthread_cleanup_push(void (*function)(void *), void *arg);
//
//void pthread_cleanup_pop(int execute);


#include <malloc.h>
#include <pthread.h>
/* Allocate a temporary buffer. */
void* allocate_buffer (size_t size)
{
    printf("allocate_buffer.\n");
	return malloc (size);
}
/* Deallocate a temporary buffer. */
void deallocate_buffer (void* buffer)
{
    printf("deallocate_buffer.\n");
	free (buffer);
}
void do_some_work ()
{
	/* Allocate a temporary buffer. */
	void* temp_buffer = allocate_buffer (1024);
	/* Register a cleanup handler for this buffer, to deallocate it in
	 * case the thread exits or is cancelled. */
	pthread_cleanup_push (deallocate_buffer, temp_buffer);
	/* Do some work here that might call pthread_exit or might be
	 * cancelled... */
	/* Unregister the cleanup handler. Because we pass a nonzero value,
	 * this actually performs the cleanup by calling
	 * deallocate_buffer. */
	pthread_cleanup_pop (1);
    
//    int status = 1;
//    pthread_exit(&status);
}

int main()
{
    do_some_work ();
}
