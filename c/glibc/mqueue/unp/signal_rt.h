#ifndef __SIGNAL_RT_H
#define __SIGNAL_RT_H 1

#include <signal.h>
//#include <sigaction.h>

#define MYSIG_NOTIFY	(SIGRTMIN+2)

typedef	void	Sigfunc_rt(int, siginfo_t *, void *);

Sigfunc_rt *signal_rt(int signo, Sigfunc_rt *func);

Sigfunc_rt *Signal_rt(int signo, Sigfunc_rt *func);


#endif //__SIGNAL_RT_H
