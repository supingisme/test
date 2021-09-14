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
		bsrl assembly instruction. */
		asm ("bsrl %1, %0" : "=r" (position) : "r" (number));
		printf("0x%16x\n", number);
		result = position;
	}
	return 0;
}
