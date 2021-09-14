/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 09日 星期二 08:56:44 CST. */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SVSHM_MODE (SHM_R|SHM_W|SHM_R>>3|SHM_R>>6)

int main(int argc, char *argv[])
{
	int c, id, oflag;
	char *ptr;
	size_t length;

	if(argc < 2)
	{
		printf("Usage: %s <pathname>\n", argv[0]);
		return -1;
	}

	oflag = SVSHM_MODE | IPC_CREAT ;
	//IPC_CREAT: 不管是否已存在的共享内存块，都返回该共享内存的ID，不存在则创建
	//IPC_EXCL: 当只有IPC_EXCL选项打开，不管有没有该共享内存块，shmget都返回-1
	printf("oflag = %x\n", oflag);	

	length = 12;//128*1024*1024;

	id = shmget(ftok(argv[1], 0), length, oflag);
	printf("id = %d, file = %s, errno = %d ->%s\n", id, argv[1], errno, strerror(errno));
	
	ptr = shmat(id, NULL, 0);
	

	exit(0);
}
