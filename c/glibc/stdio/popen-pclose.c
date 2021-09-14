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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 10:11:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*	FILE * popen (const char *command, const char *mode) [Function]
 *	The popen function is closely related to the system function; see Section 26.1 [Running
 *	a Command], page 688. It executes the shell command command as a subprocess.
 *	However, instead of waiting for the command to complete, it creates a pipe to the
 *	subprocess and returns a stream that corresponds to that pipe.
 *	If you specify a mode argument of "r", you can read from the stream to retrieve
 *	data from the standard output channel of the subprocess. The subprocess inherits its
 *	standard input channel from the parent process.
 *	Similarly, if you specify a mode argument of "w", you can write to the stream to send
 *	data to the standard input channel of the subprocess. The subprocess inherits its
 *	standard output channel from the parent process.
 *	In the event of an error popen returns a null pointer. This might happen if the pipe
 *	or stream cannot be created, if the subprocess cannot be forked, or if the program
 *	cannot be executed.
 *	int pclose (FILE *stream) [Function]
 *	The pclose function is used to close a stream created by popen. It waits for the child
 *	process to terminate and returns its status value, as for the system function.
 */
#include <stdio.h>
#include <stdlib.h>
void
write_data (FILE * stream)
{
	int i;
	for (i = 0; i < 100; i++)
		fprintf (stream, "%d hello RongTao\n", i);
	if (ferror (stream))
	{
		fprintf (stderr, "Output to stream failed.\n");
		exit (EXIT_FAILURE);
	}
}
int
main (void)
{
	FILE *output;
	output = popen ("more", "w");
	if (!output)
	{
		fprintf (stderr,
				"incorrect parameters or too many files.\n");
		return EXIT_FAILURE;
	}
	write_data (output);
	if (pclose (output) != 0)
	{
		fprintf (stderr,
				"Could not run more or other error.\n");
	}
	return EXIT_SUCCESS;
}
