/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:21 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>


#define __USE_GNU
#include <sched.h>
#include <ctype.h>
#include <string.h>

#define COUNT       300000
#define MILLION     1000000L
#define NANOSECOND  1000


void test_func()
{
    int i = 0;
    unsigned long long result = 0;
    
    for(i=0;i<8000;i++)
    {
        result += 2;
    }
}   

int main(int argc, char *argv[])
{
    int i;
    struct timeval sleeptm;
    long interval;
    struct timeval tend, tstart;
    struct tm lctime = {0};
    struct sched_param param;
    
    int ret = 0;
    
    if(argc != 3)
    {
        printf("Usage: %s [sched_method] [sched_priority]\n", argv[0]);
        exit(0);
    }
    
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(1, &mask);
    
    if(sched_setaffinity(0, sizeof(mask), &mask) == -1)
    {
        printf("warning: could not set cpu affinity, continuing...\n");
    }
    
    int sched_method = atoi(argv[1]);
    int sched_priority = atoi(argv[2]);
    
    if(sched_method > 2 || sched_method < 0)
    {
        printf("sched_method error\n");
        exit(0);
    }
    if(sched_priority > 99 || sched_priority < 1)
    {
        printf("sched_priority error\n");
        exit(0);
    }
    
    if(sched_method == 1 || sched_method == 2)
    {
        param.sched_priority = sched_priority;
        ret = sched_setscheduler(getpid(), sched_method, &param);
        
        if(!ret)
        {
            printf("set scheduler to %d failed.\n", sched_method);
            exit(0);
        }
    }
    
    int scheduler = sched_getscheduler(getpid());
    printf("the scheduler of PID(%d)is %d, priority(%d), BEGIN time is %d\n",
            getpid(), scheduler, sched_priority, time(NULL));
    
    sleep(2);
    sleeptm.tv_sec = 0;
    sleeptm.tv_usec = NANOSECOND;
    
    for(i=0;i<COUNT;i++)
    {
        test_func();
    }
    
    interval = MILLION*(tend.tv_sec - tstart.tv_sec) 
                + (tend.tv_usec - tstart.tv_usec);
    
    printf("PID(%d)is %d, priority(%d), END time is %d, interval = %d\n",
            getpid(), scheduler, sched_priority, time(NULL), interval);
    
    return 0;    
    
}