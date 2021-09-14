/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*

Using contexts in such a way enables emulating exception handling. The search functions
passed in the fp parameter could be very large, nested, and complex which would make it
complicated (or at least would require a lot of code) to leave the function with an error
value which has to be passed down to the caller. By using the context it is possible to leave
the search function in one step and allow restarting the search which also has the nice side
eﬀect that it can be signifcantly faster.
Something which is harder to implement with setjmp and longjmp is to switch tem
porarily to a diﬀerent execution path and then resume where execution was stopped.


*/

#include <ucontext.h>
#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <sys/time.h>


int
random_search (int n, int (*fp) (int, ucontext_t *))
{
    volatile int cnt = 0;
    ucontext_t uc;
    
    /* Safe current context. */
    if (getcontext (&uc) < 0)
        return -1;

    /* If we have not tried n times try again. */
    if (cnt++ < n)
        /* Call the function with a new random number
        and the context. */
        if (fp (rand (), &uc) != 0)
            /* We found what we were looking for. */
            return 1;
    
    /* Not found. */
    return 0;

}


/* Set by the signal handler. */
static volatile int expired;

/* The contexts. */
static ucontext_t uc[3];

/* We do only a certain number of switches. */
static int switches;

/* This is the function doing the work. It is just a
skeleton, real code has to be flled in. */
static void f (int n)
{
    int m = 0;
    while (1)
    {
        /* This is where the work would be done. */
        if (++m % 100 == 0)
        {
            putchar ('.');
            fflush (stdout);
        }
        /* Regularly the expire variable must be checked. */
        if (expired)
        {
            /* We do not want the program to run forever. */
            if (++switches == 20)
                return;
            printf ("\nswitching from %d to %d\n", n, 3 - n);
            expired = 0;
            /* Switch to the other context, saving the current one. */
            swapcontext (&uc[n], &uc[3 - n]);
        }
    }
}
/* This is the signal handler which simply set the variable. */
void handler (int signal)
{
    expired = 1;
}

int main (void)
{
    struct sigaction sa;
    struct itimerval it;
    char st1[8192];
    char st2[8192];
    
    /* Initialize the data structures for the interval timer. */
    sa.sa_flags = SA_RESTART;
    sigfillset (&sa.sa_mask);
    sa.sa_handler = handler;
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = 1;
    it.it_value = it.it_interval;
    
    /* Install the timer and get the context we can manipulate. */
    if (sigaction (SIGPROF, &sa, NULL) < 0
        || setitimer (ITIMER_PROF, &it, NULL) < 0
        || getcontext (&uc[1]) == -1
        || getcontext (&uc[2]) == -1)
        abort ();
        
    /* Create a context with a separate stack which causes the
    function f to be call with the parameter 1.
    Note that the uc_link points to the main context
    which will cause the program to terminate once the function
    return. */
    uc[1].uc_link = &uc[0];
    uc[1].uc_stack.ss_sp = st1;
    uc[1].uc_stack.ss_size = sizeof st1;
    makecontext (&uc[1], (void (*) (void)) f, 1, 1);
    
    /* Similarly, but 2 is passed as the parameter to f. */
    uc[2].uc_link = &uc[0];
    uc[2].uc_stack.ss_sp = st2;
    uc[2].uc_stack.ss_size = sizeof st2;
    makecontext (&uc[2], (void (*) (void)) f, 1, 2);
    
    /* Start running. */
    swapcontext (&uc[0], &uc[1]);
    putchar ('\n');
    return 0;
}
