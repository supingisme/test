/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 18日 星期二 08:27:34 CST. */


/**
 *	NAME
 *    getitimer, setitimer - get or set value of an interval timer
 *
 * SYNOPSIS
 *	  #include <sys/time.h>
 *
 *    int getitimer(int which, struct itimerval *curr_value);
 *    int setitimer(int which, const struct itimerval *new_value,
 *                  struct itimerval *old_value);
 */

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
void timer_handler (int signum)
{
	static int count = 0;
	printf ("timer expired %d times\n", ++count);
}
int main ()
{
	struct sigaction sa;
	struct itimerval timer;
	/* Install timer_handler as the signal handler for SIGVTALRM. */
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &timer_handler;
	sigaction (SIGVTALRM, &sa, NULL);
	/* Configure the timer to expire after 250 msec... */
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 500000;
	/* ... and every 250 msec after that. */
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 500000;
	/* Start a virtual timer. It counts down whenever this process is
	 * executing. */
	setitimer (ITIMER_VIRTUAL, &timer, NULL);
	/* Do busy work. */
	while (1);
}
