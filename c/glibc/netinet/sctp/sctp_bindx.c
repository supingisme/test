#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/sctp.h>


int main()
{
    int sctp_socket1 = socket(PF_INET, SOCK_STREAM, IPPROTO_SCTP);

    
//    int sctp_bindx(sctp_socket1, struct sockaddr * addrs, int addrcnt, int flags);
//    TODO

    close(sctp_socket1);
}

