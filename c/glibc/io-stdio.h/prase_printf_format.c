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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define PA_FOO PA_LAST
#define PA_BAR (PA_LAST + 1)

/* Test whether the nargs specifed objects
 * in the vector args are valid
 * for the format string format:
 * if so, return 1.
 * If not, return 0 after printing an error message. */
int
validate_args (char *format, int nargs, OBJECT *args)
{
	int *argtypes;
	int nwanted;
	/* Get the information about the arguments.
	 * Each conversion specifcation must be at least two characters
	 * long, so there cannot be more specifcations than half the
	 * length of the string. */
	argtypes = (int *) alloca (strlen (format) / 2 * sizeof (int));
	nwanted = parse_printf_format (string, nelts, argtypes);
	/* Check the number of arguments. */
	if (nwanted > nargs)
	{
		error ("too few arguments (at least %d required)", nwanted);
		return 0;
	}
	/* Check the C type wanted for each argument
	 * and see if the object given is suitable. */
	for (i = 0; i < nwanted; i++)
	{
		int wanted;
		if (argtypes[i] & PA_FLAG_PTR)
			wanted = STRUCTURE;
		else
			switch (argtypes[i] & ~PA_FLAG_MASK)
			{
				case PA_INT:
				case PA_FLOAT:
				case PA_DOUBLE:
					wanted = NUMBER;
					break;
				case PA_CHAR:
					wanted = CHAR;
					break;
				case PA_STRING:
					wanted = STRING;
					break;
				case PA_POINTER:
					wanted = STRUCTURE;
					break;
			}
		if (TYPE (args[i]) != wanted)
		{
			error ("type mismatch for arg number %d", i);
			return 0;
		}
	}
	return 1;
}

int main()
{
	validate_args("RongTao:%d\n", 1, PA_INT);

	return 0;
}
