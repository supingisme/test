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
 * Description: this is the header file for the sample about how to fetch all table name in specific database in C programming language
 * */

#ifndef _TABLE_NAME_H_

#define _TABLE_NAME_H_

#include "connector.h"

#define ERROR_NULL_CON_FDT -1
#define ERROR_CREATE_QUERY_FDT -2
#define SUCCESS_RESULT_QUERY 0

int iFetchData(MYSQL **connector, const char *lpcQuery, MYSQL_RES **res);
void vPrintResult(MYSQL_RES **res, MYSQL_ROW *row);
void vFileResult(MYSQL_RES **res, MYSQL_ROW *row);
void vPrint(MYSQL **connector, const char *lpcQuery, MYSQL_RES **res, MYSQL_ROW *row);

#endif

