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
#include <fcntl.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "server.h"
/* HTML source for the start of the page we generate. */
static char* page_start =
"<html>\n"
"<body>\n"
"<pre>\n";
/* HTML source for the end of the page we generate. */
static char* page_end =
" </pre>\n"
" </body>\n"
"</html>\n";
/* HTML source for the page indicating there was a problem opening
 * /proc/issue. */
static char* error_page =
"<html>\n"
" <body>\n"
" <p>Error: Could not open /proc/issue.</p>\n"
" </body>\n"
"</html>\n";
/* HTML source indicating an error. */
static char* error_message = "Error reading /proc/issue.";
void module_generate (int fd)
{
	int input_fd;
	struct stat file_info;
	int rval;
	/* Open /etc/issue. */
	input_fd = open ("/etc/issue", O_RDONLY);
	if (input_fd == -1)
		system_error ("open");
	/* Obtain file information about it. */
	rval = fstat (input_fd, &file_info);
	if (rval == -1)
		/* Either we couldn't open the file or we couldn't read from it. */
		write (fd, error_page, strlen (error_page));
	else {
		int rval;
		off_t offset = 0;
		/* Write the start of the page. */
		write (fd, page_start, strlen (page_start));
		/* Copy from /proc/issue to the client socket. */
		rval = sendfile (fd, input_fd, &offset, file_info.st_size);
		if (rval == -1)
			/* Something went wrong sending the contents of /proc/issue.
			 * Write an error message. */
			write (fd, error_message, strlen (error_message));
		/* End the page. */
		write (fd, page_end, strlen (page_end));
	}
	close (input_fd);
}


