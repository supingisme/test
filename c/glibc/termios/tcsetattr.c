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
/*	int tcsetattr (int filedes, int when, const struct termios [Function]
 *	*termios-p)
 *	This function sets the attributes of the terminal device with fle descriptor fledes.
 *	The new attributes are taken from the structure that termios-p points to.
 *	The when argument specifes how to deal with input and output already queued. It
 *	can be one of the following values:
 *	TCSANOW Make the change immediately.
 *	TCSADRAIN
 *	Make the change after waiting until all queued output has been written.
 *	You should usually use this option when changing parameters that aﬀect
 *	output.
 *	TCSAFLUSH
 *	This is like TCSADRAIN, but also discards any queued input.
 *	TCSASOFT This is a ﬂag bit that you can add to any of the above alternatives. Its
 *	meaning is to inhibit alteration of the state of the terminal hardware. It
 *	is a BSD extension; it is only supported on BSD systems and the GNU
 *	system.
 *	Using TCSASOFT is exactly the same as setting the CIGNORE bit in the
 *	c_cflag member of the structure termios-p points to. See Section 17.4.6
 *	[Control Modes], page 440, for a description of CIGNORE.
 *
 *
 */
#include <stdio.h>
#include <termios.h>

int main()
{
	struct termios t;

    /*default*/
	t.c_iflag = 1280;
	t.c_oflag = 5;
	t.c_cflag = 191;
	t.c_lflag = 35387;
    
    t.c_iflag = 1400;
	t.c_oflag = 5;
	t.c_cflag = 191;
	t.c_lflag = 35387;
    
	int i;
	for(i=0;i<NCCS; i++)
		t.c_cc[i] = i;

    

	tcsetattr(fileno(stdin), TCSANOW, &t);
    
    
    tcgetattr(fileno(stdin), &t);

	printf("c_iflag: %d\n", t.c_iflag);
	printf("c_oflag: %d\n", t.c_oflag);
	printf("c_cflag: %d\n", t.c_cflag);
	printf("c_lflag: %d\n", t.c_lflag);
	//int i;
	printf("c_cc: \n");
	for(i=0;i<NCCS; i++)
		printf("%4d,%s", t.c_cc[i], (i+1)%8==0?"\n":" ");
    
	return 0;
}
