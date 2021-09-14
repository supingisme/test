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
/* Copyright (C) 2005, 2006 Hartmut Holzgraefe
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 * */

/*
 * * MySQL C client API example: mysql_use_result()
 * *
 * * see also http://mysql.com/mysql_use_result
 * */

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

	if (!mysql_real_connect(mysql,       /* MYSQL structure to use */
				MYSQL_HOST,         /* server hostname or IP address */ 
				MYSQL_USER,         /* mysql user */
				MYSQL_PWD,          /* password */
				NULL,               /* default database to use, NULL for none */
				0,           /* port number, 0 for default */
				NULL,        /* socket file or named pipe name */
				CLIENT_FOUND_ROWS /* connection flags */ )) {
		puts("Connect failed\n");
	} else {              
		if (mysql_query(mysql, "SELECT VERSION()")) {
			printf("Query failed: %s\n", mysql_error(mysql));
		}
		else 
		{
			/**
			 *	
			 *
			 */
			/**
			 * *	MYSQL_RES *     STDCALL mysql_use_result(MYSQL *mysql);
			 * *	对于成功检索了数据的每个查询（select、show、describe、explain、check、table）
			 * *	必须使用mysql_store_result()或者mysql_use_result()。
			 * *	对于其他查询，不需要调用。
			 * *	通过检查必须使用mysql_store_result返回值是否是0，可检测查询结果有没有结
			 * 果集。
			 **
			 */
			MYSQL_RES *result = mysql_use_result(mysql);

			if (result) {
				puts("Got a valid result set\n");
				mysql_free_result(result);
			} else {
				printf("Couldn't get results set: %s\n", mysql_error(mysql));
			}
		}
	}

	mysql_close(mysql);

	return EXIT_SUCCESS;
}

