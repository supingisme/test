/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */


#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
void print_cpu_time()
{
	struct rusage usage;
	getrusage (RUSAGE_SELF, &usage);
	printf ("CPU time: %ld.%06ld sec user, %ld.%06ld sec system\n",
			usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
			usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
}

int main()
{
	print_cpu_time();
	return 0;
}
