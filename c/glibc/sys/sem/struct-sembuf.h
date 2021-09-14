/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */


struct sembuf
{
	unsigned short int sem_num;	/* semaphore number */
	short int sem_op;		/* semaphore operation */
	short int sem_flg;		/* operation flag */
};


