#include <malloc.h>


//malloc_trim - release free memory from the top of the heap
//使用 malloc_trim()可把之前分配的内存还给系统。
void malloc_trim(size_t pad);

