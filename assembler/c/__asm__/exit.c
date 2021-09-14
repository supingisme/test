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

	/**
	 *	exit(0);
	 */
	__asm__("movq $60, %%rax \n\t"
			"movq $0, %%rdi \n\t"
			"syscall"
			:
			);

	printf("-------\n");

	return 0;
}
