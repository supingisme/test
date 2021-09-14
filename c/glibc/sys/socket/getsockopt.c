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
 * int getsockopt(	int s, 		//已经建立的socket的编号
 * 					int level,	//需要设置的网络层
 * 					int optname,//需要获取的选项
 * 					void *optval,	//取得的某个参数的返回值指针
 * 					socklen_t *optlen	//optval的内存长度
 * 				);
 * 	函数执行成功返回1，否则返回-1
 * 	需要包含头文件
 * 	sys/socket.h
 * 	sys/types.h
 *	
 *
 *	16.12 Socket Options
 *	This section describes how to read or set various options that modify the behavior of sockets
 *	and their underlying communications protocols.
 *	When you are manipulating a socket option, you must specify which level the option
 *	pertains to. This describes whether the option applies to the socket interface, or to a
 *	lower-level communications protocol interface.
 *	16.12.1 Socket Option Functions
 *	Here are the functions for examining and modifying socket options. They are declared in
 *	‘sys/socket.h’.
 *	int getsockopt (int socket, int level, int optname, void *optval, [Function]
 *	socklen t *optlen-ptr)
 *	The getsockopt function gets information about the value of option optname at level
 *	level for socket socket.
 *
 *	The option value is stored in a buﬀer that optval points to. Before the call, you should
 *	supply in *optlen-ptr the size of this buﬀer; on return, it contains the number of
 *	bytes of information actually stored in the buﬀer.
 *	Most options interpret the optval buﬀer as a single int value.
 *	The actual return value of getsockopt is 0 on success and -1 on failure. The following
 *	errno error conditions are defned:
 *	EBADF The socket argument is not a valid fle descriptor.
 *	ENOTSOCK The descriptor socket is not a socket.
 *	ENOPROTOOPT
 *	The optname doesn’t make sense for the given level.
 */
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void demo1()
{
    int s;	
	int val, len;
	len = sizeof(int);

	if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("connect");	
		exit(1);
	}
	else
	{
		printf("a socket was create.\n");
		printf("socket number is: %d\n", s);
	}

	//#define SO_SNDBUF	7
	//#define SO_RCVBUF	8
	getsockopt(s, SOL_SOCKET, SO_SNDBUF, &val, &len);
	perror("socket:");
	printf("optval = %d\n", val);
	printf("optlen = %d\n", len);

	/*用错误的方法取得一个信息*/
	getsockopt(100, SOL_SOCKET, SO_TYPE, &val, &len);
	perror("socket:");
	printf("optval = %d\n", val);
	printf("optlen = %d\n", len);
}

void error_handling(const char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);

    exit(1);
}

void demo2()
{
    int sock;
    int send_buf,recv_buf,state;
    socklen_t buf_len;

    buf_len = sizeof(send_buf);
    sock = socket(PF_INET, SOCK_STREAM, 0);
    state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, &send_buf, &buf_len);
    if(state)
        error_handling("getsockopt() error!");
    printf("SO_SNDBUF: %d %d \n", send_buf, buf_len);

    sock = socket(PF_INET, SOCK_STREAM, 0);
    state = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &recv_buf, &buf_len);
    if(state)
        error_handling("getsockopt() error!");
    printf("SO_RCVBUF: %d %d \n", recv_buf, buf_len);    
    
}

int main()
{
    demo1();
    printf("----------------\n");
    demo2();
}
