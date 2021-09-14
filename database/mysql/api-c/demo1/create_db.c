/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:53 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:52 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:23:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 16:02:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 11:03:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 10:40:17 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define CREATE_DB   "CREATE DATABASE IF NOT EXISTS "

#define CREATE_TABLE    "create table customer ( "\
                            "customer_id serial,"\
                            "title char(4),"\
                            "fname varchar(32),"\
                            "lname varchar(32) NOT NULL,"\
                            "addressline varchar(64),"\
                            "town varchar(32),"\
                            "zipcode char(10) NOT NULL,"\
                            "phone varchar(16)"\
                        ");"
                        
#define INSERT_TABLE    "insert into customer(title, fname, lname, addressline, zipcode, phone) "\
                        "values('Miss', 'Chandler', 'Stones', '27 Rowan', 'zipcode', '3417615');"

int main(int argc, char *argv[])
{
	printf("MySQL client version: %s\n", mysql_get_client_info());

	MYSQL *conn = mysql_init(NULL);

	char query[256] = CREATE_DB;
	strncat(query, "testdb", strlen("testdb"));

	printf("QUERY: %s\n", query);

	if(conn == NULL)
	{
		printf("%s\n", mysql_error(conn));
		return -1;
	}
	if(mysql_real_connect(conn, "localhost", "root", "root ", NULL, 0, NULL, 0) == NULL)
	{
		printf("%s\n", mysql_error(conn));
		return -1;
	}
	if(mysql_query(conn, query))
	{
		printf("%s\n", mysql_error(conn));
		mysql_close(conn);
		return 0;
	}
	if(mysql_query(conn, "use testdb;"))
	{
		printf("%s\n", mysql_error(conn));
		mysql_close(conn);
		return 0;
	}
	if(mysql_query(conn, INSERT_TABLE))
	{
		printf("%s\n", mysql_error(conn));
		mysql_close(conn);
		return 0;
	}

	puts("MySQL database created.\n");

	mysql_close(conn);

	return 0;
}
