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
 *	17.4.3 Setting Terminal Modes Properly
 *	When you set terminal modes, you should call tcgetattr frst to get the current modes of
 *	the particular terminal device, modify only those modes that you are really interested in,
 *	and store the result with tcsetattr.
 *	It’s a bad idea to simply initialize a struct termios structure to a chosen set of at
 *	tributes and pass it directly to tcsetattr. Your program may be run years from now, on
 *	systems that support members not documented in this manual. The way to avoid setting
 *	these members to unreasonable values is to avoid changing them.
 *	What’s more, diﬀerent terminal devices may require diﬀerent mode settings in order to
 *	function properly. So you should avoid blindly copying attributes from one terminal device
 *	to another.
 *	When a member contains a collection of independent ﬂags, as the c_iflag, c_oflag
 *	and c_cflag members do, even setting the entire member is a bad idea, because particular
 *	operating systems have their own ﬂags. Instead, you should start with the current value
 *	of the member and alter only the ﬂags whose values matter in your program, leaving any
 *	other ﬂags unchanged.
 *	Here is an example of how to set one ﬂag (ISTRIP) in the struct termios structure
 *	while properly preserving all the other data in the structure:
 */
#include <stdio.h>
#include <termios.h>

int set_istrip (int desc, int value)
{
	struct termios settings;
	int result;
	result = tcgetattr (desc, &settings);
	if (result < 0)
	{
		perror ("error in tcgetattr");
		return 0;
	}
	settings.c_iflag &= ~ISTRIP;
	if (value)
		settings.c_iflag |= ISTRIP;
	result = tcsetattr (desc, TCSANOW, &settings);
	if (result < 0)
	{
		perror ("error in tcsetattr");
		return 0;
	}
	return 1;
}

int main()
{
	set_istrip(fileno(stdin), 1);

	return 0;
}
