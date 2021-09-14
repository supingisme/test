/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:25 CST. */


union sigval {
	int sival_int ;
	void *sival_ptr;
} ;
/* integer value */
/* pointer value */
struct sigevent {
	int sigev_notify; /* SIGEV_{NONE,SIGNAL,THREAD) */
	int sigev_signo; /* signal number i f SIGEV_SIGNAL */
	union sigval sigev_value; /* passed to signal handler or thread */
	/* following two i f SIGEV_THREAD */
	void (*sigev_notify_function) (union sigval);
	pthread_attr_t *sigev_notify_attributes;
};
