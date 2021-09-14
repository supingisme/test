/* Copyright (C) Rong Tao @Sylincom Beijing, Tue Aug 13 16:20:41 CST 2019. */
#include <stdio.h>
#include <sys/select.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/timerfd.h>
#include <stdlib.h>
#include <stdint.h>


int timerfd_create(int clockid, int flags);
int timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
int timerfd_gettime(int fd, struct itimerspec *curr_value);

void sig_handler(int signum)
{
	printf("signal handler.\n");
	exit(0);
	return;
}

#define TFMT	"[%d,%ld]"
#define T(t)  t.tv_sec,t.tv_nsec

#define N_TIMER 3
static int timersfd[N_TIMER] = {0};

int main()
{
	signal(SIGINT, sig_handler);
	
    fd_set readtimersfd;
    FD_ZERO(&readtimersfd);
    int maxfd = 0, nready = 0;
    
	int ret, i;
	uint64_t exp = 0;
    char ch;
	struct itimerspec t1 = {{1,0},{1,0}}, t2;

    for(i=0;i<N_TIMER; i++)
    {
        timersfd[i] = timerfd_create(CLOCK_REALTIME, TFD_CLOEXEC);
        timerfd_settime(timersfd[i], 0, &t1, NULL);
        printf("timerfd = %d\n", timersfd[i]);
        FD_SET(timersfd[i], &readtimersfd);
        if(maxfd < timersfd[i])
            maxfd = timersfd[i];
    }
    printf("maxfd = %d\n", maxfd);
    
	// int timerfd = timerfd_create(CLOCK_REALTIME, TFD_CLOEXEC);	//TFD_CLOEXEC, TFD_NONBLOCK
	// printf("Timer FD: %d\n", timerfd);
	// ret = timerfd_settime(timerfd, 0, &t1, &t2);
	// printf("[%d, new]: "TFMT","TFMT"\n", ret, T(t1.it_interval), T(t1.it_value) );
	// printf("[%d, old]: "TFMT","TFMT"\n", ret, T(t2.it_interval), T(t2.it_value) );

	// ret = timerfd_gettime(timerfd, &t1);
	// printf("[%d, get]: "TFMT","TFMT"\n", ret, T(t1.it_interval), T(t1.it_value) );

    
    
    
	while(1)
	{
        fd_set allset = readtimersfd;
        static int count = 0;
        nready = select(maxfd+1, &allset, NULL, NULL, NULL);
		//int n = read(timerfd, &exp, sizeof(exp));	
        
		printf("nready = %d, count = %d\n", nready, count++);
		//printf("exp  =%ld\n", exp);
        for(i=0;i<N_TIMER; i++)
        {
            if(FD_ISSET(timersfd[i], &allset))
            {
                int n = read(timersfd[i], &exp, sizeof(exp));	
                printf("exp = %ld\n", exp);
                if(timersfd[i]==4)
                    FD_CLR(timersfd[i], &readtimersfd);
            }
        }
	}

	return 0;
}
