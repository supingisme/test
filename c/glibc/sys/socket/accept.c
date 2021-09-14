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
 *`16.9.3 Accepting Connections
 When a server receives a connection request, it can complete the connection by accepting
 the request. Use the function accept to do this.
 A socket that has been established as a server can accept connection requests from
 multiple clients. The server’s original socket does not become part of the connection; instead,
 accept makes a new socket which participates in the connection. accept returns the
 descriptor for this socket. The server’s original socket remains available for listening for
 further connection requests.
 The number of pending connection requests on a server socket is fnite. If connection
 requests arrive from clients faster than the server can act upon them, the queue can fll
 up and additional requests are refused with an ECONNREFUSED error. You can specify the
 maximum length of this queue as an argument to the listen function, although the system
 may also impose its own internal limit on the length of this queue.
 int accept (int socket, struct sockaddr *addr, socklen t *length_ptr) [Function]
 This function is used to accept a connection request on the server socket socket.
 The accept function waits if there are no connections pending, unless the socket
 socket has nonblocking mode set. (You can use select to wait for a pending connec
 tion, with a nonblocking socket.) See Section 13.14 [File Status Flags], page 333, for
 information about nonblocking mode.
 The addr and length-ptr arguments are used to return information about the name
 of the client socket that initiated the connection. See Section 16.3 [Socket Addresses],
 page 391, for information about the format of the information.
 Accepting a connection does not make socket part of the connection. Instead, it
 creates a new socket which becomes connected. The normal return value of accept
 is the fle descriptor for the new socket.
 After accept, the original socket socket remains open and unconnected, and continues
 listening until you close it. You can accept further connections with socket by calling
 accept again.
 If an error occurs, accept returns -1. The following errno error conditions are defned
 for this function:
 EBADF The socket argument is not a valid fle descriptor.
 ENOTSOCK The descriptor socket argument is not a socket.
 EOPNOTSUPP
 The descriptor socket does not support this operation.
 EWOULDBLOCK
 socket has nonblocking mode set, and there are no pending connections
 immediately available.
 This function is defned as a cancellation point in multi-threaded programs, so one
 has to be prepared for this and make sure that allocated resources (like memory, fles
 descriptors, semaphores or whatever) are freed even if the thread is canceled.
 The accept function is not allowed for sockets using connectionless communication
 styles.
 *
 *
 * 接收连接函数
 * int accept(int s, struct sockaddr *addr, int *addrlen);
 * 	s: 处于监听状态的socket
 * 	addr 一个sockaddr结构体指针
 * 	addrlen：是sockaddr的内存长度
 *
 * 当accept函数就收一个连接时，或返回一个新的socket编号，以后的数据传输与读取
 * 就是通过这个新的socket编号来处理，原理参数中的socket可以继续使用，接收
 * 连接收，远程主机的地址和端口信息将会保存到addr所指向的结构体内，如果处理
 * 失败，返回-1.
 * 函数可能产生如下的错误：
 * 		EBADF：参数s不是一个合法的socket代码
 * 		EFAULT：参数uaddr指针西乡无法存取的内存
 * 		ENOTSOCK：参数s为一文件描述词，不是socket
 * 		EOPNOTSUPP：指定的socket不是SOCK_STREAM
 * 		EPERM：防火墙拒绝这个链接
 * 		ENOMEN：核心内存不足
 * 头文件
 * #include <sys/type.h>
 * #include <sys/socket.h>
 *
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 5678
#define MAX 10

int main()
{
	int sockfd, newsockfd, is_connected[MAX], fd;

	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	fd_set myreadfds;

	char msgbuffer[256];

	char msg[] = "This is the message from server.Connection\n";

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket: ");
		exit(1);
	}
	else
	{
		printf("socket created\nsocket id: %d\n", sockfd);
	}

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	/*绑定端口号*/
	if(bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("connect");
		exit(1);
	}
	else
	{
		printf("connected\nlocal port: %d\n", PORT);
	}

	/*监听一个端口号*/
	if(listen(sockfd, 3) < 0)
	{
		perror("listen");
		exit(1);
	}
	else
	{
		printf("listenning\n");
	}

	/*接收一个连接*/
	//这是服务器的API函数
	//所以说只运行这个函数不行，需要从客户端的端口获取消息才行
	if((newsockfd = accept(sockfd, (struct sockaddr *)&addr, &addr_len)) < 0)
	{
		perror("accept: ");
		exit(1);
	}
	else
	{
		printf("accept a new connection\n");
	}
	
	exit(0);
}
