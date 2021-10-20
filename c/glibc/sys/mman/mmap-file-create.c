/**
 *	创建一个映射文件
 *	荣涛 2021年10月20日
 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#if 1
#define MMAP_FILE_NAME	"test.dat.out"
#else
#define MMAP_FILE_NAME	(char*)0x12345678
#endif
#define MMAP_FILE_SIZE	64

int fd = -1;

void sig_handler(int signum)
{
	close(fd);
	unlink(MMAP_FILE_NAME);
	exit(0);
}

int main()
{
	int i = 0;
	void *mmap_file = NULL;
	signal(SIGINT, sig_handler);

#if 1
	i = 10;
	while(i--) {
		char *mmap_file_name = mmap(NULL, sizeof(MMAP_FILE_NAME)+1, PROT_WRITE|PROT_READ, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
		perror("mmap");
		strcpy(mmap_file_name, MMAP_FILE_NAME);
	}
#endif
	fd = open(MMAP_FILE_NAME, O_RDWR|O_CREAT|O_TRUNC, 0644);
	ftruncate(fd, MMAP_FILE_SIZE);
	mmap_file = mmap(NULL, MMAP_FILE_SIZE, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);

	while(1) {
		int j;
		int *p = (int *)mmap_file;
		for(j=0; j<MMAP_FILE_SIZE/sizeof(int); j++)
			p[j] = i++;
		sleep(1);
	}
	return 0;
}
