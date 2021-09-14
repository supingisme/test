/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 18日 星期二 08:46:20 CST. */

#include <stdio.h>
#include <stdlib.h>
int main (int argc, char* argv[])
{
	long max = atoi (argv[1]);
	long number;
	unsigned position;
	volatile unsigned result;
	/* Repeat the operation for a large number of values. */
	for (number = 1; number <= max; ++number) {
		/* Compute the position of the most significant set bit using the
		 * bsrl assembly instruction. */
		asm ("bsrl %1, %0" : "=r" (position) : "r" (number));
		//asm ("bsr %1, %0" : "=r" (position) : "r" (number));
		result = position;
	}
	return 0;
}
