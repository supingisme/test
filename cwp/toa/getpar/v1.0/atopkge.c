/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:49 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:34 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

#include "getpars.h"

#include <errno.h>

/* eatoh - convert string s to short integer {SHRT_MIN:SHRT_MAX} */
short eatoh(char *s)
{
	long n = strtol(s, NULL, 10);
	
	if ( (n > SHRT_MAX) || (n < SHRT_MIN) || (errno == ERANGE) )
		log_msg_vcm_error("%s: eatoh: overflow", __FILE__);

	return (short) n;
}


/* eatou - convert string s to unsigned short integer {0:USHRT_MAX} */
unsigned short eatou(char *s)
{
	unsigned long n = strtoul(s, NULL, 10);

	if ( (n > USHRT_MAX) || (errno == ERANGE) )
		log_msg_vcm_error("%s: eatou: overflow", __FILE__);

	return (unsigned short) n;
}


/* eatoi - convert string s to integer {INT_MIN:INT_MAX} */
int eatoi(char *s)
{
	long n = strtol(s, NULL, 10);

	if ( (n > INT_MAX) || (n < INT_MIN) || (errno == ERANGE) )
		log_msg_vcm_error("%s: eatoi: overflow", __FILE__);

	return (int) n;
}


/* eatop - convert string s to unsigned integer {0:UINT_MAX} */
unsigned int eatop(char *s)
{
	unsigned long n = strtoul(s, NULL, 10);

	if ( (n > UINT_MAX) || (errno == ERANGE) )
		log_msg_vcm_error("%s: eatop: overflow", __FILE__);

	return (unsigned int) n;
}


/* eatol - convert string s to long integer {LONG_MIN:LONG_MAX} */
long eatol(char *s)
{
	long n = strtol(s, NULL, 10);

	if (errno == ERANGE)
		log_msg_vcm_error("%s: eatol: overflow", __FILE__);

	return n;
}


/* eatov - convert string s to unsigned long {0:ULONG_MAX} */
unsigned long eatov(char *s)
{
	unsigned long n = strtoul(s, NULL, 10);

	if (errno == ERANGE)
		log_msg_vcm_error("%s: eatov: overflow", __FILE__);

	return n;
}


/* eatof - convert string s to float {-FLT_MAX:FLT_MAX} */
float eatof(char *s)
{
	float x = strtod(s, NULL);

	if ( (x > FLT_MAX) || (x < -FLT_MAX) || (errno == ERANGE) )
		log_msg_vcm_error("%s: eatof: overflow", __FILE__);

	return (float) x;
}


/* eatod - convert string s to double {-DBL_MAX:DBL_MAX} */
double eatod(char *s)
{
	double x = strtod(s, NULL);

	/* errno == ERANGE suffices if compiler sets errno on overflow */
	if ( (errno == ERANGE) || (x > DBL_MAX) || (x < -DBL_MAX) )
		log_msg_vcm_error("%s: eatod: overflow", __FILE__);

	return x;
}

