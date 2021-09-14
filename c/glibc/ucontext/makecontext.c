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

void makecontext (ucontext t *ucp, void (*func) (void), int argc, . . .) [Function]
The ucp parameter passed to the makecontext shall be initialized by a call to
getcontext. The context will be modifed to in a way so that if the context is
resumed it will start by calling the function func which gets argc integer arguments
passed. The integer arguments which are to be passed should follow the argc param
eter in the call to makecontext.
Before the call to this function the uc_stack and uc_link element of the ucp structure
should be initialized. The uc_stack element describes the stack which is used for
this context. No two contexts which are used at the same time should use the same
memory region for a stack.
The uc_link element of the object pointed to by ucp should be a pointer to the
context to be executed when the function func returns or it should be a null pointer.
See setcontext for more information about the exact use.
*/

#include <ucontext.h>
#include <stdio.h>

// struct ucontext_t{
    // ucontext_t *uc_link;
    // sigset_t uc_sigmask;
    // stack_t uc_stack;
    // mcontext_t uc_mcontext;
// };
ucontext_t ucp;



//void makecontext (ucontext t *ucp, void (*func) (void), int argc, . . .)

void func(void)
{
    printf("%s---------------\n", __func__);
}

int main()
{
    
    
    getcontext(&ucp);
    
    printf("%s---------------\n", __func__);
    makecontext(&ucp, func, 1); //段错误啦
    
    return 0;
}