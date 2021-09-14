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
int getloadavg (double loadavg[], int nelem) [Function]
This function gets the 1, 5 and 15 minute load averages of the system. The values are
placed in loadavg. getloadavg will place at most nelem elements into the array but
never more than three elements. The return value is the number of elements written
to loadavg, or -1 on error.
This function is declared in ‘stdlib.h’.


*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

//int getloadavg (double loadavg[], int nelem)

int main()
{
    double loadavg[5];
    long int ret = getloadavg (loadavg, 5);
    printf("ret = %d\n", ret);

    int i=0;
    for(i=0;i<5;i++)
    {
        printf("%lf\n", loadavg[i]);
    }
    
    
    
	return 0;
}
