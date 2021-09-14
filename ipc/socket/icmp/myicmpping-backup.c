

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:14 CST. */
#include <stdio.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <errno.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>

#ifndef offsetof
#define offsetof(type, member)    ( (int) & ((type*)0) -> member )
#endif


#define ICMP_BUF_SIZE           256
#define ICMP_PKG_SIZE           86
#define ICMP_RECVBUF_SIZE       (50 * 1024)
#define ICMP_PKG_CHKSUM_OFFSET  offsetof(struct icmp, icmp_cksum)
#define ICMP_PKG_CHKSUM_SIZE    2
#define ICMP_MAGIC_ID           0xf1f2
#define ICMP_PROTO_NAME         "icmp"
#define ICMP_MAX_WAIT_TIME      1
#define ICMP_MAX_N_PKG          4

#define ICMP_LOG(fmt...)        printf(fmt)

#define IPFMT                   "%d.%d.%d.%d"
#define ipfmt(ip)               (ip) & 0xff, ((ip) >> 8) & 0xff, ((ip) >> 16) & 0xff, ((ip) >> 24) & 0xff
#define ICMP_START_FMT          "PING %s(%s): %d bytes data in ICMP packets."
#define ICMP_PING_FMT           "%d byte from %s: icmp_req=%u ttl=%d rtt=%.3f ms"
#define ICMP_END1_FMT           "\n--- ping statistics ---"
#define ICMP_END2_FMT           "%d packets transmitted, %d received, %d%% lost"




static int __nsend = 0, __nrecv = 0, __sockfd = 0;

/* functions */
int icmp_socket();
int icmp_dst_addr(const char *addrHost, struct sockaddr_in * dst_addr);
unsigned short icmp_gen_chksum(unsigned short * addr, int len);
int icmp_pkg_pack(void *buffer, int pack_no, const void *data, int data_size);
int icmp_send_pkg(int __sockfd, struct sockaddr_in * dst_addr, const void *data, int size);
int icmp_recv_pkg(int __sockfd, struct sockaddr_in * from_addr, void *recvbuf, int size);
int icmp_pkg_unpack(struct sockaddr_in * addr, char * buf, int len);
inline int icmp_get_nsend();
inline int icmp_set_nsend(int v);
inline int icmp_pp_nsend();
inline int icmp_zero_nsend();
inline int icmp_get_nrecv();
inline int icmp_set_nrecv(int v);
inline int icmp_pp_nrecv();
inline int icmp_zero_nrecv();

static void __icmp_timeval_sub(struct timeval * out, struct timeval * in);




/* alogrithm of checksum */
unsigned short icmp_gen_chksum(unsigned short * addr, int len)
{
    int             nleft   = len;
    int             sum     = 0;
    unsigned short  *w      = addr;
    unsigned short  answer  = 0;

    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }

    if (nleft == 1)
    {
        * (unsigned char *) (&answer) = *(unsigned char *)w;
        sum += answer;
    }

    sum     = (sum >> 16) + (sum & 0xffff);
    sum     += (sum >> 16);
    answer  = ~sum;
    
    return answer;
}


/* create a socke to icmp */
int icmp_socket()
{
    int sockfd;
    int size = ICMP_RECVBUF_SIZE;
    
    struct protoent * protocol  = NULL;
    
    if ((protocol = getprotobyname(ICMP_PROTO_NAME)) == NULL)
    {
        ICMP_LOG("getprotobyname error.\n\r");
        return -1;
    }
    if ((sockfd = socket(AF_INET, SOCK_RAW, protocol->p_proto)) < 0)
    {
        ICMP_LOG("socket error.\n\r");
        return -1;
    }
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size))!=0)
    {
        ICMP_LOG("setsockopt.\n\r");
        close(sockfd);
        return -1;
    }
    
    return sockfd;
}

/* get dst address */
int icmp_dst_addr(const char *addrHost, struct sockaddr_in * dst_addr)
{
    struct hostent  * host      = NULL;
    unsigned long   inaddr      = 0;

    bzero(dst_addr, sizeof(struct sockaddr_in));
    dst_addr->sin_family = AF_INET;

    if ((inaddr = inet_addr(addrHost)) == INADDR_NONE)
    {
        if ((host = gethostbyname(addrHost)) == NULL)
        {
            ICMP_LOG("gethostbyname error.\n\r");
            return (-1);
        }
        memcpy((char *) &dst_addr->sin_addr, host->h_addr, host->h_length);
    }
    else 
    {
        memcpy((char *) &dst_addr->sin_addr, (char *) &inaddr, sizeof(dst_addr->sin_addr));
    }

    ICMP_LOG(ICMP_START_FMT"\n\r", addrHost, inet_ntoa(dst_addr->sin_addr), ICMP_PKG_SIZE);
    
    return 0;
}


