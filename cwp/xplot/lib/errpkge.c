/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:51 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:51 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:35 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/*********************** self documentation **********************/
/**************************************************************************
ERRPKGE - routines for reporting errors

err	print warning on application program error and die
warn	print warning on application program error
syserr	print warning on application program error using errno and die

***************************************************************************
Function Prototypes:
void err (char *fmt, ...);
void warn (char *fmt, ...);
void syserr (char *fmt, ...);

***************************************************************************
Return: void

***************************************************************************
Notes:
fmt		a printf format string ("\n" not needed)
...		the variables referenced in the format string

Examples:
	err("Cannot divide %f by %f", x, y);
	warn("fmax = %f exceeds half nyquist= %f", fmax, 0.25/dt);
 
	if (NULL == (fp = fopen(xargv[1], "r")))
 		err("can't open %s", xargv[1]);
 	...
 	if (-1 == close(fd))
 		err("close failed");

***************************************************************************
References:
Kernighan and Pike, "The UNIX Programming Environment", page 207.
Also Rochkind, "Advanced UNIX Programming", page 13.

***************************************************************************
Authors:SEP: Jeff Thorson, Stew Levin	CWP: Shuki Ronen, Jack Cohen
**************************************************************************/
/**************** end self doc ********************************/

#include <stdarg.h>
#include "par.h"

void err(char *fmt, ...)
{
	va_list args;

 
	if (EOF == fflush(stdout)) {
		fprintf(stderr, "\nerr: fflush failed on stdout");
	}
	fprintf(stderr, "\n%s: ", xargv[0]);
	va_start(args,fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}


void warn(char *fmt, ...)
{
	va_list args;

	if (EOF == fflush(stdout)) {
		fprintf(stderr, "\nwarn: fflush failed on stdout");
	}
	fprintf(stderr, "\n%s: ", xargv[0]);
	va_start(args,fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, "\n");
	return;
}


#ifndef SUN_A
#include <errno.h>
void syserr(char *fmt, ...)
{
	va_list args;

	if (EOF == fflush(stdout)) {
		fprintf(stderr, "\nsyserr: fflush failed on stdout");
	}
	fprintf(stderr, "\n%s: ", xargv[0]);
	va_start(args,fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, " (%s)\n", strerror(errno));
	exit(EXIT_FAILURE);
}
#else
void syserr(char *fmt, ...)
{
	va_list args;

	if (EOF == fflush(stdout)) {
		fprintf(stderr, "\nsyserr: fflush failed on stdout");
	}
	fprintf(stderr, "\n%s: ", xargv[0]);
	va_start(args,fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, " (%s)\n");
	exit(EXIT_FAILURE);
}
#endif /* end of SUN_A */

#ifdef TEST
main(int argc, char **argv)
{
	FILE *fp;
	float fmax, dt=0.004, nyq,  x=1.0, y=0.0;

	initargs(argc, argv);

	nyq = 1.0/(2.0*dt); fmax = nyq/2.0 + .01;

	fprintf(stderr, "\nTrue values:\n");
	fprintf(stderr, "fmax=%f, half nyquist=%f\n", fmax, 0.25/dt);
	fprintf(stderr, "filename=%s\n", xargv[1]);
	fprintf(stderr, "x=%f, y=%f\n\n", x, y);

 	warn("warn: fmax = %f exceeds half nyquist= %f", fmax, 0.25/dt);

 	warn("warn: Cannot divide x=%f by y=%f", x, y);
	
  	if (NULL == (fp = fopen(xargv[1], "r")))
		err("err: can't open %s", xargv[1]);

	return EXIT_SUCCESS;
}
#endif
