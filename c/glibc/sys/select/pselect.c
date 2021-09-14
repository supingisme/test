/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
#include <sys/select.h>
#include <signal.h>
#include <time.h>

int pselect(int maxfdp1,
			fd_set *readset,
			fd_set *writeset,
			fd_set exceptset,
			const struct timespec *timeout,
			const sigset_t *sigmask);

/**
 *	pselect对于select有两个变化：
 *
 *	1.pselect使用timespec结构，而不是timeval结构。
 *		timespec结构是POSIX的有一个发明。
 *			
 *			struct timespec{
 *				time_t tv_sec; //seconds
 *				long tv_nsec;	//nanoseconds
 *			}
 *
 *		这两个结构区别在于第二个成员，新结构的成员tv_nsec指定纳秒数，
 *		而旧结构的该成员是微秒。
 *
 *	2.pselect函数组鞥加了第六个参数：一个执行信号掩码的指针。
 *		该参数允许程序员先禁止递交某些信号，在测试由这些当前被禁止信号的
 *		信号处理函数设置的全局变量，然后调用pselect，高速它重新设置信号掩码。
 *
 *
 *
 */
