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

int main()
{
	PGconn *conn = PQconnectdb("user=rongtao dbname=testdb");

	if(PQstatus(conn) == CONNECTION_BAD)
	{
		fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		do_exit(conn);
	}

	PGresult *res = PQexec(conn, "select * from Cars limit 5");
	if(PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		printf("No data retrieved.\n");
		PQclear(res);
		exit(1);
	}

	/**
	 *	PQntuples: returns the number of rows in the query result	
	 */
	int i, rows = PQntuples(res);

	for(i=0; i<rows; i++)
	{
		printf("%8s | %8s | %8s \n", 
				PQgetvalue(res, i, 0),
				PQgetvalue(res, i, 1),
				PQgetvalue(res, i, 2)
				);
	}

	PQclear(res);
	PQfinish(conn);

	return 0;
}
