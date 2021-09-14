#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_nested();
	printf("omp_get_nested = %d\n", i);

}
