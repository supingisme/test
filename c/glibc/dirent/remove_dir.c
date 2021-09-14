/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
 *	递归删除目录
 */
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int remove_dir(const char *dir)
{
	char cur_dir[] = ".";
	char up_dir[] = "..";

	char dir_name[128];
	DIR *dirp;
	struct dirent *dp;
	struct stat dir_stat;

	/*directory not exist*/
	if(0 != access(dir, F_OK))
	{
		return 0;
	}

	/*get attribution error*/
	if(0 > stat(dir, &dir_stat))
	{
		perror("get directory stat error.");
		return -1;
	}

	/*regular file, delete*/
	if(S_ISREG(dir_stat.st_mode))
	{
		remove(dir);
	}
	else if(S_ISDIR(dir_stat.st_mode))
	{
		dirp = opendir(dir);
		while((dp = readdir(dirp))!= NULL)
		{
			if((0 == strcmp(cur_dir, dp->d_name)) ||
			   (0 == strcmp(up_dir, dp->d_name)) )
			{
				continue;
			}
			sprintf(dir_name, "%s/%s", dir, dp->d_name);
			remove_dir(dir_name);
		}
		closedir(dirp);

		rmdir(dir);
	}
	else
	{
		perror("unknow file type!");
	}
}


int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("usage: %s <dir>\n", argv[0]);
	}
	remove_dir(argv[1]);

	return 0;
}
