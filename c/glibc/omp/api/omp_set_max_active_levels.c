#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_max_active_levels();
	printf("omp_get_max_active_levels = %d\n", i);
	omp_set_max_active_levels(i);
}
