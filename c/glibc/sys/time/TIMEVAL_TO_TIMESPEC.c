#define __USE_GNU //TIMEVAL_TO_TIMESPEC
#include <stdio.h>
#define __USE_GNU
#include <sys/time.h>

int main()
{
	struct timeval tv1 = {0,0}, tv2;
	struct timespec ts1 = {0,0};

	tv1.tv_sec = 12;
	tv1.tv_usec = 23;
#ifdef __USE_GNU
	TIMEVAL_TO_TIMESPEC(&tv1, &ts1);
	TIMESPEC_TO_TIMEVAL(&tv2, &ts1);
#endif
	printf("timespec: %d, %d\n", ts1.tv_sec, ts1.tv_nsec);
	printf("timespec: %d, %d\n", tv2.tv_sec, tv2.tv_usec);

	return 0;
}
