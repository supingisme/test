#include <stdio.h>

int main()
{
	int cnt = 0;
	while(1)
	{
		fprintf(stdout, "Hello World. %d\n", cnt++);
		sleep(1);
	}
	return 0;
}
