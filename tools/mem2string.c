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
#include <string.h>
#include <malloc.h>
#include <stdint.h>


struct Msg{
    uint16_t type;
    uint16_t code;
    uint32_t len;
    int8_t rslt;
    uint32_t arg;
}__attribute__((packed));


int mem2show(void *p1, void *p2, int nbytes, int col)
{
    if(p1 == NULL)
    {
        return -1;
    }
    uint8_t *byte1;
    byte1 = p1;

    int ibyte;
    for(ibyte=0; ibyte<nbytes; ibyte++)
    {
        fprintf(stdout, "%02x ", *byte1);
        byte1++;
        if((ibyte+1)%col == 0)
        {
            fprintf(stdout, "\n");
        }
    }
    fprintf(stdout, "\n");
    fflush(stdout);
    return 0;
}

int mem2showcmp(void *p1, void *p2, int nbytes, int col)
{
    if(p1 == NULL || p2 == NULL || nbytes <= 0 || col <= 0)
	{
		return -1;
	}
    uint8_t *byte1, *byte2;
    byte1 = p1;
    byte2 = p2;

    int ibyte, i1, i2, i11 = 0, i22 = 0;
    do{
        for(i1=0; i1<col; i1++)
        {
            i11++;
            if(i11 > nbytes)
            {
                i11--;
                fprintf(stdout, "   ");
            }
            else
            {
                fprintf(stdout, "%02x ", *byte1);
                byte1++;
            }
        }
        fprintf(stdout, " | ");
        for(i2=0; i2<col; i2++)
        {
            i22++;
            if(i22 > nbytes)
            {
                i22--;
                fprintf(stdout, "   ");
            }
            else
            {
                fprintf(stdout, "%02x ", *byte2);
                byte2++;
            }
        }
        fprintf(stdout, " \n");
    }while(i11 < nbytes && i22 < nbytes);

    
    fflush(stdout);
    return 0;
}



int main()
{
    struct Msg msg = {0xf2a1,0x0102,0x03040506,0x07,0x08091011};

    void *p = &msg;
    
    
    mem2showcmp(&msg, p+1, 29, 8);

    return 0;
}
