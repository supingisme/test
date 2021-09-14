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
#include <sys/ioctl.h>

#define _PRINTER_COLOR

int progress_bar(const int iTotal, const int Total)
{
    int percent, ic=0, i, itotal, total;
    struct winsize sz;
    ioctl(0, TIOCGWINSZ, &sz);
    int term_x = sz.ws_col;
    
    if(term_x < 15)
    {
        return -1;
    }
    else
    {
        term_x -= 10;
        itotal = (int)(iTotal*1.0/Total*term_x);
        total  = term_x;
    }
    
    printf("[");
    ic++;
    for(percent=0; percent<=total; percent++)
    {
        if(percent<=itotal)
        {
#ifdef _PRINTER_COLOR
            printf("\033[47m \033[m");   
#else 
            printf("#"); 
#endif
        }
        else
        {
            printf(" ");
        }
        ic++;
    }
#ifdef _PRINTER_COLOR
    printf("]");
    ic++;
    for(i=0; i<ic-1; i++) { printf("\b"); }
    ic = 1;
    printf("\033[1;47m%3d%%\033[m", (int)(itotal*100.0/total));
    ic += 4;
#else
    printf("]%3d%%", (int)(itotal*100.0/total));
    ic += 5;
#endif
    fflush(stdout);
    for(i=0; i<ic; i++) { printf("\b"); }
    
    return 0;
}

int main()
{
    int percent, whole, interval;
    
    whole       = 120;
    interval    = 1;
    
    for(percent = 0; percent <= whole; percent+=interval)
    {
        progress_bar(percent, whole);
        
        usleep(500*120);
    }
    printf("\n");

    return 0;
}
