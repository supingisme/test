/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/**
 *	int gtty (int filedes, struct sgttyb *attributes) [Function]
 *	This function gets the attributes of a terminal.
 *	gtty sets *attributes to describe the terminal attributes of the terminal which is open
 *	with fle descriptor fledes.
 *
 *	int stty (int filedes, struct sgttyb * attributes) [Function]
 *	This function sets the attributes of a terminal.
 *	stty sets the terminal attributes of the terminal which is open with fle descriptor
 *	fledes to those described by *fledes.
 */

#include <stdio.h>
#include <sgtty.h>
#include <stdlib.h>

struct sgttyb_self
{
	char sg_ispeed;
	char sg_ospeed;
	char sg_erase;
	char sg_kill;
	int sg_flags;
};

int main()
{
	struct sgttyb_self st;

	gtty(fileno(stdout),(struct sgttyb *) &st);

	printf("%c, %c, %c, %c, %d\n", 
			st.sg_ispeed, st.sg_ospeed, st.sg_erase, st.sg_kill, st.sg_flags);

	
	stty(fileno(stdout), (struct sgttyb *)&st);


	return 0;
}
