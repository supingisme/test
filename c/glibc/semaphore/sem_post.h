/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */


//NAME
//sem_post - unlock a semaphore

//SYNOPSIS
#include <semaphore.h>

int sem_post(sem_t *sem);

//Link with -pthread.

//DESCRIPTION
//sem_post()  increments  (unlocks)  the semaphore pointed to by sem.  If the semaphore's value
//consequently becomes greater  than  zero,  then  another  process  or  thread  blocked  in  a
//sem_wait(3) call will be woken up and proceed to lock the semaphore.
