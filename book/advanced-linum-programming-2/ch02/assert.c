/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 26日 星期三 08:58:16 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 21日 星期五 08:57:16 CST. */
#include <assert.h>
#include <stdio.h>

#define debug() printf("%s:%d\n", __func__, __LINE__)

int main()
{
	debug();
	assert(1);
	debug();
	assert(0);	//为“假”则报错：a.out: assert.c:11: main: Assertion `0' failed.
	debug();
}
