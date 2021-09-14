/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 20日 星期四 08:47:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 19日 星期三 08:50:23 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 06月 19日 星期三 08:50:10 CST. 
*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "server.h"
/* HTML source for the start of the page we generate. */
static char* page_start =
"<html>\n"
" <body>\n"
" <pre>\n";
/* HTML source for the end of the page we generate. */
static char* page_end =
" </pre>\n"
" </body>\n"
"</html>\n";
void module_generate (int fd)
{
	pid_t child_pid;
	int rval;
	/* Write the start of the page. */
	write (fd, page_start, strlen (page_start));
	/* Fork a child process. */
	child_pid = fork ();
	if (child_pid == 0) {
		/* This is the child process. */
		/* Set up an argument list for the invocation of df. */
		char* argv[] = { "/bin/df", "-h", NULL };
		/* Duplicate stdout and stderr to send data to the client socket. */
		rval = dup2 (fd, STDOUT_FILENO);
		if (rval == -1)
			system_error ("dup2");
		rval = dup2 (fd, STDERR_FILENO);
		if (rval == -1)
			system_error ("dup2");
		const char *tmp = "Hello World";
		write (fd, tmp, strlen (tmp));
		/* Run df to show the free space on mounted file systems. */
		execv (argv[0], argv);
		/* A call to execv does not return unless an error occurred. */
		system_error ("execv");
	}
	else if (child_pid > 0) {
		/* This is the parent process. Wait for the child process to
		 * finish. */
		rval = waitpid (child_pid, NULL, 0);
		if (rval == -1)
			system_error ("waitpid");
	}
	else
		/* The call to fork failed. */
		system_error ("fork");
	/* Write the end of the page. */
	write (fd, page_end, strlen (page_end));
}


