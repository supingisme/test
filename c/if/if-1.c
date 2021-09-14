#include <stdio.h>

int main()
{
	int i = -199;
	printf("i = %d, !i = %d\n", i, !i);
	if(!i)
	{
		printf("!-1 is ok\n");
	}
	return 0;
}
