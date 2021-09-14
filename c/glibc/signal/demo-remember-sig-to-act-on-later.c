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







/* If this ﬂag is nonzero, don’t handle the signal right away. */
volatile sig_atomic_t signal_pending;

/* This is nonzero if a signal arrived and was not handled. */
volatile sig_atomic_t defer_signal;

void handler (int signum)
{
    if (defer_signal)
        signal_pending = signum;
    else
        ;/* “Really” handle the signal. */
}

void update_mumble (int frob)
{
    /* Prevent signals from having immediate eﬀect. */
    defer_signal++;
    
    /* Now update mumble, without worrying about interruption. */
    mumble.a = 1;
    mumble.b = hack ();
    mumble.c = frob;
    
    /* We have updated mumble. Handle any signal that came in. */
    defer_signal--;
    
    if (defer_signal == 0 && signal_pending != 0)
        raise (signal_pending);
}