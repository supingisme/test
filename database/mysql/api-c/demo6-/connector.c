/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:54 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:49:16 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 19:49:12 CST. */
/*
 * Author: Dung Harry
 * Date created: 1st, November 2013
 * Operating System: Ubuntu 13.04 Desktop x86_64
 * Compiler: GNU compiler 4.8.1
 *
 * Description: this is the sample about how to connect to specific table in the database in C programming language
 *
 * This is the source code for connector in the C programming language
 * */

#include "connector.h"

MYSQL* lpSqlGetConnector(const char *lpcServer, const char *lpcUser, const char *lpcPassword, const char *lpcDatabase) {
	MYSQL *connector;

	connector = mysql_init(NULL);

	if(!mysql_real_connect(connector, lpcServer, lpcUser, lpcPassword, lpcDatabase, 0, NULL, 0)) {
		connector = NULL;
	}

	return connector;
};

void vDestroyConnector(MYSQL **connector) {
	mysql_close(*connector);
}

