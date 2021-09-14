/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:40 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:24 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <libgen.h>

int reject_ch_from_string(char *str, const char ch)
{    
    if(str == NULL)    
    {        
        return -1;    
    }    
    
    int ilen, len = strlen(str);  
    
    for(ilen=0; ilen < len; ilen++)    
    {        
        if(str[ilen] == ch)        
        {            
            int i;            
            for(i=ilen; i<len-1; i++)            
            {                
                str[i] = str[i+1];            
            }            
            str[len-1] = '\0';            
            len--;     
            //printf("%s:%c, %d\n", str, ch, len);
        }    
    }    
    return 0;
}

int is_pid_alive_with_pname(const pid_t pid, const char *pname)
{
	if(pname == NULL)
	{
		return -1;
	}
	int ret1 = -1, ret2 = -1;
    char cmd[256], line[256];
    memset(cmd, 0, 256);
    memset(line, 0, 256);
    
    sprintf(cmd, "ps -ef | grep %d | awk '{print $2}'", pid);
    FILE *fp = popen(cmd, "r");
    while(fgets(line, 256, fp) != NULL)
    {
        int pid_tmp = atoi(line);
        if(pid == pid_tmp)
        {
            ret1 = 0;
        }
    }
    fclose(fp);

	memset(cmd, 0, 256);
	sprintf(cmd, "ps -ef | grep %s | awk '{print $8}'", pname);
	fp = popen(cmd, "r");
    
	while(fgets(line, 256, fp) != NULL)
	{
        char *tmp = malloc(sizeof(char)*256);
        memset(tmp, 0, 256);
        memcpy(tmp, basename(line), strlen(basename(line)));
        reject_ch_from_string(tmp, '\n');
		if(strcmp(tmp, basename(pname)) == 0)
		{
			ret2 = 0;
		}
        free(tmp);
	}
	fclose(fp);

    return ret1<ret2?ret1:ret2;
}


int main(int argc, char *argv[])
{
	if(is_pid_alive_with_pname(atoi(argv[1]), argv[2]) == 0)
	{
		printf("alive\n");
	}
	else
	{
		printf("not exist\n");
	}

	return 0;
}

