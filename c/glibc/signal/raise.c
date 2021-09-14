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
int raise (int signum) [Function]
The raise function sends the signal signum to the calling process. It returns zero if
successful and a nonzero value if it fails. About the only reason for failure would be
if the value of signum is invalid.

*/

#include <signal.h>

#include <stdio.h>
#include <stdlib.h>


/* When a stop signal arrives, set the action back to the default
and then resend the signal after doing cleanup actions. */
void tstp_handler (int sig)
{
    signal (SIGTSTP, SIG_DFL);
    /* Do cleanup actions here. */
    raise (SIGTSTP);
}
/* When the process is continued again, restore the signal handler. */
void cont_handler (int sig)
{
    signal (SIGCONT, cont_handler);
    signal (SIGTSTP, tstp_handler);
}



void handler(int signum)
{
    printf("RongTao\n");
    exit(1);
}


int main()
{
    signal (SIGCONT, cont_handler);
    signal (SIGTSTP, tstp_handler);
    signal(SIGINT, handler);
    
    raise(SIGCONT);
    raise(SIGTSTP);
    raise(SIGINT);
    
    printf("123123\n");
    
    return 0;
}
