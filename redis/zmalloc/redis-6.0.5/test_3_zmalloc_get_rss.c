#include "zmalloc.h"

#define UNUSED(x) ((void)(x))
int zmalloc_test(int argc, char **argv) {
    void *ptr;

    UNUSED(argc);
    UNUSED(argv);
    printf("Initial used memory: %zu\n", zmalloc_get_rss());
    ptr = zmalloc(123);
    printf("Allocated 123 bytes; used: %zu\n", zmalloc_get_rss());
    ptr = zrealloc(ptr, 1025);
    printf("Reallocated to 456 bytes; used: %zu\n", zmalloc_get_rss());
    zfree(ptr);
    printf("Freed pointer; used: %zu\n", zmalloc_get_rss());
    return 0;
}

int main(int argc, char **argv)
{
    zmalloc_test(argc, argv);
}

