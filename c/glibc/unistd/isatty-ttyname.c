/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
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

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*	
 dentifying Terminals
 The functions described in this chapter only work on fles that correspond to terminal
 devices. You can fnd out whether a fle descriptor is associated with a terminal by using
 the isatty function.
 Prototypes for the functions in this section are declared in the header fle ‘unistd.h’.
 int isatty (int filedes) [Function]
 This function returns 1 if fledes is a fle descriptor associated with an open terminal
 device, and 0 otherwise.
 If a fle descriptor is associated with a terminal, you can get its associated fle name
 using the ttyname function. See also the ctermid function, described in Section 27.7.1
 [Identifying the Controlling Terminal], page 714.
 char * ttyname (int filedes) [Function]
 If the fle descriptor fledes is associated with a terminal device, the ttyname function
 returns a pointer to a statically-allocated, null-terminated string containing the fle
 name of the terminal fle. The value is a null pointer if the fle descriptor isn’t
 associated with a terminal, or the fle name cannot be determined.
 int ttyname_r (int filedes, char *buf, size t len) [Function]
 The ttyname_r function is similar to the ttyname function except that it places its
 result into the user-specifed buﬀer starting at buf with length len.
 The normal return value from ttyname_r is 0. Otherwise an error number is re
 turned to indicate the error. The following errno error conditions are defned for this
function:
EBADF The fledes argument is not a valid fle descriptor.
ENOTTY The fledes is not associated with a terminal.
ERANGE The buﬀer length len is too small to store the string to be returned.
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *fp = fopen("tmp.out", "w");
    
	printf("%s: %d\n", ttyname(fileno(stdin)), isatty(fileno(stdin)));
	printf("%s: %d\n", ttyname(fileno(stdout)), isatty(fileno(stdout)));
	printf("%s: %d\n", ttyname(fileno(stderr)), isatty(fileno(stderr)));
	printf("%s: %d\n", ttyname(fileno(fp)), isatty(fileno(fp)));
    
    fclose(fp);

	return 0;
}
