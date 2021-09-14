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
#include "memp.h"

#define MAX_TEST_THREAD 20


typedef struct _test_ctxt_s {
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
} test_ctxt_t;

test_ctxt_t t_ctxt[MAX_TEST_THREAD];

void curr_time_get(struct timespec *tv)
{
    clock_gettime(CLOCK_MONOTONIC, tv);
}

uint64_t time_diff_get(struct timespec *begin, struct timespec *end)
{
    if (end->tv_sec < begin->tv_sec) {
        assert(0);
    }
    
    return ((end->tv_sec - begin->tv_sec) * 1000000000 + (end->tv_nsec - begin->tv_nsec));
}


void memp_test(test_ctxt_t *p_ctxt, uint32_t size)
{
    int j = 0;
    struct timespec tv1;
    struct timespec tv2;
    uint64_t diff;
    uint8_t *p_test_addr = NULL;
    
    curr_time_get(&tv1);
    p_test_addr = memp_alloc(COMMON_MEM_POOL_ID, size);
    curr_time_get(&tv2);
    
    if (NULL == p_test_addr || (uint64_t)p_test_addr % 8 != 0) {
        assert(0);
    }
    
    memp_overflow_check((memp_block_t *)(p_test_addr - MEM_ALIGN(sizeof(memp_block_t), 8)));
    
    diff = time_diff_get(&tv1, &tv2);
    
    if (p_ctxt->alloc_max < diff) {
        p_ctxt->max_size = size;
        p_ctxt->alloc_max = diff;
    }
    
    p_ctxt->alloc_total += diff;
    
    for (j = 0; j < size; j++) {
        p_test_addr[j] = j % 255;
    }
    
    usleep(100);
            
    curr_time_get(&tv1);
    memp_free(p_test_addr);
    curr_time_get(&tv2);
    
    diff = time_diff_get(&tv1, &tv2);
    
    if (p_ctxt->free_max < diff) {
        p_ctxt->free_max = diff;
    }
    
    p_ctxt->free_total += diff;
    
    p_ctxt->count++;
    
    if (10000 == p_ctxt->count) {
        printf("\033[32m[mempol] tid %2d, alloc max = %6llu, avg = %3llu, free max = %5llu, avg = %3llu, size = %4d\033[m\n",
            p_ctxt->tid,
            p_ctxt->alloc_max, p_ctxt->alloc_total / p_ctxt->count,
            p_ctxt->free_max, p_ctxt->free_total / p_ctxt->count,
            p_ctxt->malloc_max_size);
            
        p_ctxt->alloc_total = 0;
        p_ctxt->alloc_max = 0;
        p_ctxt->free_max = 0;
        p_ctxt->free_total = 0;
        p_ctxt->count = 0;
        
        // if (1 == p_ctxt->tid) {
        //     memp_pool_show(COMMON_MEM_POOL_ID);
        // }
    }
}

void malloc_test(test_ctxt_t *p_ctxt, uint32_t size)
{
    int j = 0;
    struct timespec tv1;
    struct timespec tv2;
    uint64_t diff;
    uint8_t *p_test_addr = NULL;
    
    curr_time_get(&tv1);
    p_test_addr = malloc(size);
    curr_time_get(&tv2);

    if (NULL == p_test_addr) {
        assert(0);
    }
    
    diff = time_diff_get(&tv1, &tv2);
    
    if (p_ctxt->malloc_alloc_max < diff) {
        p_ctxt->malloc_alloc_max = diff;
    }
    
    p_ctxt->malloc_alloc_total += diff;
    
    for (j = 0; j < size; j++) {
        p_test_addr[j] = j;
    }
            
    curr_time_get(&tv1);
    free(p_test_addr);
    curr_time_get(&tv2);
    
    diff = time_diff_get(&tv1, &tv2);
    
    if (p_ctxt->malloc_free_max < diff) {
        p_ctxt->malloc_max_size = size;
        p_ctxt->malloc_free_max = diff;
    }
    
    p_ctxt->malloc_free_total += diff;
    
    p_ctxt->malloc_count++;
    
    if (10000 == p_ctxt->malloc_count) {
        printf("[malloc] tid %2d, alloc max = %6llu, avg = %3llu, free max = %5llu, avg = %3llu, size = %4d\n",
            p_ctxt->tid,
            p_ctxt->malloc_alloc_max, p_ctxt->malloc_alloc_total / p_ctxt->malloc_count,
            p_ctxt->malloc_free_max, p_ctxt->malloc_free_total / p_ctxt->malloc_count,
            p_ctxt->malloc_max_size);
            
        p_ctxt->malloc_alloc_total = 0;
        p_ctxt->malloc_alloc_max = 0;
        p_ctxt->malloc_free_max = 0;
        p_ctxt->malloc_free_total = 0;
        p_ctxt->malloc_count = 0;
    }
}


void *test_thread_fn(void *arg)
{
    uint32_t *tid = (uint32_t*)arg;
    uint32_t size;
    test_ctxt_t *p_ctxt = &t_ctxt[*tid];
    t_ctxt[*tid].tid = *tid;
    
    srand(0);
    
    while (1) {
        size = rand() % 2048;
        
        memp_test(p_ctxt, size);
        
        malloc_test(p_ctxt, size);
        
        usleep(100);
    }
}

int CoreDump(void)
{
    struct rlimit corelimit;
    
    if (prctl(PR_SET_DUMPABLE, 1) < 0)
    {
        printf("cannot enable core dump!\n");
        return -1;
    }
    
    corelimit.rlim_cur = RLIM_INFINITY;
    corelimit.rlim_max = RLIM_INFINITY;
    
    if (setrlimit(RLIMIT_CORE, &corelimit) < 0)
    {
        printf("setrlimit failed!\n");
        return -1;
    }
    
    return 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    pthread_t tid[MAX_TEST_THREAD];
    uint32_t thread_arg[MAX_TEST_THREAD];

    printf("sizeof(memp_t) = %d\n", sizeof(memp_t));
    printf("sizeof(memp_block_t) = %d\n", sizeof(memp_block_t));
    printf("sizeof(pthread_mutex_t) = %d\n", sizeof(pthread_mutex_t));
   
    CoreDump();
    
    memp_init();
    
    memp_pool_show(COMMON_MEM_POOL_ID);
    
    for (i = 0; i < MAX_TEST_THREAD; i++) {
        thread_arg[i] = i;
        pthread_create(&tid[i], NULL, test_thread_fn, &thread_arg[i]);
        
    }
        
    while (1) {
        sleep(5000);
    }
    
    memp_destroy();
}

