/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:29 CST. */
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
 * 函数通过已经建立的套接字，讲一段信息发送到另一个程序
 * 的套接字中，使用方法：
 * int  sendto(
 * 				int s,	//s是已经建立好的socket
 * 				void *msg, //需要发送的字符
 * 				int len, //发送字符串的长度
 * 				unsigned int flags,	//flags一般为0
 * 				struct sockaddr *to, //表示套接字的结构体
 * 				int tolen //
 * 				);
 */

#include <sys/socket.h>

ssize_t sendto(int sockfd, const void *buff, size_t nbytes, int flags,
				const struct sockaddr *to, socklen_t *addrlen);

ssize_t recvfrom(int sockfd, void *buff, size_t nbytes, int falgs,
				struct sockaddr *from, socklen_t *addrlen);
