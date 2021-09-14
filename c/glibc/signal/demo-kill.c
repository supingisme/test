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
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


/* When a SIGUSR1 signal arrives, set this variable. */
volatile sig_atomic_t usr_interrupt = 0;

void synch_signal (int sig)
{
    usr_interrupt = 1;
}

/* The child process executes this function. */
void child_function (void)
{
    /* Perform initialization. */
    printf ("I’m here!!! My pid is %d.\n", (int) getpid ());
    
    /* Let parent know you’re done. */
    kill (getppid (), SIGUSR1);
    
    /* Continue with execution. */
    puts ("Bye, now....");
    exit (0);
}

int main (void)
{
    struct sigaction usr_action;
    sigset_t block_mask;
    
    pid_t child_id;
    
    /* Establish the signal handler. */
    sigfillset (&block_mask);
    
    usr_action.sa_handler = synch_signal;
    usr_action.sa_mask = block_mask;
    usr_action.sa_flags = 0;
    
    sigaction (SIGUSR1, &usr_action, NULL);
    
    /* Create the child process. */
    child_id = fork ();
    
    if (child_id == 0)
        child_function (); /* Does not return. */
    
    /* Busy wait for the child to send a signal. */
    while (!usr_interrupt)
    ;
    /* Now continue execution. */
    puts ("That’s all, folks!");
    
    return 0;
}