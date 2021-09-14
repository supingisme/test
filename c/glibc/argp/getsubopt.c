/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:09 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	int getsubopt (char **optionp, const char* const *tokens, char [Function]
 *	**valuep)
 *	The optionp parameter must be a pointer to a variable containing the address of the
 *	string to process. When the function returns the reference is updated to point to
 *	the next suboption or to the terminating ‘\0’ character if there is no more suboption
 *	available.
 *	The tokens parameter references an array of strings containing the known suboptions.
 *	All strings must be ‘\0’ terminated and to mark the end a null pointer must be
 *	stored. When getsubopt fnds a possible legal suboption it compares it with all strings
 *	available in the tokens array and returns the index in the string as the indicator.
 *	In case the suboption has an associated value introduced by a ‘=’ character, a pointer
 *	to the value is returned in valuep. The string is ‘\0’ terminated. If no argument is
 *	available valuep is set to the null pointer. By doing this the caller can check whether
 *	a necessary value is given or whether no unexpected value is present.
 *	In case the next suboption in the string is not mentioned in the tokens array the
 *	starting address of the suboption including a possible value is returned in valuep and
 *	the return value of the function is ‘-1’.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int do_all;
const char *type;
int read_size;
int write_size;
int read_only;
enum
{
	RO_OPTION = 0,
	RW_OPTION,
	READ_SIZE_OPTION,
	WRITE_SIZE_OPTION,
	THE_END
};
const char *mount_opts[] =
{
	[RO_OPTION] = "ro",
	[RW_OPTION] = "rw",
	[READ_SIZE_OPTION] = "rsize",
	[WRITE_SIZE_OPTION] = "wsize",
	[THE_END] = NULL
};
int
main (int argc, char *argv[])
{
	char *subopts, *value;
	int opt;
	while ((opt = getopt (argc, argv, "at:o:")) != -1)
		switch (opt)
		{
			case 'a':
				do_all = 1;
				break;
			case 't':
				type = optarg;
				break;
			case 'o':
				subopts = optarg;
				while (*subopts != '\0')
					switch (getsubopt (&subopts, mount_opts, &value))
					{
						case RO_OPTION:
							read_only = 1;
							break;
						case RW_OPTION:
							read_only = 0;
							break;
						case READ_SIZE_OPTION:
							if (value == NULL)
								abort ();
							read_size = atoi (value);
							break;
						case WRITE_SIZE_OPTION:
							if (value == NULL)
								abort ();
							write_size = atoi (value);
							break;
						default:
							/* Unknown suboption. */
							printf ("Unknown suboption ‘%s’\n", value);
							break;
					}
				break;
			default:
				abort ();
		}
	/* Do the real work. */
	return 0;
}
