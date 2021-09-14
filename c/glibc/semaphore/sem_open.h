/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 26日 星期二 09:02:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 09:01:52 CST. */


#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>

sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag,
                    mode_t mode, unsigned int value);

//Link with -pthread.
