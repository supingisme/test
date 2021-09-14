#include <stdio.h>
#include <jemalloc/jemalloc.h>
#include "swapper.h"

//thread.deallocatedp (uint64_t *) r- [--enable-stats]
//	Get a pointer to the the value that is returned by the thread.deallocated mallctl. This is useful for avoiding the 
//	overhead of repeated mallctl*() calls. Note that the underlying counter should not be modified by the application.

void get_jemalloc_thread_deallocatedp(uint64_t **value)
{
    size_t size = sizeof(uint64_t*);
    je_mallctl("thread.deallocatedp", value, &size, NULL, 0);
}

int main(int argc,char **argv)
{
    uint64_t *value = NULL;
    
    get_jemalloc_thread_deallocatedp(&value);
    printf("value = %ld\n", *value);

    char *str = je_malloc(1025);
    printf("value = %ld\n", *value);
    je_free(str);
    str = je_malloc(1025);
    printf("value = %ld\n", *value);
    je_free(str);
    str = je_malloc(1025);
    printf("value = %ld\n", *value);

}




