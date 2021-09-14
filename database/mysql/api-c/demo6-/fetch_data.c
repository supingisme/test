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
 * Date created: 1st, October 2013
 * Operating System: Ubuntu 13.04 Desktop x86_64
 * Compiler: GNU compiler 4.8.1
 *
 * Description: this is the source code file for the sample about how to fetch all table name in specific data database in C programming language
 * */

#include "fetch_data.h"

int iFetchData(MYSQL **connector, const char *lpcQuery, MYSQL_RES **res) {
	int iResult = ERROR_NULL_CON_FDT;

	if(*connector != NULL) {
		if(mysql_query(*connector, lpcQuery)) {
			fprintf(stderr, "%s\n", mysql_error(*connector));

			iResult = ERROR_CREATE_QUERY_FDT;
		} else {
			*res = mysql_store_result(*connector);

			iResult = SUCCESS_RESULT_QUERY;
		}
	}

	return iResult;
}

void vPrintResult(MYSQL_RES **res, MYSQL_ROW *row) {
	unsigned long iNumRows = (unsigned long) mysql_num_rows(*res);
	unsigned int iColumns = mysql_num_fields(*res);
	MYSQL_FIELD *lpField;
	int i, j;

	printf("Have %ld rows are fetched, as following: \n", iNumRows);

	for(i = 1, *row = mysql_fetch_row(*res); *row != NULL; *row = mysql_fetch_row(*res), i ++) {
		printf("---The row %d:\n", i);

		for(j = 0; j < iColumns; j ++) {
			lpField = mysql_fetch_field_direct(*res, j);

			printf("Field %s: %s\n", lpField->name, (*row)[j]);
		}

		printf("\n");
	}

	mysql_free_result(*res);
}

void vFileResult(MYSQL_RES **res, MYSQL_ROW *row) {
	unsigned long iNumRows = (unsigned long) mysql_num_rows(*res);
	unsigned int iColumns = mysql_num_fields(*res);
	MYSQL_FIELD *lpField;
	int i, j;
	FILE *file;

	if((file = fopen("result.txt", "w")) != NULL) {
		fprintf(file, "Have %ld rows are fetched, as following: \n", iNumRows);

		for(i = 1, *row = mysql_fetch_row(*res); *row != NULL; *row = mysql_fetch_row(*res), i ++) {
			fprintf(file, "---The row %d:\n", i);

			for(j = 0; j < iColumns; j ++) {
				lpField = mysql_fetch_field_direct(*res, j);

				fprintf(file, "Field %s: %s\n", lpField->name, (*row)[j]);
			}

			fprintf(file, "\n");
		}

		fclose(file);
	} else {
		fprintf(stderr, "Fail create new result.txt file\n");
	}

	mysql_free_result(*res);
}

void vPrint(MYSQL **connector, const char *lpcQuery, MYSQL_RES **res, MYSQL_ROW *row) {
	vPrintResult(res, row);

	iFetchData(connector, lpcQuery, res);

	vFileResult(res, row);
}

