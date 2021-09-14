/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:00 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define debug() printf("%s:%d\n", __func__, __LINE__)

int func2()
{
	debug();
	int F2 = 23;
}

int func1(int i)
{
	debug();
	func2();
	debug();
	int F1 = 12;
}

int main(int argc, char *argv[])
{
	int i;
	for(i=0;i<argc;i++)
		printf("%s ", argv[i]);
	printf("\n");

	debug();

	printf("Hello World.\n");

	debug();

	int a__, b__, c__;

	c__ = 12;
	b__ = 24;
	a__ = b__+c__;
	printf("a__ = %d\n", a__);

	func1(123);

	debug();

	return 0;
}
