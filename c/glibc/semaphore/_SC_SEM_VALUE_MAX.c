/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("SEM_NSEMS_MAX = %ld\n", sysconf(_SC_SEM_NSEMS_MAX));
	printf("SEM_VALUE_MAX = %ld\n", sysconf(_SC_SEM_VALUE_MAX));

	return 0;
}
