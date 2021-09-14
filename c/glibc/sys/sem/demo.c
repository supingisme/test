/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>

int main(int argc, char *argv[])
{
	int semid;

	if(argc != 2)
	{
		printf("usage: %s <pathname>\n", argv[0]);
		exit(1);
	}

	semid = semget(ftok(argv[1], 0), 0, 0);

	printf("semid = %d\n", semid);
	
	semctl(semid, 0, IPC_RMID);

	printf("semid = %d\n", semid);

	return 0;
}	
