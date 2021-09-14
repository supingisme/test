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

#include "cwp.h"

/*********************** self documentation **********************/
/******************************************************************
STRSTUFF -- STRing manuplation subs

cwp_strdup -  duplicate a string
strchop - chop off the tail end of a string "s" after a "," returning
	  the front part of "s" as "t".
cwp_strrev - reverse a string



******************************************************************
Input:
char *str	input string	

Output:
none

Returns:
char *	  duplicated string

******************************************************************
Notes:
This local definition of strdup is necessary because some systems
do not have it.

******************************************************************
Author: John Stockwell, Spring 2000.
******************************************************************/
/**************** end self doc ********************************/

char *
cwp_strdup(char *str)
/******************************************************************
cwp_strdup -  duplicate a string
******************************************************************
Input:
char *str	input string	

Output:
none

Returns:
char *copy      copy of string

******************************************************************
Notes:
This local definition of strdup is necessary because some systems
do not have it.
******************************************************************
Author: John Stockwell, Spring 2000.
******************************************************************/
{
	int len;
	char *copy;

	len = strlen(str) + 1;
	if (!(copy = malloc((unsigned int) len)))
		return ((char *) NULL);

	memcpy(copy,str, len);
	return (copy);
}

void strchop(char *s, char *t)
/***********************************************************************
strchop - chop off the tail end of a string "s" after a "," returning
	  the front part of "s" as "t".
************************************************************************
Notes:
Based on strcpy in Kernighan and Ritchie's C [ANSI C] book, p. 106.
************************************************************************
Author: CWP: John Stockwell and Jack K. Cohen, July 1995
***********************************************************************/
{

	while ( (*s != ',') && (*s != '\0') ) {
		 *t++ = *s++;
	}
	*t='\0';
}

char *
cwp_strrev (char *str)
/************************************************************************
cwp_strrev -  reverse a string
************************************************************************
Input:
s         string to be reversed
Returns:
reversed string
************************************************************************
Credits: based on strrev: public domain by Bob Stout
************************************************************************/
{
	int len=strlen(str);
	char *revstr= (char *) malloc(sizeof(char)*(len +1 ));
	if (revstr != '\0') {
		int i,j;
		revstr[len]='\0';
		for (i=len-1, j=0; i>=0; --i, ++j)
				revstr[j] = str[i];
	}
	return revstr;

}
