#include "vos_ff_common.h"
#include "vos_ff_api.h"


int fstack_udpsocket_server(int port)
{
    int sockfd;
    
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;    
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    
    if((sockfd = ff_socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        return -1;
    }

    if(ff_bind(sockfd, (struct linux_sockaddr *)&servaddr, sizeof(servaddr))) {
        return -1;
    }
    
    return sockfd;
}


int fstack_udpsocket_client(const char *ipv4, struct sockaddr_in *servaddr, int port)
{
    int sockfd, t;
    
    bzero(servaddr, sizeof(struct sockaddr_in));
    servaddr->sin_family = AF_INET;
    servaddr->sin_port = htons(port);
    
    if((t = inet_pton(AF_INET, ipv4, &servaddr->sin_addr)) <= 0)
    {
        log_error("inet_pton error.\n");
        return -1;
    }
    if((sockfd = ff_socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        log_error("ff_socket error.\n");
        return -1;
    }
    
    return sockfd;
}


int fstack_udpsocket_sendto(int fd, void *buff, size_t buflen, struct sockaddr_in *dstaddr, socklen_t len)
{
    return ff_sendto(fd, buff, buflen, 0, (struct linux_sockaddr *)dstaddr, len);
}


int fstack_tcpsocket_server(int port)
{
    int sockfd = ff_socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd <= 0) {
        log_error("ff_socket failed, sockfd:%d\n", sockfd);
        exit(1);
    }

    struct sockaddr_in my_addr;
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = ff_bind(sockfd, (struct linux_sockaddr *)&my_addr, sizeof(my_addr));
    if (ret < 0) {
        log_error("ff_bind failed, sockfd:%d\n", sockfd);
        exit(1);
    }

     ret = ff_listen(sockfd, MAX_EVENTS);
    if (ret < 0) {
        log_error("ff_listen failed, sockfd:%d\n", sockfd);
        exit(1);
    }
}


int fstack_tcpsocket_client(const char *ipv4, struct sockaddr_in *servaddr, int port)
{
    
   	/*声明套接字和链接服务器地址*/
	int sockfd;

	/*1.创建套接字*/
	if((sockfd = ff_socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		log_error("ff_socket error\n");
		exit(1);
	}

	/*2.设置连接服务器地址结构*/
	bzero(servaddr, sizeof(struct sockaddr_in));
	servaddr->sin_family = AF_INET;
	servaddr->sin_port = htons(port);
	
	if(inet_pton(AF_INET, ipv4, &servaddr->sin_addr) < 0)
	{
		log_error("inet_pton error for %s\n", ipv4);
		exit(1);
	}
	
	/*3.发送连接服务器请求*/
	if(ff_connect(sockfd, (struct linux_sockaddr*)servaddr, sizeof(struct sockaddr_in)) < 0)
	{
		log_error("ff_connect error\n");
		exit(1);
	}	
}