/* set icmp hdr */
int icmp_pkg_pack(void *buffer, int pack_no, const void *data, int data_size)
{
    int i, packsize = 0;

    struct icmp * icmp  = malloc(sizeof(struct icmp));
    icmp->icmp_type     = ICMP_ECHO;
    icmp->icmp_code     = 0;
    icmp->icmp_cksum    = 0;
    icmp->icmp_seq      = htons(pack_no);
    icmp->icmp_id       = htons(ICMP_MAGIC_ID);

    gettimeofday((struct timeval *) &icmp->icmp_data, NULL);

    memcpy(buffer, icmp, sizeof(struct icmp));
    packsize += sizeof(struct icmp);

    if(data && data_size)
    {
        memcpy(buffer+packsize, data, data_size);
        packsize += data_size;
        
    }

    return packsize;
}



/* send icmp package */
int icmp_send_pkg(int __sockfd, struct sockaddr_in *dst_addr, const void *data, int size)
{
    int             packetsize;
    unsigned short  checksum = 0;
    int             n = 0;
    
    char pkg_buffer[ICMP_BUF_SIZE];
    
    packetsize  = icmp_pkg_pack(pkg_buffer, __nsend, data, size);
    checksum    = icmp_gen_chksum((unsigned short *)pkg_buffer, packetsize);
    
    memcpy(pkg_buffer + ICMP_PKG_CHKSUM_OFFSET, &checksum, ICMP_PKG_CHKSUM_SIZE);

    if ((n = sendto(__sockfd, pkg_buffer, packetsize, 0, 
                     (struct sockaddr *) dst_addr, sizeof(struct sockaddr_in)))< 0)
    {
        ICMP_LOG("sendto error.\n\r");
        return 0;
    }
    __nsend++;
    return n;
}


/* send icmp package */
int icmp_recv_pkg(int __sockfd, struct sockaddr_in * from_addr, void *recvbuf, int size)
{
    int         n, fromlen;
    
    
    fromlen = sizeof(struct sockaddr_in);


    if ((n = recvfrom(__sockfd, recvbuf, size, 0, 
                      (struct sockaddr *) from_addr, &fromlen)) < 0)
    {
        ICMP_LOG("recvfrom error.\n\r");
        return 0;
    }

    __nrecv++;
    
    return n;
}


/* unpack icmp pkg */
int icmp_pkg_unpack(struct sockaddr_in * addr, char * buf, int len)
{
    int     i, iphdrlen;

    struct  ip * ip = NULL;
    struct  icmp * icmp = NULL;
    struct  timeval * tvsend = NULL;
    double  rtt;

    ip          = (struct ip *)buf;
    iphdrlen    = ip->ip_hl << 2;
    icmp        = (struct icmp *) (buf + iphdrlen);
    len        -= iphdrlen;

    if (len < 8)
    {
        ICMP_LOG("ICMP packet\'s length is less than 8\n\r");
        return - 1;
    }

    /* ensure icmp reply is mine response msg */
    if ((icmp->icmp_type == ICMP_ECHOREPLY) && (icmp->icmp_id = ntohs(ICMP_MAGIC_ID)))
    {
        tvsend  = (struct timeval *)icmp->icmp_data;

        struct timeval tvrecv;
        gettimeofday(&tvrecv, NULL);
        __icmp_timeval_sub(&tvrecv, tvsend);
        rtt = tvrecv.tv_sec * 1000 + tvrecv.tv_usec / 1000;
        ICMP_LOG(ICMP_PING_FMT"\n\r", len, inet_ntoa(addr->sin_addr), ntohs(icmp->icmp_seq), ip->ip_ttl, rtt);
    }
    else 
    {
        return - 1;
    }
}


static void __icmp_timeval_sub(struct timeval * out, struct timeval * in)
{
    if ((out->tv_usec -= in->tv_usec) < 0)
    {
        --out->tv_sec;
        out->tv_usec += 1000000;
    }
    out->tv_sec -= in->tv_sec;
}
inline int icmp_get_nsend()     {return __nsend;}
inline int icmp_set_nsend(int v){__nsend = v;return __nsend;}
inline int icmp_pp_nsend()      {return ++__nsend;}
inline int icmp_zero_nsend()    {__nsend = 0;return __nsend;}
inline int icmp_get_nrecv()     {return __nrecv;}
inline int icmp_set_nrecv(int v){__nrecv = v;return __nrecv;}
inline int icmp_pp_nrecv()      {return ++__nrecv;}
inline int icmp_zero_nrecv()    {__nrecv = 0;return __nrecv;}


