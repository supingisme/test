#include <stdio.h>
#include "mymalloc.h"

void *malloc(size_t size)
{
	printf("call mymalloc.\n");
	return NULL;
}

void free(void *ptr)
{
	printf("call myfree.\n");
}
