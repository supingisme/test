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
 *	void setutent (void) [Function]
 *	This function opens the user accounting database to begin scanning it. You can then
 *	call getutent, getutid or getutline to read entries and pututline to write entries.
 *	If the database is already open, it resets the input to the beginning of the database.
 *
 *
 *	struct utmp * getutent (void) [Function]
 *	The getutent function reads the next entry from the user accounting database. It
 *	returns a pointer to the entry, which is statically allocated and may be overwritten
 *	by subsequent calls to getutent. You must copy the contents of the structure if you
 *	wish to save the information or you can use the getutent_r function which stores
 *	the data in a user-provided buﬀer.
 *	A null pointer is returned in case no further entry is available.
 *
 *
 */
 /*

struct utmp * pututline (const struct utmp *utmp) [Function]
The pututline function inserts the entry *utmp at the appropriate place in the user
accounting database. If it fnds that it is not already at the correct place in the
database, it uses getutid to search for the position to insert the entry, however this
will not modify the static structure returned by getutent, getutid and getutline.
If this search fails, the entry is appended to the database.
The pututline function returns a pointer to a copy of the entry inserted in the user
accounting database, or a null pointer if the entry could not be added. The following
errno error conditions are defned for this function:
EPERM The process does not have the appropriate privileges; you cannot modify
the user accounting database.

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
    
    struct utmp *utmp2 = pututline(utmp);
    printf("ut_user: %s\n", utmp2->ut_user);
	printf("ut_line: %s\n", utmp2->ut_line);
	printf("ut_id: %s\n", utmp2->ut_id);
	printf("ut_host: %s\n", utmp2->ut_host);
    
	endutent();

	return 0;
}
