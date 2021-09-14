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

#define debug() printf("%d\n", __LINE__)

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
		printf("mysql errno: %s\n", mysql_error(mysql));
		exit(1);
	}
	printf("%d\n", __LINE__);
/*
 *	MariaDB [testdb]> select *    from goods;
 *	+-------+-------+--------+
 *	| name  | price | number |
 *	+-------+-------+--------+
 *	| books | 88.99 |    100 |
 *	| pen   | 108.2 |     99 |
 *	+-------+-------+--------+
 *	2 rows in set (0.00 sec)
 *
 */
	
	mysql_query(mysql, "select *  from goods");
	MYSQL_RES *result = mysql_store_result(mysql);
	
	int num_fields = mysql_num_fields(result);

	/**
	 *
	 */
	int i = 0;
	MYSQL_FIELD *field = mysql_fetch_fields(result);
#if 0
	/**
	 *	MYSQL_FIELD *	STDCALL mysql_fetch_field(MYSQL_RES *result);
	 */
	while(NULL != (field = mysql_fetch_field(result)))
	{
#endif
	/**
	 *
	 */
	for(i=0; i<num_fields; i++)
	{
		//field = mysql_fetch_field_direct(result, i);

		debug();
		printf("FIELD #%d\n", i);
		printf("  %-20s %s\n", "Field name", field[i].name);
#if MYSQL_VERSION_ID >= 40100
		printf("  %-20s %s\n", "Original name", field[i].org_name);
#endif
		printf("  %-20s %s\n", "From table", field[i].table);
		printf("  %-20s %s\n", "Original name", field[i].org_table);
		printf("  %-20s %s\n", "Database", field[i].db);

#if MYSQL_VERSION_ID >= 40100
		printf("  %-20s %s\n", "Catalog", field[i].catalog);
#endif
		printf("  %-20s %s\n", "Default", field[i].def);
		printf("  %-20s %lu\n", "CREATE field length", field[i].length);
		printf("  %-20s %lu\n", "MAX field lengt", field[i].max_length);
#if MYSQL_VERSION_ID >= 40100
		printf("  %-20s %u\n", "Field name length", field[i].name_length);
		printf("  %-20s %u\n", "Original name length", field[i].org_name_length);
		printf("  %-20s %u\n", "Table name length", field[i].table_length);
		printf("  %-20s %u\n", "Original name length", field[i].org_table_length);
		printf("  %-20s %u\n", "DB name length", field[i].db_length);
		printf("  %-20s %u\n", "Catalog name length", field[i].catalog_length);
		printf("  %-20s %u\n", "Default length", field[i].def_length);
#endif
		/* TODO: decimals */
		printf("\n");








	}


	mysql_close(mysql);

}
