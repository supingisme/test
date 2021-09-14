/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 19:49:33 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 17:31:00 CST. */
#include <stdio.h>
#include <mysql.h>
#include <my_global.h>
#include <string.h>
#include "UserInput.h"
#include "Utilities.h"

int main()
{
	char *host = "localhost";
	MYSQL *conn = mysql_init(NULL);

	if(conn == NULL) {
		printf("mysql_init() returns NULL\n");
		return 1;
	}

	if(mysql_real_connect (conn, host, "root", "root ", NULL, 0, NULL, 0) == NULL) {
		printf("Error: cant login\n");
	} else {
		printf("Logged in.\n");
	}

	printf("Server version: %s\n", mysql_get_server_info(conn));
	printf("Client version: %s\n", mysql_get_client_info());
	mysql_close(conn);

	UserData *data = malloc(sizeof(UserData));
	getData(data);

	char query[1024];
	char *createCommand = "CREATE DATABASE ";
	size_t qLength = strlen(createCommand) + strlen(data->dbName) + 1;
	char *dynamicQuery = malloc(qLength);

	strcpy(dynamicQuery, createCommand);
	strcat(dynamicQuery, data->dbName);
	printf("Dynamic Query: %s\n", dynamicQuery);




	snprintf(query, sizeof(query),
			"CREATE DATABASE %1$s;"
			"GRANT ALL PRIVILEGES ON %1$s.* TO %2$s@localhost "
			"IDENTIFIED BY '%3$s';FLUSH PRIVILEGES;",
			data->dbName,
			data->userName,
			data->password
			);

	printf("The query string for the new database is:\n");
	printf("%s\n", query);
	free(data->dbName);
	free(data->userName);
	free(data->password);
	free(data);

	return 0;
}

