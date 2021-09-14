/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <name>\n", argv[0]);
		exit(0);
	}

	int ret = shm_unlink(argv[1]);
	printf("ret = %d\n", ret);
	return 0;
}
