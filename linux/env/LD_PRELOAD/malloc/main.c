#include "mymalloc.h"
#include <malloc.h>
#include <stdio.h>

int main()
{
	void *ptr = malloc(10);
	free(ptr);
}
