/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
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
/*

int sigprocmask (int how, const sigset t *restrict set, sigset t *restrict [Function]
oldset)
    The sigprocmask function is used to examine or change the calling process’s signal
    mask. The how argument determines how the signal mask is changed, and must be
    one of the following values:
        SIG_BLOCK  阻塞
        Block the signals in set—add them to the existing mask. In other words,
        the new mask is the union of the existing mask and set.
        SIG_UNBLOCK 非阻塞
        Unblock the signals in set—remove them from the existing mask.
        SIG_SETMASK
        Use set for the mask; ignore the previous value of the mask.




*/

#include <signal.h>

#include <stdio.h>

/* This variable is set by the SIGALRM signal handler. */
volatile sig_atomic_t flag = 0;


int main (void)
{
    
    sigset_t block_alarm;

    /* Initialize the signal mask. */
    sigemptyset (&block_alarm);
    sigaddset (&block_alarm, SIGALRM);
    while (1)
    {
        /* Check if a signal has arrived; if so, reset the ﬂag. */
        sigprocmask (SIG_BLOCK, &block_alarm, NULL); //阻塞
        if (flag)
        {
            //actions-if-not-arrived
            printf("flag = 0.\n");
            flag = 0;
        }
        sigprocmask (SIG_UNBLOCK, &block_alarm, NULL); //非阻塞

    }
    
    return 0;
}





