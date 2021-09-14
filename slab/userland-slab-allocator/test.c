#include "slab.h"
#include <unistd.h>
#include <assert.h>



#define SLAB_DUMP(slab) { \
    puts("\033c"); \
    slab_props(stdout, &slab); \
    puts(""); \
    slab_stats(stdout, &slab); \
    puts(""); \
    slab_dump(stdout, &slab); \
    fflush(stdout); \
    usleep(8000); \
}




void demo_double(void)
{
    setvbuf(stdout, NULL, _IOFBF, 0xFFFF);

    double *allocs[16 * 60];
    
    struct slab_chain slab;
    
    slab_pagesize = (size_t) sysconf(_SC_PAGESIZE);
    slab_init(&slab, sizeof(double));
    
    size_t i;
    for (i = 0; i < sizeof(allocs) / sizeof(*allocs); i++) {
        allocs[i] = slab_alloc(&slab);
        assert(allocs[i] != NULL);
        *allocs[i] = i * 4;
        SLAB_DUMP(slab);
    }
    ssize_t j;
    for (j = sizeof(allocs) / sizeof(*allocs) - 1; j >= 0; j--) {
        slab_free(&slab, allocs[j]);
        SLAB_DUMP(slab);
    }

    slab_destroy(&slab);

    return ;
}



void demo_structure(void)
{
    struct test {double f;double i; double d;double s;};
    
    setvbuf(stdout, NULL, _IOFBF, 0xFFFF);

    struct test *allocs[16 * 60];
    
    struct slab_chain slab;
    
    slab_pagesize = sizeof(struct test)*64;//(size_t) sysconf(_SC_PAGESIZE);
    slab_init(&slab, sizeof(struct test));
    
    size_t i;
    for (i = 0; i < sizeof(allocs) / sizeof(*allocs); i++) {
        allocs[i] = slab_alloc(&slab);
        assert(allocs[i] != NULL);
        (*allocs[i]).f = i * 4;
        (*allocs[i]).i = i * 4;
        (*allocs[i]).d = i * 4;
        (*allocs[i]).s = i * 4;
        SLAB_DUMP(slab);
    }
    ssize_t j;
    for (j = sizeof(allocs) / sizeof(*allocs) - 1; j >= 0; j--) {
        slab_free(&slab, allocs[j]);
        SLAB_DUMP(slab);
    }

    slab_destroy(&slab);

    return ;
}




int main(void)
{
//    demo_double();
    demo_structure();
    return 0;
}

