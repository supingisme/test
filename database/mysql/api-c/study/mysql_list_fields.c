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

int main(int argc, char **argv) 
{
	MYSQL *mysql = NULL;

	mysql = mysql_init(mysql);

	if (!mysql) {
		puts("Init faild, out of memory?");
		return EXIT_FAILURE;
	}
	/**
	 *	Database changed
	 *	MariaDB [testdb]> show tables;
	 *	+------------------+
	 *	| Tables_in_testdb |
	 *	+------------------+
	 *	| customer         |
	 *	| customer1        |
	 *	| goods            |
	 *	| person           |
	 *	| product          |
	 *	+------------------+
	 *	5 rows in set (0.00 sec)
	 *
	 *	MariaDB [testdb]> select * from goods;
	 *	+-------+-------+--------+
	 *	| name  | price | number |
	 *	+-------+-------+--------+
	 *	| books | 88.99 |    100 |
	 *	| pen   | 108.2 |     99 |
	 *	+-------+-------+--------+
	 *	2 rows in set (0.00 sec)
	 *
	 */
	if (!mysql_real_connect(mysql,       /* MYSQL structure to use */
				MYSQL_HOST,  /* server hostname or IP address */ 
				MYSQL_USER,  /* mysql user */
				MYSQL_PWD,   /* password */
				MYSQL_DB,        /* default database to use, NULL for none */
				0,           /* port number, 0 for default */
				NULL,        /* socket file or named pipe name */
				CLIENT_FOUND_ROWS /* connection flags */ )) 
	{
		puts("Connect failed\n");
	} 

	/**
	 *	MYSQL_RES * STDCALL mysql_list_fields(MYSQL *mysql, const char *table,
	 *										const char *wild);
	 */
	MYSQL_RES *result = mysql_list_fields(mysql, "goods", "%");

	if(!result)
		printf("Couldn't get fields list: %s\n", mysql_error(mysql));

	MYSQL_ROW row;
	while((row = mysql_fetch_row(result)))
	{
		puts(row[0]);
	}
	mysql_free_result(result);

	mysql_close(mysql);

	return EXIT_SUCCESS;
}

