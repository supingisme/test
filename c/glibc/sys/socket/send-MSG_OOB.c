#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//4 * Out-of-Band 紧急的数据需要 quickly 发送的数据,忽略 流控制 和 拥塞问题，高优先级
//5 * in-band 正常的 normal 数据


int main(int argc, const char *argv[])
{
    if (argc <= 2) 
    {
        printf("Usage: %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }
    const char *ip = argv[1];
    int port       = atoi(argv[2]);

    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family =  AF_INET;
    inet_pton(AF_INET, ip, &server_address.sin_addr);
    server_address.sin_port = htons(port);

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(sockfd >= 0);

    if (connect(sockfd, (struct sockaddr *)&server_address, 
                sizeof(server_address)) < 0)
    {
        printf("connection failed\n");
    }
    else
    {
        const char *oob_data = "abc";
        const char *normal_data = "123";

        //Out-of-Band 紧急的数据需要 quickly 发送的数据,忽略 流控制 和 拥塞问题，高优先级
        send(sockfd, normal_data, strlen(normal_data), 0);
        send(sockfd, oob_data, strlen(oob_data), MSG_OOB);
        /* send(sockfd, normal_data, strlen(normal_data), 0); */
    }
    
    close(sockfd);

    return 0;
}

