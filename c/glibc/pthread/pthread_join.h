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


#include <pthread.h>

//*      一个线程可以使joinable（可汇合的，默认值），也可以是detached（脱离的），
//*  当一个可汇合的线程终止时，他的线程ID和退出状态将留存到另一个线程对它调用
//*  pthread_join。脱离的线程却像守护进程，当他们终止时，所有相关资源都被释放，
//*  我们不能等待他们终止。如果一个线程需要知道另一个线程什么时候终止，那最好
//*  保持第二个线程的可汇合状态。

int pthread_join(pthread_t *tid, void **status);
/**
 *  pthread_join 作为返回
 *
 *      荣涛 2018.10.16
 */
//int pthread_join(pthread_t *tid, void **retval);
/**
 * 参数：
 * 		tid：线程ID
 * 		status：用户定义的指针，用来存储被等待线程的返回值。
 *
 *
 *	返回：
 *		成功：0
 *		错误：正的Exxx值
 */

//Returns: 0 if OK, positive Exxx value on error
//
//Comparing threads to Unix processes, 
//pthread_create is similar to fork, and 
//pthread_join is similar to waitpid.
