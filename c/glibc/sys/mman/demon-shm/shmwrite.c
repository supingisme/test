/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, fd;
	struct stat stat;
	unsigned char *ptr;

	if(argc != 2)
	{
		printf("usage: %s <name>\n", argv[0]);
		exit(0);
	}
	fd = shm_open(argv[1], O_RDWR|O_CREAT, S_IWUSR|S_IWOTH);
	printf("fd = %d\n", fd);
	
	fstat(fd, &stat);
	printf("stat.st_size = %d\n", stat.st_size);
	ptr = mmap(NULL, stat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);

	for(i=0;i<stat.st_size;i++)
		*ptr++ = i%256;

	return 0;
}
