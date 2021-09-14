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
 * Description: this is the sample about how to fetch data in MySQL database via C programming language
 *
 * Compile and run:
 * gcc -c $(mysql_config --cflags) connector.c $(mysql_config --libs)
 * gcc -c $(mysql_config --cflags) fetch_data.c $(mysql_config --libs)
 * gcc -o mysql $(mysql_config --cflags) fetch_data.o connector.o main.c $(mysql_config --libs)
 *
 * ./mysql
 *
 * Need to install libmysql++ by using the command:
 * sudo apt-get install libmysql++-dev
 *
 * Testing:
 * - Create a database with one table and insert a tuble into it in MySQL database:
 *   create database Test;
 *
 *   use Test;
 *
 *   create table User (
 *   Id int auto_increment not null,
 *   Name varchar(50) not null,
 *   Password varchar(50) not null,
 *   Email varchar(50),
 *   Address varchar(100),
 *   constraint Id primary key(Id) 
 *   );
 *
 *   insert into User(Name, Password, Email, Address) values ("Dung Harry", "Hello C API for MySQL!", "dungharry@engine.com", "Hanoi University of Science and Technology")
 *
 *   - Run program by using command in Terminal: ./mysql with:
 *   + Server name: localhost
 *   + User name: root
 *   + Password: password
 *   + Datbase name: Test
 *   + The query: select * from Test
 *   */

#include <stdlib.h>
#include <string.h>
#include "fetch_data.h"

void vEnter(char **lpcInfo);

void main(int argc, char *argv[]) {
	MYSQL *connector;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *lpcServer, *lpcUser, *lpcPassword, *lpcDatabase, *lpcQuery;
	int iTemp;

	printf("Author: Dung Harry. Date created: 1st, November 2013\n\n");

	printf("Entering some informations for connection part...\n\n");

	printf("Enter the server name: ");
	vEnter(&lpcServer);

	printf("Enter the user name: ");
	vEnter(&lpcUser);

	printf("Enter the password: ");
	vEnter(&lpcPassword);

	printf("Enter the database name: ");
	vEnter(&lpcDatabase);

	printf("\nEnter the SQL query: ");
	vEnter(&lpcQuery);

	if((connector = lpSqlGetConnector(lpcServer, lpcUser, lpcPassword, lpcDatabase)) == NULL) {
		fprintf(stderr, "%s\n", mysql_error(connector));

		exit(1);
	}

	if(((iTemp = iFetchData(&connector, lpcQuery, &res)) == ERROR_NULL_CON_FDT) || (iTemp == ERROR_CREATE_QUERY_FDT)) {
		iTemp == ERROR_CREATE_QUERY_FDT ? printf("Error: Couldn't create the query\n") : printf("Error: the null connection passed\n");

		exit(1);
	}

	vPrint(&connector, lpcQuery, &res, &row);
}

void vEnter(char **lpcInfo) {
	char *lpcTemp = (char *) malloc(1000 * sizeof(char)), c;
	int i;

	scanf("%s", lpcTemp);
	for(i = 0; *(lpcTemp + i) != '\0'; i ++);
	for(; (*(lpcTemp + i) = getc(stdin)) != '\n'; i ++);
	*(lpcTemp + i) = '\0';

	*lpcInfo = (char *) malloc(strlen(lpcTemp) * sizeof(char));

	strcpy(*lpcInfo, lpcTemp);

	free(lpcTemp);
}

