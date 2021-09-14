#include <stdio.h>

int main()
{
	volatile int i,j,k;
	while(1) {
		sleep(2);
		i = 1;
		j = i+1;
		printf(">> i = %d, j = %d\n", i, j);
	}
}
