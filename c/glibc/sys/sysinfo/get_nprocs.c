/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*

int get_nprocs (void)
The get_nprocs function returns the number of available processors.
This function is a GNU extension.

*/
#include <stdio.h>

#include <unistd.h>
#include <sys/sysinfo.h>


int main()
{
    long int ret = sysconf (_SC_NPROCESSORS_ONLN);
    printf("ret = %d\n", ret);

    ret = get_nprocs ();
    printf("ret = %d\n", ret);
    
    ret = sysconf (_SC_NPROCESSORS_CONF);
    printf("ret = %d\n", ret);
    
    ret = get_nprocs_conf ();
    printf("ret = %d\n", ret);

    
    
    
	return 0;
}
