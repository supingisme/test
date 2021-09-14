/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 24日 星期一 08:52:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 09:02:19 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/**
 *	pthread_getspecific
 *	pthread_setspecific
 */

#include <pthread.h>

void* pthread_getspecific(pthread_key_t key);
	//返回：指向线程特定数据的指针（有可能是个空指针）
int pthread_setspecific(pthread_key_t key, const void *value);
	//返回：若成功则为0，若出错则为正的Exxx值  
	

/**
 * pthread_setspecific
 *
 * 		使用该函数可以为指定线程特定数据键设置线程特定绑定。
 *
 */
#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
/* The key used to associate a log file pointer with each thread. */
static pthread_key_t thread_log_key;
/* Write MESSAGE to the log file for the current thread. */
void write_to_thread_log (const char* message)
{
	FILE* thread_log = (FILE*) pthread_getspecific (thread_log_key);
	fprintf (thread_log, "%s\n", message);
}
/* Close the log file pointer THREAD_LOG. */
void close_thread_log (void* thread_log)
{
	fclose ((FILE*) thread_log);
}
void* thread_function (void* args)
{
	char thread_log_filename[20];
	FILE* thread_log;
	/* Generate the filename for this thread’s log file. */
	sprintf (thread_log_filename, "thread%d.log", (int) pthread_self ());
	/* Open the log file. */
	thread_log = fopen (thread_log_filename, "w");
	/* Store the file pointer in thread-specific data under thread_log_key. */
	pthread_setspecific (thread_log_key, thread_log);
	write_to_thread_log ("Thread starting.");
	/* Do work here... */
	return NULL;
}
int main ()
{
	int i;
	pthread_t threads[5];
	/* Create a key to associate thread log file pointers in
	 * thread-specific data. Use close_thread_log to clean up the file
	 * pointers. */
	pthread_key_create (&thread_log_key, close_thread_log);
	/* Create threads to do the work. */
	for (i = 0; i < 5; ++i)
		pthread_create (&(threads[i]), NULL, thread_function, NULL);
	/* Wait for all threads to finish. */
	for (i = 0; i < 5; ++i)
		pthread_join (threads[i], NULL);
	return 0;
}


