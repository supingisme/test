/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:40 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 13:31:17 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:24 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_alrm(int signo)
{
    /*do nothing*/
    printf("sig_alrm\n");
}

unsigned int mysleep(unsigned int nsecs)
{
    struct sigaction newact, oldact;
    unsigned int unslept;
    newact.sa_handler = sig_alrm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGALRM, &newact, &oldact);
    alarm(nsecs);
    pause();
    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);
    return unslept;
}

int main()
{
    while(1)
    {
        mysleep(1);
        printf("Two seconds passed\n");
    }
    return 0;
}