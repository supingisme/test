/**
 *  
 *  作者：荣涛 <rongtao@sylincom.com>
 *  时间：s2020年8月5日15:05:16
 */
#include "vos_ff_common.h"
#include "vos_ff_api.h"



inline long int fstack_gettimeval(struct timeval *tv)
{
    gettimeofday(tv, NULL);    
}


inline void fstack_statistic_throughput(char *description, 
            struct timeval *before, struct timeval *after, unsigned long int bytes, long int npkg)
{
    printf("-- %s: Total %.3lf Mbps, bytes = %ld(bits:%ld), npkg = %ld.\n", 
                            description?description:"Unknown Description", 
                            8*bytes*1.0/((after->tv_sec-before->tv_sec)*1000000
    						            +after->tv_usec-before->tv_usec), bytes, bytes*8, npkg);
}

