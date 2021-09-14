/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:13 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:55 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*	int asprintf (char **ptr, const char *template, . . .) [Function]
 *	This function is similar to sprintf, except that it dynamically allocates a string
 *	(as with malloc; see Section 3.2.2 [Unconstrained Allocation], page 33) to hold the
 *	output, instead of putting the output in a buﬀer you allocate in advance. The ptr
 *	argument should be the address of a char * object, and a successful call to asprintf
 *	stores a pointer to the newly allocated string at that location.
 *	The return value is the number of characters allocated for the buﬀer, or less than zero
 *	if an error occurred. Usually this means that the buﬀer could not be allocated.
 *
 *	int obstack_printf (struct obstack *obstack, const char *template, [Function]
 *	. . .)
 *	This function is similar to asprintf, except that it uses the obstack obstack to
 *	allocate the space. See Section 3.2.4 [Obstacks], page 48.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* Construct a message describing the value of a variable
 * whose name is name and whose value is value. */
char *
make_message (char *name, char *value)
{
	char *result;
	//same as: obstack_print();
	if (asprintf (&result, "value of %s is %s", name, value) < 0)
		return NULL;
	return result;
}

int main()
{
	printf("%s\n", make_message("RongTao", "100"));
	
	

	return 0;
}
