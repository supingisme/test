/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 18日 星期二 08:46:20 CST. */

#include <stdio.h>
#include <stdlib.h>
int main (int argc, char* argv[])
{
	long max = atoi (argv[1]);
	long number;
	long i;
	unsigned position;
	volatile unsigned result;
	/* Repeat the operation for a large number of values. */
	for (number = 1; number <= max; ++number) {
		/* Repeatedly shift the number to the right, until the result is
		 * zero. Keep count of the number of shifts this requires. */
		for (i = (number >> 1), position = 0; i != 0; ++position)
			i >>= 1;
		/* The position of the most significant set bit is the number of
		 * shifts we needed after the first one. */
		result = position;
		printf("pos = %d\n", position);
	}
	return 0;
}
