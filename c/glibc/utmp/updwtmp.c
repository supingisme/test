/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:36 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:37 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:08 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:20 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
/*
void updwtmp (const char *wtmp_file, const struct utmp *utmp) [Function]
The updwtmp function appends the entry *utmp to the database specifed by
wtmp fle. For possible values for the wtmp fle argument see the utmpname
function.
Portability Note: Although many operating systems provide a subset of these functions,
they are not standardized. There are often subtle diﬀerences in the return types, and
there are considerable diﬀerences between the various defnitions of struct utmp. When
programming for the GNU system, it is probably best to stick with the functions described
in this section. If however, you want your program to be portable, consider using the
XPG functions described in Section 29.12.2 [XPG User Accounting Database Functions],
page 742, or take a look at the BSD compatible functions in Section 29.12.3 [Logging In
and Out], page 744.

*/

#include <utmp.h>
#include<stdio.h>

int main()
{
    setutent();

	struct utmp *utmp = getutent();

    
	printf("ut_type: %d\n", utmp->ut_type);
	printf("ut_user: %s\n", utmp->ut_user);
	printf("ut_line: %s\n", utmp->ut_line);
	printf("ut_id: %s\n", utmp->ut_id);
	printf("ut_host: %s\n", utmp->ut_host);
    /*
    ut_user: reboot
    ut_line: ~
    ut_id: ~~
    ut_host: 3.10.0-693.el7.x86_64
    */
    
	updwtmp("/home/RongTao/test/c/libc/utmp/wtmp.out", utmp);

	return 0;
}
