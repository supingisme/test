#include <stdio.h>
#include <omp.h>
#include <pthread.h>

int main()
{
	int k = 100;
#pragma omp parallel for private(k)
	for ( k=0; k < 10; k++)
	{
		printf("k=%d\n", k);
	}
	printf("k=%d\n", k);

#pragma omp parallel for
	for ( k=0; k < 10; k++)
	{
		printf("k=%d\n", k);
	}
	printf("k=%d\n", k);

	return 0;
}
