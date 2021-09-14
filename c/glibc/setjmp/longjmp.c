/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/**
 * 感觉像是goto，但是比goto跳的更远
 *
 *
void longjmp (jmp buf state, int value) [Function]
This function restores current execution to the state saved in state, and continues
execution from the call to setjmp that established that return point. Returning from
setjmp by means of longjmp returns the value argument that was passed to longjmp,
rather than 0. (But if value is given as 0, setjmp returns 1).
There are a lot of obscure but important restrictions on the use of setjmp and longjmp.
Most of these restrictions are present because non-local exits require a fair amount of magic
on the part of the C compiler and can interact with other parts of the language in strange
ways.
The setjmp function is actually a macro without an actual function defnition, so you
shouldn’t try to ‘#undef’ it or take its address. In addition, calls to setjmp are safe in only
the following contexts:
• As the test expression of a selection or iteration statement (such as ‘if’, ‘switch’, or
‘while’).
• As one operand of a equality or comparison operator that appears as the test expression
of a selection or iteration statement. The other operand must be an integer constant
expression.
• As the operand of a unary ‘!’ operator, that appears as the test expression of a selection
or iteration statement.
• By itself as an expression statement.
Return points are valid only during the dynamic extent of the function that called setjmp
to establish them. If you longjmp to a return point that was established in a function that
has already returned, unpredictable and disastrous things are likely to happen.
You should use a nonzero value argument to longjmp. While longjmp refuses to pass
back a zero argument as the return value from setjmp, this is intended as a safety net
against accidental misuse and is not really good programming style.
When you perform a non-local exit, accessible objects generally retain whatever values
they had at the time longjmp was called. The exception is that the values of automatic
variables local to the function containing the setjmp call that have been changed since the
call to setjmp are indeterminate, unless you have declared them volatile.
*/

#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>


jmp_buf main_loop;

void abort_to_main_loop (int status)
{
    printf("%s\n", __func__);
    longjmp (main_loop, status);
}

void do_command (void)
{
    printf("%s\n", __func__);
    char buffer[128];
    if (fgets (buffer, 128, stdin) == NULL)
        abort_to_main_loop (-1);
    else
        abort_to_main_loop (1);;
}

int main (void)
{
    while (1)
    if (setjmp (main_loop))
        puts ("Back at main loop....");
    else
        do_command ();
}


