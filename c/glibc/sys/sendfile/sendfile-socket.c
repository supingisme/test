#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>
#include <netinet/in.h>
#include <fcntl.h>

struct tsk_arg{
    int fd;
    char *file;
};

int serversocket(int port)
{
    int sockServ;
    int readLen = 0;
    
    char buf[32];
    
    sockServ = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servAddr, clientAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);
    
    bind(sockServ, (struct sockaddr*)&servAddr, sizeof(servAddr));

    listen(sockServ, 5);

    return sockServ;
    
}

int serveraccept(int sockfd, struct sockaddr_in *clientAddr)
{
    int sockClient;
    socklen_t clientAddrLen = sizeof(struct sockaddr_in);
    sockClient = accept(sockfd, (struct sockaddr*)clientAddr, &clientAddrLen);
    if(sockClient == -1)
    {
        printf("accept() error!");
        return -1;
    }
    return sockClient;
}


int clientsocket(const char *ip, int port)
{
    int sockClient = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(ip);
    servAddr.sin_port = htons(port);

    if(connect(sockClient, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
    {
        printf("connect() error!");
        return -1;
    }

    return sockClient;
}

void file_open_and_send(int dstfd, const char *fileread)
{
	struct stat stat_buf;
	off_t offset = 0;
    int read_fd;
    
	/* Open the input file. */
	read_fd = open (fileread, O_RDONLY);
	/* Stat the input file to obtain its size. */
	fstat (read_fd, &stat_buf);
    
	/* Blast the bytes from one file to the other. */
	sendfile (dstfd, read_fd, &offset, stat_buf.st_size);
    close(read_fd);
}


void *task_client(void*arg)
{
    char buffer[1024];
    sleep(1);
    struct tsk_arg *ptarg = (struct tsk_arg *)arg;

    file_open_and_send(ptarg->fd, ptarg->file);
}



int main(int argc, char* argv[])
{
    if(argc<3) {
        printf("%s [file-in] [port]\n", argv[0]);
        exit(1);
    }
    
    int port = atoi(argv[2]);
    int serverfd, clientfd, connfd;
    pthread_t serverthread;

    struct sockaddr_in clientAddr;

    char buffer[1024];
    
    serverfd = serversocket(port);
    
    clientfd = clientsocket("127.0.0.1", port);

    struct tsk_arg targ = {clientfd, argv[1]};
    
    pthread_create(&serverthread, NULL, task_client, &targ);

    while(1){
        connfd = serveraccept(serverfd, &clientAddr);
        printf("accept fd = %d\n", connfd);
    
        while(1){
            read(connfd, buffer, 1);
            printf("%c", buffer[0]);
        }
    }

    return 0;
}
