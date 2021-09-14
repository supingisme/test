#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_max_threads();
	printf("omp_get_max_threads = %d\n", i);

}
