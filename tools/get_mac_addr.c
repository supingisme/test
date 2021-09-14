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
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define INT32   int32_t

INT32 reject_ch_from_string(char *str, const char ch)
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
        }
    }
    return 0;
}

INT32 get_host_mac_addr_by_network_card(char *mac)
{
#define ETHER "ether"

    FILE *fp  = popen("ifconfig virbr0:2", "r");
    
    char str[256], tmp[256];
    
    while(fgets(str, 256, fp))
    {
        memset(tmp, 0, sizeof(tmp));
        memset(mac, 0, sizeof(mac));
        
        sscanf(str, "%s %s", tmp, mac);
        if(strncmp(ETHER, tmp, 
                   strlen(ETHER)>strlen(tmp)?strlen(ETHER):strlen(tmp)) == 0)
        {
            reject_ch_from_string(mac, ':');
            return 0;
        }
    }
    return -1;
}

int main()
{
    char mac[256];
    get_host_mac_addr_by_network_card(mac);
    printf("%s\n", mac);
    
    return 0;
}
