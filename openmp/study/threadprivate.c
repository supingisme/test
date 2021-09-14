#include <stdio.h>
#include <omp.h>
#include <pthread.h>

int counter = 0;
#pragma omp threadprivate(counter)
int increment_counter()
{
	counter++;
	return(counter);
}

int increment_counter2()
{
	static int counter = 0;
#pragma omp threadprivate(counter)
	counter++;
	return(counter);
}

int main()
{
	printf("%d\n", increment_counter());
	printf("%d\n", increment_counter2());

	return 0;
}
