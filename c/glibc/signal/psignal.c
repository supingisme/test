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
/*
void psignal (int signum, const char *message) [Function]
This function prints a message describing the signal signum to the standard error
output stream stderr; see Section 12.2 [Standard Streams], page 226.
If you call psignal with a message that is either a null pointer or an empty string,
psignal just prints the message corresponding to signum, adding a trailing newline.
If you supply a non-null message argument, then psignal prefxes its output with
this string. It adds a colon and a space character to separate the message from the
string corresponding to signum.
This function is a BSD feature, declared in the header fle ‘signal.h’.

 */

#include <signal.h>
#include <stdio.h>
#include <string.h>

int main()
{
    psignal(SIGXCPU, "SIGXCPU");
    psignal(SIGFPE, "SIGFPE");
    psignal(SIGSEGV, "SIGSEGV");
    psignal(SIGTRAP, "SIGTRAP");


	return 0;
}
