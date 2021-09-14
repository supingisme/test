/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *	$ gcc name.c -lrt 
 *	$ ./a.out -e b.out 123
 */

#define FILE_MODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

int main(int argc, char *argv[])
{
	int c, fd, flags;

	char *ptr;
	off_t length;
	//struct stat stat;

	flags = O_RDWR | O_CREAT;

	while( (c = getopt(argc, argv, "e")) != -1 )
	{
		switch(c)
		{
			case 'e':
				flags |= O_EXCL;
				break;
		}
	}
	if(optind != argc - 2)
	{
		printf("usage: %s [ -e ] <name> <length>\n", argv[0]);
		exit(1);
	}
	length = atoi(argv[optind + 1]);

	fd = shm_open(argv[optind], flags, FILE_MODE);
	//fd = shm_open(argv[optind], flags, 0777);
	//fd = shm_open(argv[optind], O_RDWR|O_EXCL|O_CREAT, 0777);
	printf("fd = %d, length = %d, flags = %#04x, name = %s\n", fd, length, flags, argv[optind]);
	int ret = ftruncate(fd, length);
	printf("ftruncate return: %d\n", ret);
	//fstat(fd, &stat);
	//printf("stat.st_size = %d\n", stat.st_size);

	//close(fd);
	int i;
	//for(i=0;i<stat.st_size;i++);
	
	ptr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	/*close(fd);
	for(i=0;i<stat.st_size;i++)
	{
		*ptr = i%256;
		ptr++;
		printf("i=%d, ptr = %d\n", i, i%256);
	}*/

	return 0;
}
