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
#include <string.h>

void print_res_header(MYSQL_RES *result)
{
	MYSQL_FIELD *field;

	print_res_top(result);
	mysql_field_seek(result, 0);
	putchar('|');

	while((field = mysql_fetch_field(result))) {
		printf(" %-*s|", (int) field->max_length+1, field->name);
	}
	putchar('\n');
	print_res_top(result);
}

void print_res_top(MYSQL_RES *result)
{
	unsigned int i;
	unsigned int length;
	MYSQL_FIELD  *field;

	putchar('+');
	mysql_field_seek(result, 0);

	while((field = mysql_fetch_field(result))) {
		if ((length = (unsigned int) strlen(field->name)) > field->max_length) {
			field->max_length = length;
		}
		else {
			length = field->max_length;
		}

		for (i = length + 2; i-- > 0; ) {
			putchar('-');
		}
		putchar('+');
	}
	putchar('\n');
}

void print_res_row(MYSQL_RES *result, MYSQL_ROW current)
{
	unsigned int i;
	unsigned int length;
	MYSQL_FIELD  *field;

	putchar('|');
	mysql_field_seek(result, 0);

	for (i = 0 ; i < mysql_num_fields(result); i++) {
		field  = mysql_fetch_field(result);
		length = field->max_length;
		printf(" %-*s|", length + 1, current[i] ? (char*) current[i] : "");
	}
	putchar('\n');
}

void print_result_set(MYSQL *mysql, MYSQL_RES *result)
{
	MYSQL_ROW row;

	print_res_header(result);
	while ((row = mysql_fetch_row(result))) {
		print_res_row(result, row);
	}
	print_res_top(result);
	printf("%ld rows in set\n", (long) mysql_affected_rows(mysql));
}

