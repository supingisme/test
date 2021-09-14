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


int main()
{
	signal(SIGINT, sig_handler);
	
	int ret;
	uint64_t exp = 0;
	struct itimerspec t1 = {{1,0},{1,0}}, t2;

	int timerfd = timerfd_create(CLOCK_REALTIME, TFD_CLOEXEC);	//TFD_CLOEXEC, TFD_NONBLOCK
	printf("Timer FD: %d\n", timerfd);

	ret = timerfd_settime(timerfd, 0, &t1, &t2);
	printf("[%d, new]: "TFMT","TFMT"\n", ret, T(t1.it_interval), T(t1.it_value) );
	printf("[%d, old]: "TFMT","TFMT"\n", ret, T(t2.it_interval), T(t2.it_value) );

	ret = timerfd_gettime(timerfd, &t1);
	printf("[%d, get]: "TFMT","TFMT"\n", ret, T(t1.it_interval), T(t1.it_value) );

	while(1)
	{
		int n = read(timerfd, &exp, sizeof(exp));	
		
		printf("exp  =%ld\n", exp);
        close(timerfd);
        break;
	}

	return 0;
}
