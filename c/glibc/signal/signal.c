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
sighandler_t signal (int signum, sighandler t action) [Function]
The signal function establishes action as the action for the signal signum.
The frst argument, signum, identifes the signal whose behavior you want to control,
and should be a signal number. The proper way to specify a signal number is with one
of the symbolic signal names (see Section 24.2 [Standard Signals], page 604)—don’t
use an explicit number, because the numerical code for a given kind of signal may
vary from operating system to operating system.
The second argument, action, specifes the action to use for the signal signum. This
can be one of the following:
SIG_DFL SIG_DFL specifes the default action for the particular signal. The default
actions for various kinds of signals are stated in Section 24.2 [Standard
Signals], page 604.
SIG_IGN SIG_IGN specifes that the signal should be ignored.
Your program generally should not ignore signals that represent serious
events or that are normally used to request termination. You cannot ig
nore the SIGKILL or SIGSTOP signals at all. You can ignore program error
signals like SIGSEGV, but ignoring the error won’t enable the program to
continue executing meaningfully. Ignoring user requests such as SIGINT,
SIGQUIT, and SIGTSTP is unfriendly.
When you do not wish signals to be delivered during a certain part of
the program, the thing to do is to block them, not ignore them. See
Section 24.7 [Blocking Signals], page 633.
handler Supply the address of a handler function in your program, to specify
running this handler as the way to deliver the signal.
For more information about defning signal handler functions, see
Section 24.4 [Defning Signal Handlers], page 618.
If you set the action for a signal to SIG_IGN, or if you set it to SIG_DFL and the default
action is to ignore that signal, then any pending signals of that type are discarded
(even if they are blocked). Discarding the pending signals means that they will never
be delivered, not even if you subsequently specify another action and unblock this
kind of signal.
The signal function returns the action that was previously in eﬀect for the specifed
signum. You can save this value and restore it later by calling signal again.
If signal can’t honor the request, it returns SIG_ERR instead. The following errno
error conditions are defned for this function:
EINVAL You specifed an invalid signum; or you tried to ignore or provide a handler
for SIGKILL or SIGSTOP.


*/


// Compatibility Note: A problem encountered when working with the signal function is
// that it has diﬀerent semantics on BSD and SVID systems. The diﬀerence is that on SVID
// systems the signal handler is deinstalled after signal delivery. On BSD systems the handler
// must be explicitly deinstalled. In the GNU C Library we use the BSD version by default.
// To use the SVID version you can either use the function sysv_signal (see below) or use
// the _XOPEN_SOURCE feature select macro (see Section 1.3.4 [Feature Test Macros], page 7).
// In general, use of these functions should be avoided because of compatibility problems. It
// is better to use sigaction if it is available since the results are much more reliable.
// Here is a simple example of setting up a handler to delete temporary fles when certain
// fatal signals happen:

//sighandler_t
void handler (int signum) 
{ 
    /*...*/
};

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This ﬂag controls termination of the main loop. */
volatile sig_atomic_t keep_going = 1;

void termination_handler (int signum)
{
    printf("%d\n", signum);
    psignal(signum, "RongTao");
    exit(0);
}

void do_stuff (void)
{
    puts ("Doing stuff while waiting for alarm....");
    
    signal (SIGINT, termination_handler);
}

/* The signal handler just clears the ﬂag and re-enables itself. */
void catch_alarm (int sig)
{
    keep_going = 0;
    do_stuff ();
}
int demo1 (void)
{
    /* Establish a handler for SIGALRM signals. */
    signal (SIGALRM, catch_alarm);
    
    /* Set an alarm to go oﬀ in a little while. */
    alarm (2);
    
    /* Check the ﬂag once in a while to see when to quit. */
    while (1);
    
    return EXIT_SUCCESS;
}



void demo2()
{
    if (signal (SIGINT, termination_handler) != SIG_ERR)
        signal (SIGINT, SIG_DFL);
    
    while(1);
}

int main (void)
{
    demo1();
    


    
    //
}





















