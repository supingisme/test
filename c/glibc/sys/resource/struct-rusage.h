/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
struct rusage [Data Type]
This data type stores various resource usage statistics. It has the following members,
and possibly others:
struct timeval ru_utime
Time spent executing user instructions.
struct timeval ru_stime
Time spent in operating system code on behalf of processes.
long int ru_maxrss
The maximum resident set size used, in kilobytes. That is, the maximum
number of kilobytes of physical memory that processes used simultane
ously.
long int ru_ixrss
An integral value expressed in kilobytes times ticks of execution, which
indicates the amount of memory used by text that was shared with other
processes.
long int ru_idrss
An integral value expressed the same way, which is the amount of un
shared memory used for data.
long int ru_isrss
An integral value expressed the same way, which is the amount of un
shared memory used for stack space.
long int ru_minflt
The number of page faults which were serviced without requiring any
I/O.
long int ru_majflt
The number of page faults which were serviced by doing I/O.
long int ru_nswap
The number of times processes was swapped entirely out of main memory.
long int ru_inblock
The number of times the fle system had to read from the disk on behalf
of processes.
long int ru_oublock
The number of times the fle system had to write to the disk on behalf of
processes.
long int ru_msgsnd
Number of IPC messages sent.
long int ru_msgrcv
Number of IPC messages received.
long int ru_nsignals
Number of signals received.
long int ru_nvcsw
The number of times processes voluntarily invoked a context switch (usu
ally to wait for some service).
long int ru_nivcsw
The number of times an involuntary context switch took place (because
a time slice expired, or another process of higher priority was scheduled).



*/

#include <sys/resource.h>


struct rusage{
    struct timeval ru_utime;
    struct timeval ru_stime;
    long int ru_maxrss;
    long int ru_ixrss;
    long int ru_idrss;
    long int ru_isrss;
    long int ru_minflt;
    long int ru_majflt;
    long int ru_nswap;
    long int ru_inblock;
    long int ru_oublock;
    long int ru_msgsnd;
    long int ru_msgrcv;
    long int ru_nsignals;
    long int ru_nvcsw;
    long int ru_nivcsw;
};



int show(struct rusage rusage)
{
    printf("ru_utime.tv_sec: %d\n", rusage.ru_utime.tv_sec);
    printf("ru_utime.tv_usec: %d\n", rusage.ru_utime.tv_usec);
    printf("ru_stime.tv_sec: %d\n", rusage.ru_stime.tv_sec);
    printf("ru_stime.tv_usec: %d\n", rusage.ru_stime.tv_usec);
    printf("ru_maxrss: %d\n", rusage.ru_maxrss);
    printf("ru_ixrss: %d\n", rusage.ru_ixrss);
    printf("ru_idrss: %d\n", rusage.ru_idrss);
    printf("ru_isrss: %d\n", rusage.ru_isrss);
    printf("ru_minflt: %d\n", rusage.ru_minflt);
    printf("ru_majflt: %d\n", rusage.ru_majflt);
    printf("ru_nswap: %d\n", rusage.ru_nswap);
    printf("ru_inblock: %d\n", rusage.ru_inblock);
    printf("ru_oublock: %d\n", rusage.ru_oublock);
    printf("ru_msgsnd: %d\n", rusage.ru_msgsnd);
    printf("ru_msgrcv: %d\n", rusage.ru_msgrcv);
    printf("ru_nsignals: %d\n", rusage.ru_nsignals);
    printf("ru_nvcsw: %d\n", rusage.ru_nvcsw);
    printf("ru_nivcsw: %d\n", rusage.ru_nivcsw);
}


