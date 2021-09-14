#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>
#include <sys/prctl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "ncx_slab.h"



typedef struct __test_ctx_t {
    int tid;
    uint32_t max_size;
    uint64_t alloc_max;
    uint64_t alloc_total;
    uint64_t free_max;
    uint64_t free_total;
    uint64_t count;
    
    uint32_t malloc_max_size;
    uint64_t malloc_alloc_max;
    uint64_t malloc_alloc_total;
    uint64_t malloc_free_max;
    uint64_t malloc_free_total;
    uint64_t malloc_count;
} test_ctx_t;



void test_get_current_timespec(struct timespec *tv)
{
    clock_gettime(CLOCK_MONOTONIC, tv);
}


uint64_t test_get_timespec_diff(struct timespec *begin, struct timespec *end)
{
    if (end->tv_sec < begin->tv_sec) {
        assert(0);
    }
    
    return ((end->tv_sec - begin->tv_sec) * 1000000000 + (end->tv_nsec - begin->tv_nsec));
}


void test_malloc_and_free(test_ctx_t *p_ctxt, uint32_t size)
{
    int j = 0;
    struct timespec tv1;
    struct timespec tv2;
    uint64_t diff;
    uint8_t *p_test_addr = NULL;
    
    test_get_current_timespec(&tv1);
    p_test_addr = (uint8_t *)malloc(size);
    test_get_current_timespec(&tv2);

    if (NULL == p_test_addr) {
        printf("error malloc.\n");
        assert(0);
    }
    
    diff = test_get_timespec_diff(&tv1, &tv2);
    
    if (p_ctxt->malloc_alloc_max < diff) {
        p_ctxt->malloc_alloc_max = diff;
    }
    
    p_ctxt->malloc_alloc_total += diff;
    
    for (j = 0; j < size; j++) {
        p_test_addr[j] = (uint8_t )j;
    }
            
    test_get_current_timespec(&tv1);
    free(p_test_addr);
    test_get_current_timespec(&tv2);
    
    diff = test_get_timespec_diff(&tv1, &tv2);
    
    if (p_ctxt->malloc_free_max < diff) {
        p_ctxt->malloc_max_size = size;
        p_ctxt->malloc_free_max = diff;
    }
//    printf("-%d-",p_ctxt->malloc_count);
    p_ctxt->malloc_free_total += diff;
    
    p_ctxt->malloc_count++;
    
    if (10000 == p_ctxt->malloc_count) {
//        printf("-%d-",p_ctxt->malloc_count);
        printf("[malloc] tid %2d, alloc max = %6llu, avg = %3llu, free max = %5llu, avg = %3llu, size = %4d\n",
            p_ctxt->tid,
            p_ctxt->malloc_alloc_max, p_ctxt->malloc_alloc_total / p_ctxt->malloc_count,
            p_ctxt->malloc_free_max, p_ctxt->malloc_free_total / p_ctxt->malloc_count,
            p_ctxt->malloc_max_size);
        fflush(stdout);
        p_ctxt->malloc_alloc_total = 0;
        p_ctxt->malloc_alloc_max = 0;
        p_ctxt->malloc_free_max = 0;
        p_ctxt->malloc_free_total = 0;
        p_ctxt->malloc_count = 0;
    }
}



int main(int argc, char **argv)
{
	int i;
    
//    test_ctx_t ctx;
//
//    for(i=0;i<10003;i++) {
//        test_malloc_and_free(&ctx, 100+i);
////        printf("-%d-\n",ctx.malloc_count);
//    }
//    printf("test malloc done.\n");
    
	char *p;
	size_t 	pool_size = 4096000;  //4M 
	ncx_slab_stat_t stat;
	u_char 	*space;
	space = (u_char *)malloc(pool_size);

	ncx_slab_pool_t *sp;
	sp = (ncx_slab_pool_t*) space;

	sp->addr = space;
	sp->min_shift = 3;
	sp->end = space + pool_size;

	ncx_slab_init(sp);

	for (i = 0; i < 1000000; i++) 
	{   
		p = ncx_slab_alloc(sp, 128 + i); 
		if (p == NULL) 
		{   
			printf("%d\n", i); 
			return -1; 
		}   
		ncx_slab_free(sp, p); 
	}   
	ncx_slab_stat(sp, &stat);

	printf("##########################################################################\n");
	for (i = 0; i < 2500; i++) 
	{   
		p = ncx_slab_alloc(sp, 30 + i); 
		if (p == NULL) 
		{   
			printf("%d\n", i); 
			return -1; 
		}   
		
		if (i % 3 == 0) 
		{
			ncx_slab_free(sp, p);
		}
	}   
	ncx_slab_stat(sp, &stat);

	free(space);

    while(1) {
        sleep(1);
        }

	return 0;
}
