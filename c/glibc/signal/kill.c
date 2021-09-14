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
int kill (pid t pid, int signum) [Function]
The kill function sends the signal signum to the process or process group specifed
by pid. Besides the signals listed in Section 24.2 [Standard Signals], page 604, signum
can also have a value of zero to check the validity of the pid.
The pid specifes the process or process group to receive the signal:
pid > 0 The process whose identifer is pid.
pid == 0 All processes in the same process group as the sender.
pid < -1 The process group whose identifer is −pid.
pid == -1 If the process is privileged, send the signal to all processes except for some
special system processes. Otherwise, send the signal to all processes with
the same eﬀective user ID.
A process can send a signal to itself with a call like kill (getpid(), signum). If
kill is used by a process to send a signal to itself, and the signal is not blocked,
then kill delivers at least one signal (which might be some other pending unblocked
signal instead of the signal signum) to that process before it returns.
The return value from kill is zero if the signal can be sent successfully. Otherwise,
no signal is sent, and a value of -1 is returned. If pid specifes sending a signal to
several processes, kill succeeds if it can send the signal to at least one of them.
There’s no way you can tell which of the processes got the signal or whether all of
them did.
The following errno error conditions are defned for this function:
EINVAL The signum argument is an invalid or unsupported number.
EPERM You do not have the privilege to send a signal to the process or any of
the processes in the process group named by pid.
ESRCH The pid argument does not refer to an existing process or group.


*/

#include <signal.h>

#include <stdio.h>
#include <stdlib.h>

int ret = 0;

void handler(int signum)
{
    printf("RongTao, ret = %d\n\n", ret);
    exit(1);
}


int main()
{
    signal(SIGINT, handler);

    ret = kill(getpid(), SIGINT);
    
    printf("123123\n");
    
    return 0;
}
