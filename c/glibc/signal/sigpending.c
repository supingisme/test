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

24.7.6 Checking for Pending Signals
You can fnd out which signals are pending at any time by calling sigpending. This function
is declared in ‘signal.h’.

等待  ， 在等待期间，  悬而未决的
int sigpending (sigset t *set) [Function]
The sigpending function stores information about pending signals in set. If there is
a pending signal that is blocked from delivery, then that signal is a member of the
returned set. (You can test whether a particular signal is a member of this set using
sigismember; see Section 24.7.2 [Signal Sets], page 633.)
The return value is 0 if successful, and -1 on failure.


*/

#include <signal.h>

#include <stdio.h>
#include <signal.h>
#include <stddef.h>



int main (void)
{
    sigset_t base_mask, waiting_mask;
    sigemptyset (&base_mask);
    sigaddset (&base_mask, SIGINT);
    sigaddset (&base_mask, SIGTSTP);
    /* Block user interrupts while doing other processing. */
    sigprocmask (SIG_SETMASK, &base_mask, NULL);
 
    /* After a while, check to see whether any signals are pending. */
    sigpending (&waiting_mask);
    
    if (sigismember (&waiting_mask, SIGINT)) {
    /* User has tried to kill the process. */
        printf("SIGINT\n");
    }
    else if (sigismember (&waiting_mask, SIGTSTP)) {
    /* User has tried to stop the process. */
        printf("SIGTSTP\n");
    }
    
    while(1)sleep(1);
    
    return 0;
}





