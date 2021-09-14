#include <omp.h>
#include <stdio.h>

int main()
{
	int i = omp_get_thread_num();
	printf("omp_get_thread_num = %d\n", i);

}