/**********************************************************************************************************************/
/* icmp ping with alarm */
/* signal callback */
static void icmp_sig_handler(int signo)
{
    switch(signo)
    {
        case SIGALRM:
        case SIGINT:
            ICMP_LOG(ICMP_END1_FMT"\n\r");
            ICMP_LOG(ICMP_END2_FMT"\n\r", 
                    __nsend, __nrecv, (__nsend - __nrecv) / __nsend * 100);
            //close(sockfd);
            break;
            
        default:
            break;
    }
    
    exit(1);
}

void icmpping1(const char *ipv4)
{
    
    struct sockaddr_in dest_addr;
    struct sockaddr_in from_addr;
    
    signal(SIGALRM, icmp_sig_handler);
    signal(SIGINT, icmp_sig_handler);
    
    int sockfd = icmp_socket();
    icmp_dst_addr(ipv4, &dest_addr);

    char pkg_buffer[ICMP_BUF_SIZE];
    char __data[] = {"Rong Tao's ICMP Ping"};

    while(__nsend < ICMP_MAX_N_PKG)
    {
        int tx = icmp_send_pkg(sockfd, &dest_addr, __data, sizeof(__data));
        int rx = icmp_recv_pkg(sockfd, &from_addr, pkg_buffer, tx);
        
        alarm(ICMP_MAX_WAIT_TIME*ICMP_MAX_N_PKG);
        
        if (icmp_pkg_unpack(&from_addr, pkg_buffer, rx) == -1)
            continue;
        sleep(1);
    }
    
    close(sockfd);
    
    raise(SIGALRM);
}

/**********************************************************************************************************************/
/* type of icmp ping */
typedef struct __icmp_ping_s {
    int sockfd;
    int timerfd;
    struct sockaddr_in dst_addr;
    int ntx, nrx;   //number of send pkg and recv pkg
    void *recv_buf, *send_buf;
    int timeout_s;  //time out second
}icmp_ping_t;

/* icmp ping with timeout */
static void * __icmpping_timeout_cb(void *arg)
{
    icmp_ping_t *_icmp_ping = (icmp_ping_t*)arg;
    unsigned int timeout_s = _icmp_ping->timeout_s;
    uint64_t exp = 0;
    printf("timeout_s=%d\n", timeout_s);
	struct itimerspec t1 = {{timeout_s,0},{timeout_s,0}}, t2;
    
    int ret = timerfd_settime(_icmp_ping->timerfd, 0, &t1, &t2);
    while(1)
	{
		int n = read(_icmp_ping->timerfd, &exp, sizeof(exp));	
		//printf("exp  =%ld\n", exp);
		ICMP_LOG(ICMP_END1_FMT"\n\r");
        ICMP_LOG(ICMP_END2_FMT"\n\r", 
                __nsend, __nrecv, (__nsend - __nrecv) / __nsend * 100);
        close(_icmp_ping->timerfd);
        break;
	}
    return NULL;
}
void icmpping2(const char *ipv4, unsigned int timeout)
{
    static icmp_ping_t icmp_ping;
    memset(&icmp_ping, 0x00, sizeof(icmp_ping_t));

    icmp_ping.sockfd    = icmp_socket();
    icmp_ping.timeout_s = timeout;
    icmp_ping.timerfd = timerfd_create(CLOCK_REALTIME, TFD_CLOEXEC);
    
    
    pthread_t __icmpping_thread_id;
    
pthread_create(&__icmpping_thread_id, NULL, __icmpping_timeout_cb, &icmp_ping);
    printf("pthreadid = %d\n", __icmpping_thread_id);

    struct sockaddr_in dest_addr;
    struct sockaddr_in from_addr;
    
    icmp_dst_addr(ipv4, &dest_addr);

    char pkg_buffer[ICMP_BUF_SIZE];
    char __data[] = {"Rong Tao's ICMP Ping"};

    while(icmp_ping.ntx < ICMP_MAX_N_PKG)
    {
        int tx = icmp_send_pkg(icmp_ping.sockfd, &dest_addr, __data, sizeof(__data));
        int rx = icmp_recv_pkg(icmp_ping.sockfd, &from_addr, pkg_buffer, tx);
        
        if (icmp_pkg_unpack(&from_addr, pkg_buffer, rx) == -1)
            continue;
        sleep(1);
    }
    close(icmp_ping.sockfd);
}


int main(int argc, char * argv[])
{

    if (argc < 2)
    {
        ICMP_LOG("Usage: %s hostname/IP address\n\r", argv[0]);
        return (-1);
    }
    //icmpping1(argv[1]);
    icmpping2(argv[1], 4);

    
    
    return 0;
}


