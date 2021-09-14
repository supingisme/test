#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_in_parallel();
	printf("omp_in_parallel = %d\n", i);

}
