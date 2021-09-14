#include <stdlib.h>

//posix_memalign, aligned_alloc, memalign, valloc, pvalloc - allocate aligned memory

void *valloc(size_t size);
//等于 aligned_alloc(getpagesize(), size);
//The memory address will be a multiple of the page 
//    size.   It  is  equivalent  to  memalign(sysconf(_SC_PAGE‐SIZE),size).


