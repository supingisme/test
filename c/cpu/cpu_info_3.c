/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>
//#include "proc.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/times.h>
#include <time.h>

#define PROC_SELF_STATM     "/proc/self/statm"

/**
 * Returns the size of physical memory (RAM) in bytes.
 */
size_t getPhyMemorySize( )
{
	return (size_t)sysconf( _SC_PHYS_PAGES ) *
		(size_t)sysconf( _SC_PAGESIZE );
}

/**
 * Returns the peak (maximum so far) resident set size (physical
 * memory use) measured in bytes, or zero if the value cannot be
 * determined on this OS.
 */
size_t getProcPeakRSS( )
{
	struct rusage rusage;
	getrusage( RUSAGE_SELF, &rusage );

	return (size_t)(rusage.ru_maxrss * 1024L);
}


/**
 * Returns the current resident set size (physical memory use) measured
 * in bytes, or zero if the value cannot be determined on this OS.
 */
size_t getProcCurrentRSS( )
{
	long rss = 0L;
	FILE* fp = NULL;
	if ( (fp = fopen( PROC_SELF_STATM, "r" )) == NULL )
    {
		return (size_t)0L;		/* Can't open? */
    }
	if ( fscanf( fp, "%*s%ld", &rss ) != 1 )
	{
		fclose( fp );
		return (size_t)0L;		/* Can't read? */
	}
	fclose( fp );
	return (size_t)rss * (size_t)sysconf( _SC_PAGESIZE);
}



/**
 *  Returns the amount of CPU time used by the current process,
 *  in seconds, or -1.0 if an error occurred.
 */
double getCPUTime()
{
	{
		struct rusage rusage;
		if ( getrusage( RUSAGE_SELF, &rusage ) != -1 )
			return (double)rusage.ru_utime.tv_sec +
				(double)rusage.ru_utime.tv_usec / 1000000.0;
	}
}


double getCPUUsage() 
{
	static double lastT = -1.0;
	static double lastCPUTime = -1.0;
	struct timeval tv;
	double nowCPUTime;
	double nowT;
	double percent = 0.0;
    
	if (gettimeofday(&tv, NULL) != 0) 
    {
		return -1;
	}
	nowCPUTime = getCPUTime();
    
	if (nowCPUTime < 0) 
    {
		return -2;
	}
	nowT = (double)tv.tv_sec + (double)(tv.tv_usec / 1000000.0);
    
	if (lastT <= 0) 
    {
		lastT = nowT;
		lastCPUTime = nowCPUTime;
		return 0;
	}
	percent = (nowCPUTime - lastCPUTime) / (nowT - lastT);
	lastT = nowT;
	lastCPUTime = nowCPUTime;
    
	return percent;
}


static void sleep_ms(int ms)
{
    usleep((useconds_t)ms * 1000);
}

int main(int argc, const char *argv[])
{
	char s[128];
	int i=0;
	for (;;) {
        //
		sleep_ms(1000);
		struct timeval tv;
		for (i=0; i< 500000; i++) {
			gettimeofday(&tv, NULL);
			snprintf(s, sizeof(s)-1, "sec=%08lx,usec=%08x", tv.tv_sec, tv.tv_usec);
		}
        
        printf("RUSAGE_SELF = %d, pid = %d\n", RUSAGE_SELF, getpid());
        
		printf("==================================\n");
		printf("currss=%zu\n", getProcCurrentRSS());
		printf("peakrss=%zu\n", getProcPeakRSS());
		printf("phymem=%zu\n", getPhyMemorySize());
		printf("cputime=%g\n", getCPUTime());
		printf("cpuusage=%g\n", getCPUUsage());

	}
	return 0;
}















