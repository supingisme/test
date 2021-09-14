/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:54 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:23:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:12:17 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 17:20:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 14:00:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 13:38:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 11:33:18 CST. */
#include "config.h"

#include <stdlib.h>
#include <stdio.h>

#include <mysql.h>

#include <string.h>

int main(int argc, char **argv) 
{
	MYSQL *mysql = NULL;

	mysql = mysql_init(mysql);

	if (!mysql) {
		puts("Init faild, out of memory?");
		return EXIT_FAILURE;
	}
		          
	if (!mysql_real_connect(mysql,       /* MYSQL structure to use */
				MYSQL_HOST,  /* server hostname or IP address */ 
				MYSQL_USER,  /* mysql user */
				MYSQL_PWD,   /* password */
				NULL,        /* default database to use, NULL for none */
				0,           /* port number, 0 for default */
				NULL,        /* socket file or named pipe name */
				CLIENT_FOUND_ROWS /* connection flags */ )) 
	{
		puts("Connect failed\n");
	} 
	
	const char *from = "abcdefg";
	char to[201];
	unsigned long len;
	/**
	 *	十六进制字符串
	 *	abcdefg -> 61626364656667
	 */
	len = mysql_hex_string(to, from, strlen(from));
	to[len] = '\0';

	printf("Hex encoded string is: \" %s\" (%lu)\n", to, len);

	mysql_close(mysql);

	return EXIT_SUCCESS;
}

