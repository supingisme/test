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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/*	
 *	c语言限定符，告诉编译器，对象已经被指针所引用，不能通过除该指针外所有其他直接或间接的方式修改
 *	该对象的内容
 *
 *
 *	7.2 Restricting Pointer Aliasing
 *	As with the C front end, G++ understands the C99 feature of restricted pointers, specifed
 *	with the __restrict__, or __restrict type qualifer. Because you cannot compile C++ by
 *	specifying the ‘-std=c99’ language ﬂag, restrict is not a keyword in C++.
 *	In addition to allowing restricted pointers, you can specify restricted references, which
 *	indicate that the reference is not aliased in the local context.
 *	void fn (int *__restrict__ rptr, int &__restrict__ rref)
 *	{
 *
	}

In the body of fn, rptr points to an unaliased integer and rref refers to a (diﬀerent) unaliased
integer.
You may also specify whether a member function’s this pointer is unaliased by using
__restrict__ as a member function qualifer.
void T::fn () __restrict__
{
	//
}
Within the body of T::fn, this will have the eﬀective defnition T *__restrict__ const
this. Notice that the interpretation of a __restrict__ member function qualifer is diﬀer
ent to that of const or volatile qualifer, in that it is applied to the pointer rather than
the object. This is consistent with other compilers which implement restricted pointers.
As with all outermost parameter qualifers, __restrict__ is ignored in function defnition
matching. This means you only need to specify __restrict__ in a function defnition,
	rather than in a function prototype as well.
 */

#include <stdio.h>

void fn (int *__restrict__ rptr, int* __restrict__ rref)
{
	/* . . . */
#if 0
	int *p  = rptr;
	*p = 12;
#else
	*rptr = 12;
#endif
}

int main()
{
	int *p1, *p2;
	fn(p1, p2);

}
