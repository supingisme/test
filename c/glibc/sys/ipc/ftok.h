/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */



/**
 *	NAME
 *	ftok - convert a pathname and a project identifier to a System V IPC key
 *
 *	SYNOPSIS
 *	#include <sys/types.h>
 *	#include <sys/ipc.h>
 *
 *	key_t ftok(const char *pathname, int proj_id);
 */

#include <sys/types.h>
#include <sys/ipc.h>

key_t ftok(const char *pathname, int proj_id);
/**
 *	key_t 键 和 ftok函数
 *
 *	函数ftok把一个已经存在的路径名和一个整数标识符转换成一个key_t值，称为IPC键
 */


