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
/**
 *  2018.08 rt
 */
#include <sys/select.h>
#include <sys/time.h>

//select最大描述符数：应该是1024，但是没有程序员用到这么多
#ifndef FD_SETSIZE
#define FD_SETSIZE 256
#endif


int select(int maxfdp1,
			fd_set *readset,
			fd_set *writeset,
			fd_set *exceptset,
			const struct timeval *timeout);

/** 百度百科 **
 *
 * 	select的机制中提出fd_set数据结构（实际上就是long数组），每个数组元素
 * 	都能与一打开的文件句柄（不管是socket韩式其他文件或管道或设备句柄）建立
 * 	联系，建立联系的工作由程序员完成，当调用select()函数时，由内核根据IO状态
 * 	修改fd_set的内容，由此来通知执行了select函数的进程哪一个socket或文件可读
 * 	可写。select主要用于socket通信中。
 *
 * 	select：
 * 		主要用于：socket通信
 * 		特点：能监视我们需要的文件描述变化；
 * 		实质：long类型的数组。
 *
 */

/**
 *	select函数允许进程只是内核等待多个事件中的任何一个发生，
 *	并只在有一个或多个事件发生或经理一段指定的时间后才唤醒他。
 *	调用select告知内核对那些描述符（读、写、异常）感兴趣以及
 *	等待多长时间。我们感兴趣的描述符不局限于套接字，任何描述符
 *	都可以使用select来测试。
 *
 *	timeout：告知内核等待所指定描述符中的任何一个就绪话多长时间。
 *			timeout结构如下：
 *				struct timeval{
 *					long tv_sec;	//seconds
 *					long tv_usec;	//microseconds
 *				}
 *			这个参数有以下可能：
 *				1：永远等待；
 *				2：等待一段固定时间；
 *				3：根本不等待。
 *	readset\writeset\exceptset:
 *		这三个参数要让内核测试读、写、异常条件的描述符。
 *		目前支持的异常条件有两个：
 *			1：某个套接字的带外数据的到达；
 *			2：某个已置为分组模式的伪终端存在可从其主端读取的控制状态信息。
 *
 *	void FD_ZERO(fd_set &fdset); //清除所有字节为0
 *	void FD_SET(int fd, fd_set *fdset); //打开fdset中的字节fd
 *	void FD_CLR(int fd, fd_set *fdset); //关闭fdset中的字节fd
 *	void FD_ISSET(int fd, fd_set *fdset); //
 */

/**
 *	以下代码用于定义一个fd_set类型的比那辆，然后打开描述符1、4、5的对应位
 */
fd_set rset;
FD_ZERO(&rset);	//初始化
FD_SET(1, &rset);
FD_SET(4, &rset);
FD_SET(5, &rset);
