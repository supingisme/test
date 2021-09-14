/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*
ucontext_t [Data Type]
The ucontext_t type is defned as a structure with as least the following elements:
ucontext_t *uc_link
This is a pointer to the next context structure which is used if the context
described in the current structure returns.
sigset_t uc_sigmask
Set of signals which are blocked when this context is used.
stack_t uc_stack
Stack used for this context. The value need not be (and normally is
not) the stack pointer. See Section 24.9 [Using a Separate Signal Stack],
page 641.
mcontext_t uc_mcontext
This element contains the actual state of the process. The mcontext_t
type is also defned in this header but the defnition should be treated
as opaque. Any use of knowledge of the type makes applications less
portable.

*/

#include <ucontext.h>


struct ucontext_t{
    ucontext_t *uc_link;
    sigset_t uc_sigmask;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
};