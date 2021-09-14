/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//封装

struct _Data;
typedef void (*process)(struct _Data* pData);
typedef struct _Data
{
	int value;
	process pProcess;
}Data;
