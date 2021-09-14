#include <stdio.h>

int main()
{
	unsigned long i = 1024;

	printf("%#lx\n%#lx\n%#lx\n", i, i<<1, i>>-1);

	return 0;
}
