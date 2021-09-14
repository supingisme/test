/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */


//NAME
//semop, semtimedop - System V semaphore operations
//SYNOPSIS
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semop(int semid, struct sembuf *sops, unsigned nsops);

int semtimedop(int semid, struct sembuf *sops, unsigned nsops,
		struct timespec *timeout);

//Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

//semtimedop(): _GNU_SOURCE
				  
