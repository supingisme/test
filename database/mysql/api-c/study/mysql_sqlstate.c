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
 * * MySQL C client API example: mysql_sqlstate()
 * *
 * * see also http://mysql.com/mysql_sqlstate
 * */

#include "config.h"

#include <stdlib.h>
#include <stdio.h>

#include <mysql.h>

int main(int argc, char **argv) 
{
	MYSQL *mysql = NULL, *con;

	mysql = mysql_init(mysql);

	if (!mysql) {
		puts("Init faild, out of memory?");
		return EXIT_FAILURE;
	}

	con = mysql_real_connect(mysql,       /* MYSQL structure to use */
			MYSQL_HOST, /* server hostname or IP address */ 
			MYSQL_USER,      /* mysql user */
			MYSQL_PWD,          /* password */
			MYSQL_DB,      /* default database to use, NULL for none */
			0,           /* port number, 0 for default */
			NULL,        /* socket file or named pipe name */
			CLIENT_FOUND_ROWS /* connection flags */ ); 

#if 0
/usr/include/mysql/sql_state.h:216:{ ER_SIGNAL_EXCEPTION                     ,"HY000", "" },
/usr/include/mysql/sql_state.h-217-{ ER_RESIGNAL_WITHOUT_ACTIVE_HANDLER      ,"0K000", "" },
/usr/include/mysql/sql_state.h-218-{ ER_SPATIAL_MUST_HAVE_GEOM_COL           ,"42000", "" },
#endif
	printf("MySQL sqlstate for failed connect: %s \n", mysql_sqlstate(mysql));
	printf("MySQL sqlstate for failed connect: %s \n", mysql_sqlstate(con));

	mysql_close(mysql);

	return EXIT_SUCCESS;
}

