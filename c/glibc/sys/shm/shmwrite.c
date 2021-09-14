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

/**
 *	$ ./write.out b.out
 *	oflag = 3a4
 *	id = 98306, file = b.out, errno = 0 ->Success
 *	shmctl: ret = 0, errno = 0 -> Success
 *	$ ./read.out b.out
 *	oflag = 1a4
 *	id = 98306, file = b.out, errno = 0 ->Success
 *	shmctl: ret = 0, errno = 0 -> Success
 *	ch = 0
 *	ch = 1
 *	ch = 2
 *	ch = 3
 *	ch = 4
 *	ch = 5
 *	ch = 6
 *	ch = 7
 *	ch = 8
 *	ch = 9
 *	ch = 10
 *	ch = 11
 */

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

	length = 12;

	id = shmget(ftok(argv[1], 0), length, oflag);
	printf("id = %d, file = %s, errno = %d ->%s\n", id, argv[1], errno, strerror(errno));
	
	ptr = shmat(id, NULL, 0);

	/**
	 *	IPC_STAT: write
	 */
	//char buf[] = {"hello world"};
	struct shmid_ds buf;
	int ret = shmctl(id, IPC_STAT, &buf);
	printf("shmctl: ret = %d, errno = %d -> %s\n", ret, errno, strerror(errno));
	int i;
	for(i=0;i<buf.shm_segsz; i++)
		*ptr++ = i%256;

#if 0
	/**
	 *	IPC_RMID
	 */
	int ret = shmctl(id, IPC_RMID, NULL);
	printf("shmctl: ret = %d, errno = %d -> %s\n", ret, errno, strerror(errno));
#endif
	exit(0);
}
