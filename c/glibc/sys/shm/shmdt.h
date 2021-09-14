/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 09日 星期二 08:56:44 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 20日 星期三 08:38:34 CST. */


//NAME
//shmat, shmdt - System V shared memory operations
//SYNOPSIS
#include <sys/types.h>
#include <sys/shm.h>


//attaches -> 附上，贴上, 把...归因于，把...固定
//连接共享内存标识符为shmid的共享内存，连接成功后把共享内存区对象映射到调用进程的地址空间，随后可像本地空间一样访问
void *shmat(int shmid, const void *shmaddr, int shmflg);

//detach -> 派遣，分离，拆开，分派
//when a process is finished with a shared memory segment, it detached the segment by calling shmdt
int shmdt(const void *shmaddr);


