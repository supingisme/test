#include <stdio.h>
#include <omp.h>
#include <pthread.h>

int main()
{
#pragma omp parallel sections 
	{
#pragma omp section
	printf("section 1 ThreadId = %d\n", omp_get_thread_num());
#pragma omp section
	printf("section 2 ThreadId = %d\n", omp_get_thread_num());
#pragma omp section
	printf("section 3 ThreadId = %d\n", omp_get_thread_num());
#pragma omp section
	printf("section 4 ThreadId = %d\n", omp_get_thread_num());
	}

#pragma omp parallel 
	{
#pragma omp sections
	{
#pragma omp section
		printf("section 1 ThreadId = %d\n", omp_get_thread_num());
#pragma omp section
		printf("section 2 ThreadId = %d\n", omp_get_thread_num());
	}
#pragma omp sections
	{
#pragma omp section
		printf("section 3 ThreadId = %d\n", omp_get_thread_num());
#pragma omp section
		printf("section 4 ThreadId = %d\n", omp_get_thread_num());
	}
	}

	return 0;
}
