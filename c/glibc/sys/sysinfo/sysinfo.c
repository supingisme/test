/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 18日 星期二 08:29:14 CST. */

#include <linux/kernel.h>
#include <linux/sysinfo.h>
#include <stdio.h>
#include <sys/sysinfo.h>

#ifdef __rtoax_debug
struct sysinfo {
    long uptime;             /* Seconds since boot */
    unsigned long loads[3];  /* 1, 5, and 15 minute load averages */
    unsigned long totalram;  /* Total usable main memory size */
    unsigned long freeram;   /* Available memory size */
    unsigned long sharedram; /* Amount of shared memory */
    unsigned long bufferram; /* Memory used by buffers */
    unsigned long totalswap; /* Total swap space size */
    unsigned long freeswap;  /* swap space still available */
    unsigned short procs;    /* Number of current processes */
    unsigned long totalhigh; /* Total high memory size */
    unsigned long freehigh;  /* Available high memory size */
    unsigned int mem_unit;   /* Memory unit size in bytes */
    char _f[20-2*sizeof(long)-sizeof(int)]; /* Padding to 64 bytes */
};

#endif //__rtoax_debug


int main ()
{
    
	/* Obtain system statistics. */
	struct sysinfo si;
	sysinfo (&si);

    printf("Original data -----------------------------------\n");
    printf("uptime      \t%ld.\n", si.uptime);
    printf("loads[0]    \t%ld.\n", si.loads[0]);
    printf("loads[1]    \t%ld.\n", si.loads[1]);
    printf("loads[2]    \t%ld.\n", si.loads[2]);
    printf("totalram    \t%ld.\n", si.totalram);
    printf("freeram     \t%ld.\n", si.freeram);
    printf("sharedram   \t%ld.\n", si.sharedram);
    printf("bufferram   \t%ld.\n", si.bufferram);
    printf("totalswap   \t%ld.\n", si.totalswap);
    printf("freeswap    \t%ld.\n", si.freeswap);
    printf("procs       \t%d.\n",  si.procs);
    printf("totalhigh   \t%ld.\n", si.totalhigh);
    printf("freehigh    \t%ld.\n", si.freehigh);
    printf("mem_unit    \t%ld.\n", si.mem_unit);



    printf("Meaningful data -----------------------------------\n");

	/* Conversion constants. */
	const long minute = 60;
	const long hour = minute * 60;
	const long day = hour * 24;
	const double megabyte = 1024 * 1024;
    
	printf("uptime      \t%ld days, %ld:%02ld:%02ld\n",
    			si.uptime / day, (si.uptime % day) / hour,
    			(si.uptime % hour) / minute, si.uptime % minute);
    printf("loads[0]    \t%ld.\n", si.loads[0]);
    printf("loads[1]    \t%ld.\n", si.loads[1]);
    printf("loads[2]    \t%ld.\n", si.loads[2]);
    printf("totalram    \t%.2lf MB.\n", si.totalram / megabyte);
    printf("freeram     \t%.2lf MB.\n", si.freeram / megabyte);
    printf("sharedram   \t%.2lf MB.\n", si.sharedram / megabyte);
    printf("bufferram   \t%.2lf MB.\n", si.bufferram / megabyte);
    printf("totalswap   \t%.2lf MB.\n", si.totalswap / megabyte);
    printf("freeswap    \t%.2lf MB.\n", si.freeswap / megabyte);
    printf("procs       \t%d.\n",  si.procs);
    printf("totalhigh   \t%.2lf MB.\n", si.totalhigh / megabyte);
    printf("freehigh    \t%.2lf MB.\n", si.freehigh / megabyte);
    printf("mem_unit    \t%ld.\n", si.mem_unit);

    
	return 0;
}
