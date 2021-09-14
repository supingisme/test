#include <omp.h>
#include <stdio.h>

int main()
{
	//omp_schedule(omp_sched_t * kind, int *modifier);
	//Reference: OpenMP specifications v3.0, section 3.2.12.
	omp_sched_t kind;
	int modifier;
	omp_schedule(&kind, &modifier);
	printf("omp_schedule modifier = %d\n", modifier);

}
