/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/**
20.7 Floating-Point Control Functions
IEEE 754 ﬂoating-point implementations allow the programmer to decide whether traps
will occur for each of the exceptions, by setting bits in the control word. In C, traps result
in the program receiving the SIGFPE signal; see Chapter 24 [Signal Handling], page 602.
NB: IEEE 754 says that trap handlers are given details of the exceptional situation, and
can set the result value. C signals do not provide any mechanism to pass this information
back and forth. Trapping exceptions in C is therefore not very useful.
It is sometimes necessary to save the state of the ﬂoating-point unit while you perform
some calculation. The library provides functions which save and restore the exception ﬂags,
the set of exceptions that generate traps, and the rounding mode. This information is
known as the ﬂoating-point environment.
The functions to save and restore the ﬂoating-point environment all use a variable of
type fenv_t to store information. This type is defned in ‘fenv.h’. Its size and contents
are implementation-defned. You should not attempt to manipulate a variable of this type
directly.
To save the state of the FPU, use one of these functions:
int fegetenv (fenv t *envp) [Function]
Store the ﬂoating-point environment in the variable pointed to by envp.
The function returns zero in case the operation was successful, a non-zero value oth
erwise.
int feholdexcept (fenv t *envp) [Function]
Store the current ﬂoating-point environment in the object pointed to by envp. Then
clear all exception ﬂags, and set the FPU to trap no exceptions. Not all FPUs
support trapping no exceptions; if feholdexcept cannot set this mode, it returns
nonzero value. If it succeeds, it returns zero.
The functions which restore the ﬂoating-point environment can take these kinds of ar
guments:
• Pointers to fenv_t objects, which were initialized previously by a call to fegetenv or
feholdexcept.
• The special macro FE_DFL_ENV which represents the ﬂoating-point environment as it
was available at program start.
• Implementation defned macros with names starting with FE_ and having type fenv_t
*.
If possible, the GNU C Library defnes a macro FE_NOMASK_ENV which represents an
environment where every exception raised causes a trap to occur. You can test for this
macro using #ifdef. It is only defned if _GNU_SOURCE is defned.
Some platforms might defne other predefned environments.
*/
#include <fenv.h>
#include <stdio.h>
#include <math.h>

//int fegetenv (fenv_t *envp);
#define _print(val) printf("%s:%x\n", #val, val)

int main()
{
    fenv_t envp;
    
    fegetenv(&envp);
    
    _print(FE_);
    _print(envp);
    
    return 0;
}