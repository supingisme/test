/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:38 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

#define CMD_SIZE    256

int kill_exec_by_pid(const pid_t pid)
{
    char cmd[CMD_SIZE];
    
    memset(cmd, 0, CMD_SIZE);
    
    sprintf(cmd, "ps -e | grep %d | awk '{print $1}'", pid);
    FILE *fp = popen(cmd, "r");
    
    char str_pid[CMD_SIZE];
    if(NULL != fgets(str_pid, 20, fp))
    {
        if(pid == atoi(str_pid))
        {
            memset(cmd, 0, CMD_SIZE);
            sprintf(cmd, "kill -9 %d", pid);
            system(cmd);
        }
    }
    
    return -1;
}

int main()
{
    char cmd[CMD_SIZE];
    char *macExeName = (char *)"a.out";
    
    sprintf(cmd, "ps -e | grep %s | awk '{print $1}'", macExeName);
    
    FILE *fp = popen(cmd, "r");
    
    char str_pid[CMD_SIZE];
    
    while(NULL != fgets(str_pid, 20, fp))
    {
        //printf("PID: %s\n", str_pid);
        memset(cmd, 0, CMD_SIZE);
        sprintf(cmd, "kill -9 %s", str_pid);
        system(cmd);
    }
    pclose(fp);
    
    kill_exec_by_pid(57299);
    
    return 0;
}