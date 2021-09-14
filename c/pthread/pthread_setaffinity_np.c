/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:41 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:39 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:23 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
/*
 *	绑定线程到cpu核上运行.
 *	绑定线程到cpu核上使用pthread_setaffinity_np函数，
 *
 */
#include <stdio.h>


#define __USE_GNU
#include <sched.h>

#include <stdlib.h>
#include <errno.h>
#include <pthread.h>


int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize, const cpu_set_t *cpuset);
int pthread_getaffinity_np(pthread_t thread, size_t cpusetsize, cpu_set_t *cpuset);

#define handle_error_en(en, msg)\
    do{\
        errno = en;\
        perror(msg);\
        exit(EXIT_FAILURE);\
    }while(0)

int main()
{
    int s, j;
    cpu_set_t cpuset;
    pthread_t thread;
    
    thread = pthread_self();
    
    /*set affinity mask to include CPUs 0 to 7*/
    CPU_ZERO(&cpuset);
    
    for(j=0;j<8;j++)
    {
        CPU_SET(j, &cpuset);
    }
    
    s = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if(s != 0)
    {
        handle_error_en(s, "pthread_setaffinity_np");
    }
    
    s = pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if(s != 0)
    {
        handle_error_en(s, "pthread_getaffinity_np");
    }
    
    for(j=0;j<CPU_SETSIZE; j++)
    {
        if(CPU_ISSET(j, &cpuset))
        {
            printf("CPU_SETSIZE = %d, j = %d\n", CPU_SETSIZE, j);
        }
    }
    
	return 0;
}
