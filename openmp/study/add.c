#include <stdio.h>
#include <omp.h>
#include <pthread.h>

int main()
{
	int i, N = 10;
	int sum = 0;
#pragma omp parallel for
//#pragma omp for
	for(i=0;i<N;i++) {
		sum+=i;
	}
	printf("sum = %d\n", sum);

	return 0;
}
