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
sigset_t [Data Type]
The sigset_t data type is used to represent a signal set. Internally, it may be
implemented as either an integer or structure type.



int sigemptyset (sigset t *set) [Function]
This function initializes the signal set set to exclude all of the defned signals. It
always returns 0.
int sigfillset (sigset t *set) [Function]
This function initializes the signal set set to include all of the defned signals. Again,
the return value is 0.
int sigaddset (sigset t *set, int signum) [Function]
This function adds the signal signum to the signal set set. All sigaddset does is
modify set; it does not block or unblock any signals.
The return value is 0 on success and -1 on failure. The following errno error condition
is defned for this function:
EINVAL The signum argument doesn’t specify a valid signal.
int sigdelset (sigset t *set, int signum) [Function]
This function removes the signal signum from the signal set set. All sigdelset does
is modify set; it does not block or unblock any signals. The return value and error
conditions are the same as for sigaddset.
Finally, there is a function to test what signals are in a signal set:
int sigismember (const sigset t *set, int signum) [Function]
The sigismember function tests whether the signal signum is a member of the signal
set set. It returns 1 if the signal is in the set, 0 if not, and -1 if there is an error.
The following errno error condition is defned for this function:
EINVAL The signum argument doesn’t specify a valid signal.
*/

#include <signal.h>

#include <stdio.h>

int main (void)
{
    sigset_t st;
    
    sigemptyset(&st);
    
    sigfillset(&st);
    
    printf("%x\n", st);
    
    sigaddset(&st, SIGINT);
    
    printf("%x\n", st);
    
    sigaddset(&st, SIGSTOP);
    
    printf("%x\n", st);
    
    //sigdelset(&st, SIGINT);
    
    printf("%x\n", st);
    
    
    if(sigismember(&st, SIGINT))
    {
        printf("SIGINT: %x\n", st);
    }
    
    return 0;
}





