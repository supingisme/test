#include <math.h>
#include <stdio.h>

static int count  = 0;

int add(int a, int b)
{
	count ++;

	printf("count = %d\n", count);
	return a+b;
}
