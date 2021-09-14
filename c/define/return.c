/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 10月 09日 星期三 08:20:26 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 10月 09日 星期三 08:20:19 CST. */
#include <stdio.h>
#include <stdlib.h>

/* 带返回值的宏定义：荣涛 */
#define sum(a,b) ({int __c = a+b; __c;})

int main()
{
	int a = 2;
	int b = 3;

	printf("%d + %d = %d\n", a, b, sum(a, b));
	return 0;
}
