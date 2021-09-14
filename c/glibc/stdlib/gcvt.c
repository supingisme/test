/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
 *	char * gcvt (double value, int ndigit, char *buf) [Function]
 *	gcvt is functionally equivalent to ‘sprintf(buf, "%*g", ndigit, value’. It is pro
 *	vided only for compatibility’s sake. It returns buf.
 *	If ndigit decimal digits would exceed the precision of a double it is reduced to a
 *	system-specifc value.
 *
 *
 *
 *	Others funciton
 *
 *	char * qecvt (long double value, int ndigit, int *decpt, int *neg) [Function]
 *	This function is equivalent to ecvt except that it takes a long double for the frst
 *	parameter and that ndigit is restricted by the precision of a long double.
 *	char * qfcvt (long double value, int ndigit, int *decpt, int *neg) [Function]
 *	This function is equivalent to fcvt except that it takes a long double for the frst
 *	parameter and that ndigit is restricted by the precision of a long double.
 *	char * qgcvt (long double value, int ndigit, char *buf) [Function]
 *	This function is equivalent to gcvt except that it takes a long double for the frst
 *	parameter and that ndigit is restricted by the precision of a long double.
 *
 *
 *	int ecvt_r (double value, int ndigit, int *decpt, int *neg, char *buf, [Function]
 *	size t len)
 *	The ecvt_r function is the same as ecvt, except that it places its result into the
 *	user-specifed buﬀer pointed to by buf, with length len. The return value is -1 in case
 *	of an error and zero otherwise.
 *	This function is a GNU extension.
 *	int fcvt_r (double value, int ndigit, int *decpt, int *neg, char *buf, [Function]
 *	size t len)
 *	The fcvt_r function is the same as fcvt, except that it places its result into the
 *	user-specifed buﬀer pointed to by buf, with length len. The return value is -1 in case
 *	of an error and zero otherwise.
 *	This function is a GNU extension.
 *	int qecvt_r (long double value, int ndigit, int *decpt, int *neg, char [Function]
 *	*buf, size t len)
 *	The qecvt_r function is the same as qecvt, except that it places its result into the
 *	user-specifed buﬀer pointed to by buf, with length len. The return value is -1 in case
 *	of an error and zero otherwise.
 *	This function is a GNU extension.
 *
 *
 *	int qfcvt_r (long double value, int ndigit, int *decpt, int *neg, char [Function]
 *	*buf, size t len)
 *	The qfcvt_r function is the same as qfcvt, except that it places its result into the
 *	user-specifed buﬀer pointed to by buf, with length len. The return value is -1 in case
 *	of an error and zero otherwise.
 *	This function is a GNU extension.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int main()
{
	char *buf = malloc(256);
	gcvt(123.123, 6, buf);

	printf("%s\n", buf);
}	
