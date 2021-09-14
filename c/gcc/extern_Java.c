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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/*
 *	java_interface
 *	This type attribute informs C++ that the class is a Java interface. It may
 *	only be applied to classes declared within an extern "Java" block. Calls to
 *	methods declared in this interface will be dispatched using GCJ’s interface table
 *	mechanism, instead of regular virtual table dispatch.
 *	See also Section 7.8 [Namespace Association], page 572.
 */

#include <iostream>

extern "Java"{

class A{
	public int a;
	A(){
		this.a = 1;
	};
	A(int a){
		this.a = a;
	};
};

}


int main()
{
	
}
