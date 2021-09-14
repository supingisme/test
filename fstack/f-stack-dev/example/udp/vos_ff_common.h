/**
 *  
 *  作者：荣涛 <rongtao@sylincom.com>
 *  时间：2020年7月16日10:08:34
 */
#ifndef __VOS_FF_COMMON_H
#define __VOS_FF_COMMON_H 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/epoll.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>

#define __USE_GNU
#include <sched.h>
#include <ctype.h>
#include <string.h>

#include <stdarg.h>
#include <libgen.h>

#include "ff_config.h"
#include "ff_api.h"
#include "ff_epoll.h"

#include "vos_ff_api.h"
#include "vos_ff_common.h"




/**
 *  打印log debug信息
 *  作者： 荣涛
 *  时间： s2020年7月15日10:12:24
 */
enum {
    __LV_INFO,
    __LV_WARNING,
    __LV_ERR,
    __LV_DEBUG,
};

#define LOG_DEBUG 1
#ifdef LOG_DEBUG
#define log_info(fmt...) ___debug_log(__LV_INFO, __FILE__, __func__ ,__LINE__, fmt)
#define log_warn(fmt...) ___debug_log(__LV_WARNING, __FILE__, __func__ ,__LINE__, fmt)
#define log_error(fmt...) ___debug_log(__LV_ERR, __FILE__, __func__ ,__LINE__, fmt)
#define log_debg(fmt...) ___debug_log(__LV_DEBUG, __FILE__, __func__ ,__LINE__, fmt)
#else
#define log_info(fmt...) 
#define log_warn(fmt...)
#define log_error(fmt...)
#define log_debg(fmt...)
#define log_errorno(i_errno)
#endif

static inline int ___debug_log(int level, char *file, const char *func, int line, char *fmt, ...)
{
    

    va_list av;
    va_start(av, fmt);

    switch(level) {
        case __LV_INFO:
            printf(" [%sFF INFO%s][%s:%s:%d]: ","\033[1;36m","\033[0m", basename(file), func, line);
            break;
        case __LV_WARNING:
            printf(" [%sFF WARN%s][%s:%s:%d]: ","\033[1;35m","\033[0m", basename(file), func, line);
            break;
        case __LV_ERR:
            printf("[%sFF ERROR%s][%s:%s:%d]: ","\033[1;31m","\033[0m", basename(file), func, line);
            break;
        case __LV_DEBUG:
            printf("[%sFF DEBUG%s][%s:%s:%d]: ","\033[1m",   "\033[0m", basename(file), func, line);
            break;
    }
    
    int i = vprintf(fmt, av);

    va_end(av);

    return i;
}


static inline long int gettimeval(struct timeval *tv)
{
    gettimeofday(tv, NULL);    
}
static inline void statistic_throughput(char *description, 
            struct timeval *before, struct timeval *after, unsigned long int bytes, long int npkg
)
{
//    printf("\t -- before time: %ld, %ld\n", before->tv_sec, before->tv_usec);
//    printf("\t --  after time: %ld, %ld\n", after->tv_sec, after->tv_usec);
    printf("-- %s: Total %.3lf Mbps, bytes = %ld(bits:%ld), npkg = %ld.\n", 
                            description?description:"Unknown Description", 
                            8*bytes*1.0/((after->tv_sec-before->tv_sec)*1000000
    						            +after->tv_usec-before->tv_usec), bytes, bytes*8, npkg);
}


static void setaffinity(long int ncpu)
{
//    long int ncpu = sysconf (_SC_NPROCESSORS_ONLN);
    
    cpu_set_t cpuset;

	CPU_ZERO(&cpuset);
    
    CPU_SET(ncpu>1?ncpu-1:1, &cpuset);
    
    int ret = sched_setaffinity(getpid(), sizeof(cpuset), &cpuset);
    
    log_warn("setaffinity ret = %d\n", ret);
    
    int j;
    for(j=0;j<CPU_SETSIZE; j++)
    {
        if(CPU_ISSET(j, &cpuset))
        {
            printf("CPU_SETSIZE = %d, j = %d, cpuset = %d\n", CPU_SETSIZE, j, cpuset);
            CPU_CLR(j, &cpuset);
            printf("CPU_SETSIZE = %d, j = %d, cpuset = %d\n", CPU_SETSIZE, j, cpuset);
        }
    }
    
    ret = sched_getaffinity(getpid(), sizeof(cpuset), &cpuset);

    for(j=0;j<CPU_SETSIZE; j++)
    {
        if(CPU_ISSET(j, &cpuset))
        {
            printf("CPU_SETSIZE = %d, j = %d, cpuset = %d\n", CPU_SETSIZE, j, cpuset);
        }
    }
}




#endif /*__VOS_FF_COMMON_H*/

