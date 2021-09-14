#include <omp.h>
#include <stdio.h>

int main()
{
	double d = omp_get_wtick();
	printf("omp_get_wtick = %lf\n", d);

}
