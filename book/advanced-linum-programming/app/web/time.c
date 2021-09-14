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
#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "server.h"
/* A template for the HTML page this module generates. */
static char* page_template =
"<html>\n"
" <head>\n"
" <meta http-equiv=\"refresh\" content=\"5\">\n"
" </head>\n"
" <body>\n"
" <p>>The current time is %s.</p>\n"
" </body>\n"
"</html>\n";
void module_generate (int fd)
{
	struct timeval tv;
	struct tm* ptm;
	char time_string[40];
	FILE* fp;
	/* Obtain the time of day, and convert it to a tm struct. */
	gettimeofday (&tv, NULL);
	ptm = localtime (&tv.tv_sec);
	/* Format the date and time, down to a single second. */
	strftime (time_string, sizeof (time_string), "%H:%M:%S", ptm);
	/* Create a stream corresponding to the client socket file
	 * descriptor. */
	fp = fdopen (fd, "w");
	assert (fp != NULL);
	/* Generate the HTML output. */
	fprintf (fp, page_template, time_string);
	/* All done; flush the stream. */
	fflush (fp);
}


