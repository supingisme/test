/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 19:49:33 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:53 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 17:31:00 CST. */
#include "Utilities.h"

void show_error(MYSQL *mysql)
{
	printf("Error(%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1);
}

ssize_t my_getpass (char **lineptr, size_t *n, FILE *stream)
{
	struct termios old, new;
	int nread;

	/* Turn echoing off and fail if we can’t. */
	if (tcgetattr(fileno(stream), &old) != 0)
		return -1;
	new = old;
	new.c_lflag &= ~ECHO;
	if (tcsetattr (fileno (stream), TCSAFLUSH, &new) != 0)
		return -1;

	/* Read the passphrase */
	nread = getline (lineptr, n, stream);
	char *end = (*lineptr) + (nread - 1);
	*end = '\0'; /* Remove the trailing newline	*/
	(void) tcsetattr (fileno (stream), TCSAFLUSH, &old);
	return nread;
}

