/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 11月 03日 星期二 08:42:41 CST. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret = mkdir("mkmkmk", 0777);

	printf("ret: %d\n", ret);

	return 0;
}

