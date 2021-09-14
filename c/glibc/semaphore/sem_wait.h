/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */


//sem_trywait()  is  the same as sem_wait(), except that if the decrement cannot be immediately
//performed, then call returns an error (errno set to EAGAIN) instead of blocking.


#include <semaphore.h>

int sem_wait(sem_t *sem);
int sem_trywait(sem_t *sem);
int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
//Link with -pthread.
