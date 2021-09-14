#ifndef _mymalloc_h
#define _mymalloc_h
#include <sys/types.h>

void *malloc(size_t size);
void free(void *ptr);

#endif
