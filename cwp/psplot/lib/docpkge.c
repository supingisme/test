/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:48 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:50 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:07 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/*********************** self documentation **********************/
/*************************************************************************** 
DOCPKGE - Function to implement the CWP self-documentation facility

requestdoc	give selfdoc on user request (i.e. when name of main is typed)
pagedoc		print self documentation string

**************************************************************************** 
Function Prototypes:
void requestdoc(flag);
void pagedoc();

**************************************************************************** 
requestoc:
Input:
flag		integer specifying i.o. cases

pagedoc():
Returns:	the self-documentation, an array of strings

**************************************************************************** 
Notes:
requestdoc:
In the usual case, stdin is used to pass in data.  However,
some programs (eg. synthetic data generators) don't use stdin
to pass in data and some programs require two or more arguments
besides the command itself (eg. sudiff) and don't use stdin.
In this last case, we give selfdoc whenever too few arguments
are given, since these usages violate the usual SU syntax.
In all cases, selfdoc can be requested by giving only the
program name.

The flag argument distinguishes these cases:
            flag = 0; fully defaulted, no stdin
            flag = 1; usual case
            flag = n > 1; no stdin and n extra args required

pagedoc:
Intended to be called by requesdoc(), but conceivably could be
used directly as in:
      if (xargc != 3) selfdoc();

Based on earlier versions by:
SEP: Einar Kjartansson, Stew Levin CWP: Jack Cohen, Shuki Ronen
HRC: Lyle

**************************************************************************** 
Author: Jack K. Cohen, Center for Wave Phenomena
****************************************************************************/
/**************** end self doc ********************************/


#include "par.h"
 
/*  definitions of global variables */
int xargc; char **xargv;


void requestdoc(int flag)
/*************************************************************************** 
print selfdocumentation as directed by the user-specified flag
**************************************************************************** 
Notes:
In the usual case, stdin is used to pass in data.  However,
some programs (eg. synthetic data generators) don't use stdin
to pass in data and some programs require two or more arguments
besides the command itself (eg. sudiff) and don't use stdin.
In this last case, we give selfdoc whenever too few arguments
are given, since these usages violate the usual SU syntax.
In all cases, selfdoc can be requested by giving only the
program name.

The flag argument distinguishes these cases:
            flag = 0; fully defaulted, no stdin
            flag = 1; usual case
            flag = n > 1; no stdin and n extra args required

pagedoc:
Intended to be called by pagedoc(), but conceivably could be
used directly as in:
      if (xargc != 3) selfdoc();

**************************************************************************** 
Authors: Jack Cohen, Center for Wave Phenomena, 1993, based on on earlier
versions by:
SEP: Einar Kjartansson, Stew Levin CWP: Jack Cohen, Shuki Ronen
HRC: Lyle
****************************************************************************/
{
        switch(flag) {
        case 1:
                if (xargc == 1 && isatty(STDIN)) pagedoc();
        break;
        case 0:
                if (xargc == 1 && isatty(STDIN) && isatty(STDOUT)) pagedoc();
        break;
        default:
                if (xargc <= flag) pagedoc();
        break;
        }
        return;
}


void pagedoc(void)
{
        extern char *sdoc[];
		char **p = sdoc;
        FILE *fp;
		char *pager;
		char cmd[32];

		if ((pager=getenv("PAGER")) != (char *)NULL)
			sprintf(cmd,"%s 1>&2", pager);
		else 
			sprintf(cmd,"more 1>&2");


        fflush(stdout);
       /*  fp = popen("more -22 1>&2", "w"); */
       /*  fp = popen("more  1>&2", "w"); */
        fp = (FILE *) popen(cmd, "w");
	while(*p) (void)fprintf(fp, "%s\n", *p++);
        pclose(fp);

        exit(EXIT_FAILURE);
}
