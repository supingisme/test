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

int sigaction (int signum, const struct sigaction *restrict action, [Function]
struct sigaction *restrict old-action)
The action argument is used to set up a new action for the signal signum, while
the old-action argument is used to return information about the action previously
associated with this symbol. (In other words, old-action has the same purpose as the
signal function’s return value—you can check to see what the old action in eﬀect for
the signal was, and restore it later if you want.)
Either action or old-action can be a null pointer. If old-action is a null pointer, this
simply suppresses the return of information about the old action. If action is a null
pointer, the action associated with the signal signum is unchanged; this allows you to
inquire about how a signal is being handled without changing that handling.
The return value from sigaction is zero if it succeeds, and -1 on failure. The
following errno error conditions are defned for this function:
EINVAL The signum argument is not valid, or you are trying to trap or ignore
SIGKILL or SIGSTOP.



*/

#include <signal.h>

// struct sigaction{
    // sighandler_t sa_handler;
    // sigset_t sa_mask;
    // int sa_flags;
// };


#include <stdio.h>
#include <stdlib.h>


void handler(int signum)
{
    printf("%d\n", signum);
    psignal(signum, "RongTao");
    exit(0);
}

void demo1()
{
    struct sigaction s1 = {
        .sa_handler = handler,
        .sa_flags = SA_RESTART,
    }, s2;
    
    sigaction(SIGINT, &s1, &s2);
}

int demo2 (void)
{
    struct sigaction new_action, old_action;
    
    /* Set up the structure to specify the new action. */
    new_action.sa_handler = handler;
    
    sigemptyset (&new_action.sa_mask);
    
    new_action.sa_flags = 0;
    
    sigaction (SIGINT, NULL, &old_action);
    
    if (old_action.sa_handler != SIG_IGN)
        sigaction (SIGINT, &new_action, NULL);
    sigaction (SIGHUP, NULL, &old_action);
    
    if (old_action.sa_handler != SIG_IGN)
        sigaction (SIGHUP, &new_action, NULL);
    sigaction (SIGTERM, NULL, &old_action);
    
    if (old_action.sa_handler != SIG_IGN)
        sigaction (SIGTERM, &new_action, NULL);

}

void demo3()
{
    struct sigaction temp;
    sigaction (SIGHUP, NULL, &temp);
    if (temp.sa_handler != SIG_IGN)
    {
        temp.sa_handler = handler;
        sigemptyset (&temp.sa_mask);
        sigaction (SIGHUP, &temp, NULL);
    }
}

int main()
{
    demo2(); 
    
    demo3();
    
    while(1);
    
    return 0;
}











