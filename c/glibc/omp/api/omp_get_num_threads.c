#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_num_threads();
	printf("omp_get_num_threads = %d\n", i);

}
