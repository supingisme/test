#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "mq.h"
#include "signal_rt.h"

#ifndef debug
#define debug() printf("%s:%d\n", __func__, __LINE__);
#endif
//static void sig_notify(int signo, siginfo_t *info, void *context);

struct sigevent	sigev;

static Sigfunc_rt	sig_notify;

int main()
{
	int flags = O_RDWR|O_CREAT|O_EXCL;
	
	mqd_t	mqd;
	struct mq_attr attr;

	attr.mq_maxmsg = 256;
	attr.mq_msgsize = 1024;

	mqd = mq_open(_MQ_NAME, flags, FILE_MODE, &attr);
	if(!mqd)
		perror("mq_open:");

	debug();
	Signal_rt(MYSIG_NOTIFY, sig_notify);
	debug();

	sigev.sigev_notify = SIGEV_SIGNAL;
	sigev.sigev_signo = MYSIG_NOTIFY;
	sigev.sigev_value.sival_ptr = &mqd;
	mq_notify(mqd, &sigev);

	for ( ; ; )
		pause();		/* signal handler does everything */

	exit(0);


	mq_close(mqd);

	return 0;
}

static void sig_notify(int signo, siginfo_t *info, void *context)
{
	printf("MYSIG_NOTIFY received\n");
	if (info->si_code != SI_MESGQ)
		printf("si_code = %d", info->si_code);
	mq_notify(*((mqd_t *) info->si_value.sival_ptr), &sigev);
	return;
}

