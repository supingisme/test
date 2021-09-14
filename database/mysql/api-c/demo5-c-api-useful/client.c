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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 17:47:38 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 17:44:35 CST. */
#include "utils.h"
#include "show.h"

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	/* Skip the program name */
	(argc)--;
	if (argc == 0) {
		printf("Usage: %s \"<mysql-statement>\"\n", argv[0]);
		printf("Such as: %s \"select * from goods;\"\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (argc > 1) {
		fprintf(stderr, "%s: Too many arguments\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	MYSQL mysql;
	mysql_init(&mysql);

	if (mysql_real_connect(&mysql, "localhost", "root", "root ", "testdb",
				0, NULL, 0) == NULL) {
		exit_with_error(&mysql);
	}

	if (mysql_query(&mysql, argv[1])) {
		exit_with_error(&mysql);
	}

	MYSQL_RES *result = mysql_store_result(&mysql);
	if (result == NULL) {
		exit_with_error(&mysql);
	}

	printf("mysql> %s;\n", argv[1]);
	print_result_set(&mysql, result);

	mysql_free_result(result);
	mysql_close(&mysql);

	exit(EXIT_SUCCESS);
}

