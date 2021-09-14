/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/**
int cfsetospeed (struct termios *termios-p, speed t speed) [Function]
This function stores speed in *termios-p as the output speed. The normal return
value is 0; a value of −1 indicates an error. If speed is not a speed, cfsetospeed
returns −1.
*/
#include <stdio.h>
#include <termios.h>

//typedef unsigned int speed_t;

//int cfsetospeed (struct termios *termios_p, speed_t speed);

int main()
{
	struct termios t;

	//tcgetattr(fileno(stdout), &t);

    cfsetispeed(&t, 10);
    
	speed_t speedo = cfgetospeed(&t);

	printf("%d\n", speedo);

	speed_t speedi = cfgetispeed(&t);

	printf("%d\n", speedi);

	return 0;
}