/**
 * client.c 客户端代码
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "ff_config.h"
#include "ff_api.h"
#include "ff_epoll.h"

#include "common.h"


int main(int argc, char *argv[])
{
    ff_init(argc, argv);
    
   	/*声明套接字和链接服务器地址*/
	int sockfd;
	struct sockaddr_in servaddr;

	/*1.创建套接字*/
	if((sockfd = ff_socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket error");
		exit(1);
	}

	/*2.设置连接服务器地址结构*/
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	
	if(inet_pton(AF_INET, "10.170.7.169", &servaddr.sin_addr) < 0)
	{
		printf("inet_pton error for %s\n", argv[1]);
		exit(1);
	}
	
	/*3.发送连接服务器请求*/
	if(ff_connect(sockfd, (struct linux_sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("connect error");
		exit(1);
	}	

	/*4.消息处理*/
	char sendline[MAX_LINE], recvline[MAX_LINE];
	
	printf("Input: ");
	while(fgets(sendline, MAX_LINE, stdin) != NULL)
	{
		ff_write(sockfd, sendline, strlen(sendline));

		printf("Client Send: %s\n", sendline);
		
		ff_read(sockfd, recvline, MAX_LINE);
		printf("Client Recv: %s\n", recvline);

		printf("Input>>");
	}

	/*5.关闭套接字*/
	ff_close(sockfd);



	return 1; 
}

