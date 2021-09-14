#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_num_procs();
	printf("omp_get_num_procs = %d\n", i);

}
