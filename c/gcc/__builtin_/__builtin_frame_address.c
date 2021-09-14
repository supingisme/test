/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	void * __builtin_frame_address (unsigned int level) [Built-in Function]
 *	This function is similar to __builtin_return_address, but it returns the address of
 *	the function frame rather than the return address of the function. Calling __builtin_
 *	frame_address with a value of 0 yields the frame address of the current function, a
 *	value of 1 yields the frame address of the caller of the current function, and so forth.
 *	The frame is the area on the stack which holds local variables and saved registers.
 *	The frame address is normally the address of the frst word pushed on to the stack
 *	by the function. However, the exact defnition depends upon the processor and the
 *	calling convention. If the processor has a dedicated frame pointer register, and the
 *	function has a frame, then __builtin_frame_address will return the value of the
 *	frame pointer register.
 *	On some machines it may be impossible to determine the frame address of any function
 *	other than the current one; in such cases, or when the top of the stack has been
 *	reached, this function will return 0 if the frst frame pointer is properly initialized by
 *	the startup code.
 *	This function should only be used with a nonzero argument for debugging purposes.
 */

#include <stdio.h>

int main()
{
	printf("%p\n", __builtin_frame_address(0));
	return 0;
}
