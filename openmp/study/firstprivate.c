#include <stdio.h>
#include <omp.h>
#include <pthread.h>

int main()
{
int k = 100;
int i;
#pragma omp parallel for firstprivate(k)
for ( i=0; i < 4; i++)
{
	k+=i;
	printf("k=%d\n",k);
}
printf("last k=%d\n", k);

	return 0;
}
