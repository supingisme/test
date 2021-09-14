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
/*	The pipe function is declared in the header fle ‘unistd.h’.
 *	int pipe (int filedes[2]) [Function]
 *	The pipe function creates a pipe and puts the fle descriptors for the reading and
 *	writing ends of the pipe (respectively) into filedes[0] and filedes[1].
 *	An easy way to remember that the input end comes frst is that fle descriptor 0 is
 *	standard input, and fle descriptor 1 is standard output.
 *	If successful, pipe returns a value of 0. On failure, -1 is returned. The following
 *	errno error conditions are defned for this function:
 *	EMFILE The process has too many fles open.
 *	ENFILE There are too many open fles in the entire system. See Section 2.2 [Error
 *	Codes], page 14, for more information about ENFILE. This error never
 *	occurs in the GNU system.
 *
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct msg {
    int type;
    int code;
    int len;
};

/* Read characters from the pipe and echo them to stdout. */
void
read_from_pipe (int file)
{
	FILE *stream; 
	int c;
	stream = fdopen (file, "r");
	//while ((c = fgetc (stream)) != EOF)
	//	putchar (c);

    struct msg msg;
    for(;;)
    {
        if(read(fileno(stream), &msg, sizeof(msg)))
        {
            printf("%d, %d, %d\n", msg.type, msg.code, msg.len);
        }
    }
	fclose (stream);
}
/* Write some random text to the pipe. */
void
write_to_pipe (int file)
{
	FILE *stream;
	stream = fdopen (file, "w");
    
    struct msg msg = {
        .type = 1,
        .code = 3,
        .len = 100,
    };
    
    write(fileno(stream), &msg, sizeof(msg));
    sleep(2);
    write(fileno(stream), &msg, sizeof(msg));

    sleep(10000);
	fclose (stream);
}
int
main (void)
{
	pid_t pid;
	int mypipe[2];
	/* Create the pipe. */
	if (pipe (mypipe))
	{
		fprintf (stderr, "Pipe failed.\n");
		return EXIT_FAILURE;
	}
	/* Create the child process. */
	pid = fork ();
	if (pid == (pid_t) 0)
	{
		/* This is the child process.
		 * Close other end frst. */
		close (mypipe[1]);
		read_from_pipe (mypipe[0]);
		return EXIT_SUCCESS;
	}
	else if (pid < (pid_t) 0)
	{
		/* The fork failed. */
		fprintf (stderr, "Fork failed.\n");
		return EXIT_FAILURE;
	}
	else
	{
		/* This is the parent process.
		 * Close other end frst. */
		close (mypipe[0]);
		write_to_pipe (mypipe[1]);
		return EXIT_SUCCESS;
	}
}
