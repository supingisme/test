#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_level();
	printf("omp_get_level = %d\n", i);

}
