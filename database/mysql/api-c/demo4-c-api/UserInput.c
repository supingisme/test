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
#include "UserInput.h"

void getData(UserData *data)
{
	char dbName[32];
	char userName[64];
	size_t passMaxChars = 64;
	char *password = malloc(passMaxChars);


	printf("Enter the name of the Database:\n");
	scanf("%s", dbName);
	getchar();
	printf("Enter the user name for the Database:\n");
	scanf("%s", userName);
	getchar();
	printf("Enter the password:\n");
	my_getpass(&password, &passMaxChars, stdin);

	data->dbName = malloc(strlen(dbName) + 1);
	strcpy(data->dbName, dbName);
	data->userName = malloc(strlen(userName) + 1);
	strcpy(data->userName, userName);
	data->password = malloc(strlen(password) + 1);
	strcpy(data->password, password);
	free(password);
}

