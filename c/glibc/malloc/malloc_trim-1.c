#include <malloc.h>
#define NUM_CHUNKS 1000000
#define CHUNCK_SIZE 100
int main()
{
    unsigned int i;
	// disable fast bins
	mallopt(M_MXFAST, 0);
	void **array = (void **) malloc(sizeof(void *) * NUM_CHUNKS);
	// allocating memory
	for (i = 0; i < NUM_CHUNKS; i++)
	{
		array[i] = malloc(CHUNCK_SIZE);
	}
	// releasing memory ALMOST all memory
	for (i = 0; i < NUM_CHUNKS - 1; i++)
	{
		free(array[i]);
	}
	// when enabled memory consumption reduces
	int ret = malloc_trim(0);
	printf("ret=%d\n", ret);
	malloc_stats();
	sleep(100000);
}

////没使用 malloc_trim(0);
//    Arena 0:
//    system bytes     =  112054272
//    in use bytes     =        112
//    Total (incl. mmap):
//    system bytes     =  120057856
//    in use bytes     =    8003696
//    max mmap regions =          1
//    max mmap bytes   =    8003584
//
//
////使用 malloc_trim(0);
//    Arena 0:
//    system bytes     =  112001024
//    in use bytes     =        112
//    Total (incl. mmap):
//    system bytes     =  120004608
//    in use bytes     =    8003696
//    max mmap regions =          1
//    max mmap bytes   =    8003584

