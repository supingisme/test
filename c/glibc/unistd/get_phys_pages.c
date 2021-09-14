/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*

long int get_phys_pages (void) [Function]
The get_phys_pages function returns the total number of pages of physical the sys
tem has. To get the amount of memory this number has to be multiplied by the page
size.
This function is a GNU extension.

*/
#include <stdio.h>

#include <unistd.h>


int main()
{
    long int ret = getpagesize();
    printf("ret = %d\n", ret);
    
    
    /*
    Widely available on System V derived systems is a method to get 
    information about the physical memory the system has. The call
    sys/sysinfo.h
    */
    ret = sysconf (_SC_PHYS_PAGES);
    printf("ret = %d\n", ret);
    
    
    ret = sysconf (_SC_AVPHYS_PAGES);
    printf("ret = %d\n", ret);
    
    ret = get_phys_pages();
    printf("ret = %d\n", ret);
    
	return 0;
}
