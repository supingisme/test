/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:29 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/**
 *	Whenever out-of-band data is received, there is an associated out-of-band mark. 
 *	This is the position in the normal stream of data at the sender when the sending 
 *	process sent the out-of-band byte. The receiving process determines whether or 
 *	not it is at the out-of-band mark by calling the sockatmark function while it 
 *	reads from the socket.
 */

#include <sys/socket.h>
//int sockatmark(int sockfd) ;
//Returns: 1 if at out-of-band mark, 0 if not at mark, –1 on error
//

#include <stdio.h>
#include <stdlib.h>

//determine whether socket is at out-of-band mark
int Sockatmark(int fd)
{
	int flag;
	if(ioctl(fd, SIOCATMARK, &flag) < 0)
		return -1;

	printf("flag = %d\n", flag);

	return (flag != 0);
}

int main()
{

	/**
	 *	决定描述符是否是带外数据out-of-band data
	 */
	printf("%d\n", Sockatmark(1));
	printf("%d\n", sockatmark(1));


	return 0;
}
