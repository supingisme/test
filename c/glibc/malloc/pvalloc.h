#include <malloc.h>

//allocate aligned memory
void *pvalloc(size_t size);
//The  obsolete  function pvalloc() is similar to valloc(), but rounds the size of the allocation up to the
//       next multiple of the system page size.
//等于 aligned_alloc(getpagesize(), size);
//The memory address will be a multiple of the page 
//    size.   It  is  equivalent  to  memalign(sysconf(_SC_PAGE‐SIZE),size).




