/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:12 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:14:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:23 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//volatile struct two_words { int a, b; } memory;

static pid_t pid = 0;

void check_pid_exist()
{
	printf("%s\n", __func__);

	char cmd[256], line[256];
	memset(cmd, 0, 256);
	memset(cmd, 0, 256);

	sprintf(cmd, "ps -ef | grep %d | awk '{print $2}'", pid);
	FILE *fp = popen(cmd, "r");
	while(fgets(line, 256, fp) != NULL)
	{
		int pid_tmp = atoi(line);
		if(pid == pid_tmp)
			printf("exit: %d:%d\n", pid, pid_tmp);
		else
			printf("not exit: %d:%d\n", pid, pid_tmp);
	}
	fclose(fp);
}


void handler(int signum)
{
	

    check_pid_exist();
    alarm (1);
}

int main (int argc, char *argv[])
{    
	if(argc < 2)
	{
		printf("Usage: %s [pid]\n", argv[0]);
		exit(1);
	}
	
	//pid = atoi(argv[1]);

	pid = getpid();

    signal (SIGALRM, handler);
        
    alarm (1);
 
	while (1)
    {
        
        
    }
}
