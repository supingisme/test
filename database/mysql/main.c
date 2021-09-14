/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:56 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:54 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:23 CST. */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <mysql/mysql.h>

#define debug() printf("\033[31m%s:%d\033[m\n", __func__, __LINE__)

#define HOST_NAME					"localhost"
#define USERNAME_FOR_CONNECTION		"rongtao"
#define PASSWORD_FOR_CONNECTION		"123456"
#define DB_NAME						"dbtest"

MYSQL* db_open()
{
    MYSQL* 	main_sql = NULL;
    debug();
	main_sql = mysql_init(NULL);
    debug();
	if (!main_sql)
	{
		printf("initial mysql error:%s\n", strerror(errno));

		return NULL;
	}
    debug();
    main_sql = mysql_real_connect(main_sql, HOST_NAME, USERNAME_FOR_CONNECTION,
    									PASSWORD_FOR_CONNECTION, DB_NAME, 0, NULL, 0);
    debug();
    if(!main_sql)
	{
    	printf("open mysql error:%s\n", strerror(errno));
        debug();
		return NULL;
    }
    debug();
    return main_sql;
}

int db_close(MYSQL* main_sql)
{
	if (NULL == main_sql)
	{
		printf("please connect the mysql-server before\n");

		return -1;
	}
	mysql_close(main_sql);
	main_sql = NULL;

	return -1;
}

/*
$ gcc main.c -L /usr/lib64/mysql/ -lmysqlclient
*/
int main()
{
	MYSQL *mysql = db_open();
    db_close(mysql);
    
	return 0;
}
