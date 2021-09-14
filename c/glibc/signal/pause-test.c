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

int pause () [Function]
The pause function suspends program execution until a signal arrives whose action
is either to execute a handler function, or to terminate the process.
If the signal causes a handler function to be executed, then pause returns. This is
considered an unsuccessful return (since “successful” behavior would be to suspend the
program forever), so the return value is -1. Even if you specify that other primitives
should resume when a system handler returns (see Section 24.5 [Primitives Interrupted
by Signals], page 628), this has no eﬀect on pause; it always fails when a signal is
handled.
The following errno error conditions are defned for this function:
EINTR The function was interrupted by delivery of a signal.
If the signal causes program termination, pause doesn’t return (obviously).
This function is a cancellation point in multithreaded programs. This is a problem
if the thread allocates some resources (like memory, fle descriptors, semaphores or
whatever) at the time pause is called. If the thread gets cancelled these resources stay
allocated until the program ends. To avoid this calls to pause should be protected
using cancellation handlers.
The pause function is declared in ‘unistd.h’.
*/

#include <unistd.h>
#include <signal.h>

#include <stdio.h>

int main (int argc, char *argv[])
{
    kill(atoi(argv[1]), SIGINT);
    
    return 0;
}





