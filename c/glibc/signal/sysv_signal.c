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
sighandler_t sysv_signal (int signum, sighandler t action) [Function]
The sysv_signal implements the behavior of the standard signal function as found
on SVID systems. The diﬀerence to BSD systems is that the handler is deinstalled
after a delivery of a signal.
Compatibility Note: As said above for signal, this function should be avoided when
possible. sigaction is the preferred method.


*/


#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*sighandler_t SIG_ERR [Macro]
The value of this macro is used as the return value from signal to indicate an error.*/

void termination_handler (int signum)
{
    printf("%d\n", signum);
    psignal(signum, "RongTao");
    exit(0);
}
int main (void)
{
    sysv_signal (SIGINT, termination_handler);
    sysv_signal (SIGQUIT, termination_handler);


    
    while(1);
}





















