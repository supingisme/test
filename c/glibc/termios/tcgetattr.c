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
 *	17.4.2 Terminal Mode Functions
 *	int tcgetattr (int filedes, struct termios *termios-p) [Function]
 *	This function is used to examine the attributes of the terminal device with file de-
 *	scriptor filedes. The attributes are returned in the structure that termios-p points
 *	to.
 *	If successful, tcgetattr returns 0. A return value of −1 indicates an error. The
 *	following errno error conditions are defned for this function:
 *	EBADF The filedes argument is not a valid fle descriptor.
 *	ENOTTY The filedes is not associated with a terminal.
 */
/*
 *	struct termios{
 *		tcflag_t c_iflag;//输入模式标志，控制终端输入方式
 *		tcflag_t c_oflag;//输出模式标志，控制终端输出方式
 *		tcflag_t c_cflag;//控制模式标志，指定终端硬件控制信息
 *		tcflag_t c_lflag;//本地模式标志，控制终端编辑功能
 *		cc_t c_cc[NCCS];
 *	};
 */
/*
 *	百度百科
 *	用来获取终端参数，
 */

#include <termios.h>

void tcattr_init(int fd)
{
	struct termios tc;	
	tcgetattr( fd, &tc);
	tc.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG );
	tcsetattr( fd, TCSANOW, &tc );
	return;
}
#include <stdio.h>
#include <termios.h>

int tcgetattr(int filedes, struct termios *termios_p);

int main()
{
	tcattr_init(fileno(stdin));
	struct termios t;

	tcgetattr(fileno(stdin), &t);

	printf("c_iflag: %d\n", t.c_iflag);
	printf("c_oflag: %d\n", t.c_oflag);
	printf("c_cflag: %d\n", t.c_cflag);
	printf("c_lflag: %d\n", t.c_lflag);
	int i;
	printf("c_cc: \n");
	for(i=0;i<NCCS; i++)
		printf("%4d,%s", t.c_cc[i], (i+1)%8==0?"\n":" ");

	printf("\n");

	return 0;
}
