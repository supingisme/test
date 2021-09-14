#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_dynamic();
	printf("omp_get_dynamic = %d\n", i);
	omp_set_dynamic(i);
	//printf("omp_set_dynamic = %d\n", i);
}
