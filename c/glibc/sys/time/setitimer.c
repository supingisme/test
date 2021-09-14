/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:31 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*
int setitimer (int which, struct itimerval *new, struct itimerval *old) [Function]
The setitimer function sets the timer specifed by which according to new. The
which argument can have a value of ITIMER_REAL, ITIMER_VIRTUAL, or ITIMER_PROF.
If old is not a null pointer, setitimer returns information about any previous unexpired timer of the same kind in the structure it points to.
The return value is 0 on success and -1 on failure. The following errno error conditions are defned for this function:
EINVAL The timer period is too large.

*/
#include <stdio.h>
#include <sys/time.h>

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

//int setitimer (int which, struct itimerval *new, struct itimerval *old);

void printmsg()
{
    printf("Hello world\n");
    return ;
}

int main()
{
    
    signal(SIGALRM, printmsg);
    
    struct itimerval tick;
    struct itimerval curr_value;
    
    tick.it_value.tv_sec = 1; //1s 后启动定时器
    tick.it_value.tv_usec = 0;
    
    tick.it_interval.tv_sec = 1; //定时器启动后，每个一秒执行响应函数
    tick.it_interval.tv_usec = 0;
    
    int ret = setitimer(ITIMER_REAL, &tick, NULL);
    
    if(ret != 0)
    {
        printf("setitimer error, %s\n", strerror(errno));
        return -1;
    }


    ret = getitimer(ITIMER_REAL, &curr_value);
    printf("ret = %d-----------\n", ret);
    printf("it_interval.tv_sec  = %ld\n", curr_value.it_interval.tv_sec);
    printf("it_interval.tv_usec = %ld\n", curr_value.it_interval.tv_usec);
    printf("it_value.tv_sec     = %ld\n", curr_value.it_value.tv_sec);
    printf("it_value.tv_usec    = %ld\n", curr_value.it_value.tv_usec);
    
    printf("Wait.\n");
    
    getchar();
    
    return 0;
}