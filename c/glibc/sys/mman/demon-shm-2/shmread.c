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
	unsigned char *ptr = NULL;

	if(argc != 2)
	{
		printf("usage: %s <name>\n", argv[0]);
		exit(0);
	}
	fd = shm_open(argv[1], O_RDONLY, S_IWUSR|S_IWOTH);
	printf("fd = %d\n", fd);
	
	fstat(fd, &stat);
	printf("stat.st_size = %d\n", stat.st_size);
	ptr = mmap(NULL, stat.st_size, PROT_READ, MAP_SHARED, fd, 0);
	close(fd);

	char c;
	
	for(i=0;i<stat.st_size;i++)
	{
		if(ptr)
			printf("ptr = %d\n", *ptr++);
		/*if((c = *ptr++) != (i%256))
		{
			printf("ptr[%d] = %d", i, c);
		}*/
	}

	return 0;
}
