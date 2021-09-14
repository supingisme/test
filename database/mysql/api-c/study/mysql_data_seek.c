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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 09:18:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 18:19:35 CST. */
#include "config.h"

#include <stdlib.h>
#include <stdio.h>

#include <mysql.h>

int main(int argc, char **argv) 
{
	MYSQL *mysql = NULL;

	mysql = mysql_init(mysql);
	
	if(!mysql)
	{
		printf("init error.\n");
		exit(1);
	}

	if(!mysql_real_connect(mysql, MYSQL_HOST, MYSQL_USER, MYSQL_PWD, 
							MYSQL_DB, 0, NULL, CLIENT_FOUND_ROWS))
	{
		printf("connect error.\n");
		exit(1);
	}

	mysql_query(mysql, "select *  from customer");

	/**
	 *	MYSQL_RES *     STDCALL mysql_store_result(MYSQL *mysql);
	 */
	MYSQL_RES *result = mysql_store_result(mysql);

	if(!result)
	{
		printf("mysql_store_result error.\n");
		exit(1);
	}
	MYSQL_ROW row;
	int i;
	/**
	 *	unsigned int STDCALL mysql_num_fields(MYSQL_RES *res);
	 */
	unsigned int num_fields = mysql_num_fields(result);

	printf("Got a valid result set, looking for 3rd result row\n");

	/**
	 *	void		STDCALL mysql_data_seek(MYSQL_RES *result, my_ulonglong offset);
	 */
	mysql_data_seek(result, 1);
	
	/**
	 *	MYSQL_ROW	STDCALL mysql_fetch_row(MYSQL_RES *result);
	 */
	row = mysql_fetch_row(result);

	if(!row)
	{
		printf("mysql_fetch_row error.\n");
		exit(1);
	}
	for(i=0;i<num_fields;i++)
		printf("%s, ", row[i]);
	putchar('\n');
	mysql_free_result(result);


	mysql_close(mysql);

}
