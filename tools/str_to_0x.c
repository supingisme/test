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
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define MAC	"00:0c:29:73:ad:23"

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
        }    
    }    
    return 0;
}

uint8_t char_to_0x(char ch)
{
    switch(ch)
    {
        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '8': case '9': 
            return ch - '0';
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            return (uint8_t)(ch - 'a' + 10);
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            return (uint8_t)(ch - 'A' + 10);
        default:
            return (uint8_t)0;
    }	
}

int mac_str_to_0x(uint8_t *mac, uint8_t *mac_str)
{
    if(mac == NULL || mac_str == NULL)
    {
        return -1;
    }
    memcpy(mac_str, MAC, sizeof(MAC));
    
    reject_ch_from_string(mac_str, ':');
    
    uint8_t flag = 0;
    
    int i;
	uint8_t ch[2];
    
    for(i=0; i<6; i++)
	{
        flag = 0x0;
        mac[i] = 0x0;
        
		ch[0] = mac_str[2*i];
		ch[1] = mac_str[2*i+1];

        flag = (char_to_0x(ch[0])<<4) | char_to_0x(ch[1]);
        
        mac[i] = (uint8_t)flag;
	}
    
    return 0;
}

int main()
{
	uint8_t *mac = malloc(6);

	uint8_t mac_str[sizeof(MAC)];
	
	mac_str_to_0x(mac, mac_str);
    
	printf("%s -- %s: 0x %#02x %#02x %#02x %#02x %#02x %#02x\n", 
            MAC, mac_str, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

	return 0;
}
