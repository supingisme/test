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

static char *server_groups[] = {
	"embedded",
	"server",
	(char *)NULL
};

int main(int argc, char **argv) 
{
	MYSQL *mysql = NULL;
	int i;
	
	/**
	 * int STDCALL mysql_server_init(int argc, char **argv, char **groups);
	 */
	if(mysql_server_init(argc, argv, server_groups))
	{
		fputs("server init failed", stderr);
		return EXIT_FAILURE;
	}

	mysql = mysql_init(mysql);
	mysql_options(mysql, MYSQL_READ_DEFAULT_GROUP, "libmysqld_client");
	mysql_options(mysql, MYSQL_OPT_USE_EMBEDDED_CONNECTION, NULL);
				
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

	for(i = 0; i < 10; i++) 
	{ 
		printf("iteration %d\n", i); 
		/**
		*	MYSQL_STMT * STDCALL mysql_stmt_init(MYSQL *mysql);	
		 */
		/**
		 *mysql_init()：初始胡爱一个mysql对象，用于与数据库的连接句柄；
		 *mysql_real_connect（）：
		 *mysql_stmt_prepare()：长传预处理的sql语句
		 *mysql_stmt_bind_param()：定义相应的MYSQL_BIND数据结构，调用，用于绑定输入参数
		 *mysql_stmt_result_metadata()：如果由输出结果集，调用，以MYSQL_RES形式返回预处理语句元数据
		 *mysql_stmt_execute()：执行响应的sql查询操作
		 *mysql_stmt_bind_result()：
		 *	如果有输出结果，调用mysql_stmt_bind_result()将数据绑定到MYSQL_BIND数据结构对象上
		 *	同时调用mysql_stmt_store_result()将所有的结果集保存到客户端的缓冲区中
		 *	并通过mysql_stmt_fetch()来进行调用获取返回的每一行的值。
		 */
		MYSQL_STMT* stmt = mysql_stmt_init(mysql); 
		char* command = "SELECT * FROM goods"; 
		//char* command = "UPDATE T1 SET i1 = 1"; 
		mysql_stmt_prepare(stmt, command, strlen(command)); 
		mysql_stmt_execute(stmt); 
		mysql_stmt_store_result(stmt);
		while (!mysql_stmt_fetch(stmt)) 
		{
			
		}
		mysql_stmt_free_result(stmt); 
		mysql_stmt_close(stmt); 
	} 
	


	mysql_close(mysql);

	return EXIT_SUCCESS;
}

