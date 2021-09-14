/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 18:06:12 CST. */
#include <string.h>
#include <stdio.h>

int main()
{
	char *str = "hello world\n";
	long len = strlen(str);

	int ret = 0;

	/**
	 *	write(2, str, len);
	 */
	__asm__("movq $1, %%rax \n\t"
			"movq $2, %%rdi \n\t"
			"movq %1, %%rsi \n\t"
			"movl %2, %%edx \n\t"
			"syscall"
			: "=g"(ret)
			: "g"(str), "g" (len)
		    );

	/*
	 *	hello.c:24: Error: unsupported instruction `mov'
	 *
	__asm__("mov %%rax, $1 \n\t"
			"mov %%rdi, $2 \n\t"
			"mov %%rsi, %1 \n\t"
			"mov %%edx, %2 \n\t"
			"syscall"
			: "=g"(ret)
			: "g"(str), "g"(len)
			);
	*/
	/**
	 *	exit(0);
	 */
	__asm__("movq $60, %%rax \n\t" /*查询syscall表，60对应exit*/
			"movq %1, %%rdi \n\t" /*寄存器rdi，第一个参数，对应exit(0)的0*/
			"syscall"
			: "=g"(ret) /*返回值*/
			: "g"(0) /*第一个参数，对应%1*/
			);

	printf("-------\n");

	return 0;
}
