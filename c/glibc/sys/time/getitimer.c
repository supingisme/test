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
int getitimer (int which, struct itimerval *old) [Function]
The getitimer function stores information about the timer specifed by which in the
structure pointed at by old.
The return value and error conditions are the same as for setitimer.
ITIMER_REAL
This constant can be used as the which argument to the setitimer and
getitimer functions to specify the real-time timer.
ITIMER_VIRTUAL
This constant can be used as the which argument to the setitimer and
getitimer functions to specify the virtual timer.
ITIMER_PROF
This constant can be used as the which argument to the setitimer and
getitimer functions to specify the profling timer.


*/
#include <stdio.h>
#include <sys/time.h>

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
//int getitimer (int which, struct itimerval *old);

void printmsg()
{
    printf("Hello world\n");
    return ;
}
int main()
{
    signal(SIGALRM, printmsg);

    
    struct itimerval curr_value;
    int ret ;

    
    struct itimerval tick;
    
    tick.it_value.tv_sec = 1; //1s 后启动定时器
    tick.it_value.tv_usec = 2;
    
    tick.it_interval.tv_sec = 1; //定时器启动后，每个一秒执行响应函数
    tick.it_interval.tv_usec = 4;
    
    ret = setitimer(ITIMER_REAL, &tick, NULL);
    printf("ret = %d-----------\n", ret);
    
    ret = getitimer(ITIMER_REAL, &curr_value);
    printf("ret = %d-----------\n", ret);
    printf("it_interval.tv_sec  = %ld\n", curr_value.it_interval.tv_sec);
    printf("it_interval.tv_usec = %ld\n", curr_value.it_interval.tv_usec);
    printf("it_value.tv_sec     = %ld\n", curr_value.it_value.tv_sec);
    printf("it_value.tv_usec    = %ld\n", curr_value.it_value.tv_usec);

    ret = getitimer(ITIMER_VIRTUAL, &curr_value);
    printf("ret = %d-----------\n", ret);
    printf("it_interval.tv_sec  = %ld\n", curr_value.it_interval.tv_sec);
    printf("it_interval.tv_usec = %ld\n", curr_value.it_interval.tv_usec);
    printf("it_value.tv_sec     = %ld\n", curr_value.it_value.tv_sec);
    printf("it_value.tv_usec    = %ld\n", curr_value.it_value.tv_usec);

    ret = getitimer(ITIMER_PROF, &curr_value);
    printf("ret = %d-----------\n", ret);
    printf("it_interval.tv_sec  = %ld\n", curr_value.it_interval.tv_sec);
    printf("it_interval.tv_usec = %ld\n", curr_value.it_interval.tv_usec);
    printf("it_value.tv_sec     = %ld\n", curr_value.it_value.tv_sec);
    printf("it_value.tv_usec    = %ld\n", curr_value.it_value.tv_usec);

    printf("Wait.\n");
    
    getchar();
    
    return 0;
}