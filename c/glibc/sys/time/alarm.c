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
unsigned int alarm (unsigned int seconds) [Function]
The alarm function sets the real-time timer to expire in seconds seconds. If you
want to cancel any existing alarm, you can do this by calling alarm with a seconds
argument of zero.
The return value indicates how many seconds remain before the previous alarm would
have been sent. If there is no previous alarm, alarm returns zero.

*/
#include <stdio.h>
#include <sys/time.h>

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

//unsigned int alarm (unsigned int seconds)

unsigned int alarm_self (unsigned int seconds)
{
    struct itimerval old, new;
    new.it_interval.tv_usec = 0;
    new.it_interval.tv_sec = 0;
    new.it_value.tv_usec = 0;
    new.it_value.tv_sec = (long int) seconds;

	//signal(SIGALRM, alarm_self);
	alarm(1);

	printf("alarm_self.\n");

    if (setitimer (ITIMER_REAL, &new, &old) < 0)
        return 0;
    else
        return old.it_value.tv_sec;
}

void printmsg()
{
    printf("Hello world\n");
	alarm(1);
    return ;
}

int main()
{
    
    signal(SIGALRM, printmsg);
    
    /*只一次*/
    alarm(1);
    
    printf("Wait.\n");
    
    getchar();
    
    return 0;
}
