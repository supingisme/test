/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 08:50:35 CST. */

#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

int shm_open(const char *name, int oflag, mode_t mode);
int shm_unlink(const char *name);
//Link with -lrt.


/* NAME
 * shm_open, shm_unlink - create/open or unlink POSIX shared memory objects
 *
 * SYNOPSIS */
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

int shm_open(const char *name, int oflag, mode_t mode);

int shm_unlink(const char *name);

/* Link with -lrt. */



