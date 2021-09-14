/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 24日 星期一 08:52:25 CST. */


#include <pthread.h>

/**
 *	创建分离（detach）的线程，这个线程不需要pthread_join
 */
void* thread_function (void* thread_arg)
{
	/* Do work here... */
}
int main ()
{
	pthread_attr_t attr;
	pthread_t thread;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	pthread_create (&thread, &attr, &thread_function, NULL);
	pthread_attr_destroy (&attr);
	/* Do work here... */
	/* No need to join the second thread. */
	return 0;
}
