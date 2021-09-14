/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 15:21:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 15:00:54 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 15:00:51 CST. */
#include <fcntl.h>
#include <stdio.h>

#define DEV_NAME	"/dev/hello"

int main()
{
	int fd;
	int val=1;

	fd = open(DEV_NAME, O_RDWR);
	if(fd < 0)
		printf("test: can't open %s \n", DEV_NAME);

	write(fd, &val, 4);

	read(fd, &val, 4);

	return 0;
}
