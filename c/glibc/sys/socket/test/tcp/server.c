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

#include "common.h"

int main(int argc, char *argv[])
{
    /*声明服务器地址和客户连接地址*/
    struct sockaddr_in servaddr, cliaddr;
    
    /*声明服务器监听套接字和客户端连接套接字*/
    int listenfd, connfd;
    pid_t childpid;

    /*声明缓冲区*/
    char buf[MAX_LINE];
    
    socklen_t clilen;

    /*1.初始化监听套接字listenfd*/
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
		perror("socket error");
		exit(1);
    } 

    /*2.设置服务器sockaddr_in结构*/
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//可接受任意IP地址
    servaddr.sin_port = htons(PORT);

    /*3.绑定套接字和端口*/
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
		perror("bind error");
		exit(1);
    }

    /*4.监听客户请求*/
    if(listen(listenfd, LISTENQ) < 0)
    {
		perror("listen error");
		exit(1);
    }    

	char *tmp;

#define TEST_ACCEPT_RETURN_0 1
#if TEST_ACCEPT_RETURN_0
	close(0);//如果这里关闭了0（stdin），accept就会返回0值
#endif

	/* 一次性接收这个connect */
	clilen = sizeof(cliaddr);
	if((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen)) <= 0)
	{
		perror("accept error");
#if TEST_ACCEPT_RETURN_0
		printf("如果你close(0)了，那么抱歉，accept也会返回0.\n");
#endif
		exit(1);
	}
	/* else // 连接上了的话，就输出一下这个客户的地址 
	{
		inet_ntop(AF_INET, &cliaddr.sin_addr, tmp, sizeof(cliaddr.sin_addr));
		printf("cliaddr: %s\n", tmp);
	} */
		
    /*5. 接受客户请求*/
    for(;;)
    {
		//新建子进程单独处理连接
		if((childpid = fork()) == 0)
		{
	    	close(listenfd);
	    	//str_echo
	    	ssize_t n;
	    	char buf[MAX_LINE];
	    	while((n = read(connfd, buf, MAX_LINE)) > 0)
	    	{
				write(connfd, buf, n);
				printf("Server: %s\n", buf);
	    	}
	    	exit(0);
		}
		close(connfd);
    }    
    
    /*6. 关闭监听套接字*/
    close(listenfd);   

}//main
