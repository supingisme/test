/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:59 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 13:47:15 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 13:46:59 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn)
{
	PQfinish(conn);
	exit(1);
}

int main(int argc, char *argv[])
{
	const int LEN = 10;
	const char *paramValues[1];

	if(argc != 2)
	{
		fprintf(stderr, "usage: %s <row id>\n", argv[0]);
		exit(1);
	}

	int rowId = atoi(argv[1]);
	if(rowId <0)
	{
		fprintf(stderr, "rowId out of range. %d\n", rowId);
		exit(1);
	}

	char str[LEN];
	snprintf(str, LEN, "%d", rowId);
	
	paramValues[0] = str;

	PGconn *conn = PQconnectdb("user=rongtao dbname=testdb");

	if(PQstatus(conn) == CONNECTION_BAD)
	{
		fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		do_exit(conn);
	}

	/**
	 *	$1: 第一个参数
	 *	$2: 第二个参数
	 *	$3: 第三个参数
	 */
	char *stm = "select * from Cars where Id=$1";

	/**
	 *	extern PGresult *PQexecParams(PGconn *conn,
	 *								const char *command,
	 *								int nParams,
	 *								const Oid *paramTypes,
	 *								const char *const * paramValues,
	 *								const int *paramLengths,
	 *								const int *paramFormats,
	 *								int resultFormat);
	 */
	PGresult *res = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);
	if(PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		printf("No data retrieved.\n");
		PQclear(res);
		do_exit(conn);
	}

	printf("%8s | %8s | %8s\n", 
			PQgetvalue(res, 0, 0),
			PQgetvalue(res, 0, 1),
			PQgetvalue(res, 0, 2)
			);

	PQfinish(conn);

	return 0;
}
