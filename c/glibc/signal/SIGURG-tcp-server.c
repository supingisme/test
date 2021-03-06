#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

#define BUF_SIZE  1024

static int connfd;

/*SIGURG信号的处理函数 kill -23 182416 */
void sig_urg(int sig)
{
    fprintf(stdout, "sig_urg function\n");
    int save_errno = errno;
    char buffer[BUF_SIZE];
    memset(buffer, '\0', BUF_SIZE);
    int ret = recv(connfd, buffer, BUF_SIZE - 1, MSG_OOB); /*receive out of band data*/
    fprintf(stdout, "got %d bytes of oob '%s'\n", ret, buffer);
    errno = save_errno;
}

void addsig(int sig, void (*sig_handler)(int))
{
    fprintf(stdout, "addsig function\n");
    struct sigaction sa;
    memset(&sa, '\0', sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags   |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig, &sa, NULL) != -1);
}

int main(int argc, char *argv[])
{
    if (argc <= 2) 
    {
        fprintf(stderr, "usage: %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }
    const char *ip = argv[1];
    int port       = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    int ret = bind(sock, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sock, 5);
    assert(ret != -1);

    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);
    connfd = accept(sock, (struct sockaddr *)&client, &client_addrlength);
    if (connfd < 0) 
    {
        fprintf(stderr, "accept error, errno is: %d\n", errno);
    }
    else
    {
//        kill -23 182416
//        MSG_OOB     = 0x01, /* Process out-of-band data.  */
//#define MSG_OOB		MSG_OOB
//        //4 * Out-of-Band 紧急的数据需要 quickly 发送的数据,忽略 流控制 和 拥塞问题，高优先级
//        //5 * in-band 正常的 normal 数据

        addsig(SIGURG, sig_urg);
        /* 使用SIGURG信號之前，我们必须设置socket的宿主进程或进程组*/
        fcntl(connfd, F_SETOWN, getpid());

        char buffer[BUF_SIZE];
        while(1)
        {
            memset(buffer, '\0', BUF_SIZE);
            ret = recv(connfd, buffer, BUF_SIZE - 1, 0);
            if (ret <= 0) 
            {
                break;
            }
            fprintf(stdout, "got %d bytes of normal data '%s'\n", ret, buffer);
        }
        close(connfd);
    }
    close(sock);
    return 0;
}
