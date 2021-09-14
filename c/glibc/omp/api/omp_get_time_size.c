#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_level();
	i = omp_get_time_size(i);
	//OpenMP specifications v3.0, section 3.2.18.
	printf("omp_get_time_size = %d\n", i);

}
