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

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define     FUNC_OK 0
#define     FUNC_ERR -1
#define     INT32 int32_t
#define     UINT32  uint32_t


#define PROC_CPUINFO    "/proc/cpuinfo"


typedef struct {
#define CPU_VENDOR_STRING_SIZE  32
    char vendor_string[CPU_VENDOR_STRING_SIZE];
#define CPU_BRAND_STRING_SIZE   64
    char brand_string[CPU_BRAND_STRING_SIZE];
    UINT32 physical_cores;
    UINT32 logical_cores;
    size_t cache_line_size;
    size_t l1d_cache_size;
    size_t l1i_cache_size;
    size_t l2_cache_size;
    size_t l3_cache_size;
} CPU_info;



void cpu_log_result(FILE* file, CPU_info* result)
{
    fprintf(file, "vendor_string: %s\n", result->vendor_string);
    fprintf(file, "brand_string: %s\n", result->brand_string);
    fprintf(file, "physical_cores: %d\n", result->physical_cores);
    fprintf(file, "logical_cores: %d\n", result->logical_cores);
    fprintf(file, "cache_line_size: %zu\n", result->cache_line_size);
    fprintf(file, "l1d_cache_size: %zu\n", result->l1d_cache_size);
    fprintf(file, "l1i_cache_size: %zu\n", result->l1i_cache_size);
    fprintf(file, "l2_cache_size: %zu\n", result->l2_cache_size);
    fprintf(file, "l3_cache_size: %zu\n", result->l3_cache_size);
}


#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

/// Gets the value as an integer from the key/value pair contained within `line` pulled from `/proc/cpuinfo`
UINT32 cpu_cpuinfo_parse_numeric(char* str, UINT32* result)
{
    char* colon = strchr(str, ':');
    if (colon != NULL ) 
    {
        *result = (UINT32)atoi(colon + 2);
    }
}

/// Gets the value as a string from the key/value pair contained within `line` pulled from `/proc/cpuinfo`
void cpu_cpuinfo_parse_string(char* line, char* result)
{
    char* colon = strchr(line, ':');
    int strend;
    char* pstr = colon + 2;
    if (!pstr) 
    {
        strend = -1;
    }
    else if (!pstr[0]) 
    {
        strend = 0;
    }
    else
    {
        strend = -1;
        size_t len = strlen(pstr);
        size_t i;
        for (i = len; i > 0; --i) 
        {
            if (isspace(pstr[i])) 
            {
                strend = (int)i;
                break;
            }
        }
        if (strend == -1) 
        {
            strend = (int)len;
        }
    }
    
    if (colon != NULL && strend > -1 ) 
    {
        strncpy(result, colon + 2, (size_t)strend);
    }
}


CPU_info* get_cpu_info(CPU_info* result)
{
    int times = 0;
    while(result == NULL)
    {
        if(times++>3){ return NULL; }
        result = (CPU_info*)malloc(sizeof(CPU_info));
    }
    memset(result, 0, sizeof(CPU_info));
    
    char str[256];

    // Getting cache info with sysconf is portable, whereas logical/hw core info isn't
    result->cache_line_size = (size_t)sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    result->l1d_cache_size  = (size_t)sysconf(_SC_LEVEL1_DCACHE_SIZE);
    result->l1i_cache_size  = (size_t)sysconf(_SC_LEVEL1_ICACHE_SIZE);
    result->l2_cache_size   = (size_t)sysconf(_SC_LEVEL2_CACHE_SIZE);
    result->l3_cache_size   = (size_t)sysconf(_SC_LEVEL3_CACHE_SIZE);

    FILE *fpcpuinfo = fopen(PROC_CPUINFO, "rb");
    // Read through cpuinfo and parse results
    while ( fgets(str, sizeof(str), fpcpuinfo) ) 
    {
        if ( !strncmp(str, "processor", 9) ) 
        {
            result->logical_cores++;
        }
        if ( !strncmp(str, "cpu cores", 9) && result->physical_cores == 0 ) 
        {
            cpu_cpuinfo_parse_numeric(str, &result->physical_cores);
        }
        if ( !strncmp(str, "vendor_id", 9) && result->vendor_string[0] == 0 ) 
        {
            cpu_cpuinfo_parse_string(str, result->vendor_string);
        }
        if ( !strncmp(str, "model name", 10) && result->brand_string[0] == 0 ) 
        {
            cpu_cpuinfo_parse_string(str, result->brand_string);
        }
    }

    fclose(fpcpuinfo);

    return result;
}

//  Created by
//  Jacob Milligan on 15/01/2018
//  Copyright (c) 2016 Jacob Milligan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
    CPU_info *result = get_cpu_info(NULL);

    cpu_log_result(stdout, result);

    return 0;
}