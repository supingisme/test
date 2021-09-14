
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include "aioperf_memory.h"


aioperf_pool_t *
aioperf_memory_pool_create(size_t size, size_t syspagesize)
{
    aioperf_pool_t          *pool = NULL;
    aioperf_normal_pool_t   *normal_pool = NULL;

    if (size == 0) {
        return NULL;
    }

    if (!(pool = aioperf_memory_alloc(sizeof(aioperf_pool_t)))) {
        return NULL;
    }

    if (size < sizeof(aioperf_normal_pool_t)) {
        size += sizeof(aioperf_normal_pool_t);
    }

    if (!(normal_pool = aioperf_memory_alloc(size))) {
        printf("memory alloc error\n");
        goto fuck_pool_release;
    }

    pool->cur_normal_pool = normal_pool;
    pool->normal_pool = normal_pool;
    pool->large_pool = NULL;

    normal_pool->cur = (char *)normal_pool + sizeof(aioperf_normal_pool_t);
    normal_pool->end = (char *)normal_pool + size;
    normal_pool->next = NULL;

    size -= sizeof(aioperf_pool_t);

    if (size < syspagesize) {
        normal_pool->max_size = size;
    } else {
        normal_pool->max_size = syspagesize;
    }

    return pool;

fuck_pool_release:
    aioperf_memory_free(pool);
    return NULL;
}

void
aioperf_memory_pool_release(aioperf_pool_t *pool)
{
    aioperf_normal_pool_t *normal = NULL;
    aioperf_normal_pool_t *temp_normal = NULL;
    aioperf_large_pool_t  *large = NULL;
    aioperf_large_pool_t  *temp_large = NULL;
    
    if (!pool) {
        return;
    }

    large = pool->large_pool;
    
    while (large) {
        temp_large = large->next;
        aioperf_memory_free(large->data);
        large = temp_large;
    }

    normal = pool->normal_pool;

    while (normal) {
        temp_normal = normal->next;
        aioperf_memory_free(normal);
        normal = temp_normal;
    }

    aioperf_memory_free(pool);
}

void *
aioperf_memory_pool_alloc(aioperf_pool_t *pool, size_t size)
{
    aioperf_normal_pool_t   *normal_pool = NULL;
    char                    *align_ptr = NULL;
    
    if (!pool || size == 0) {
        return NULL;
    }

    normal_pool = pool->cur_normal_pool;
    
    if (size <= normal_pool->max_size) {
        while (normal_pool) {
            align_ptr = (char *)(((uintptr_t)normal_pool->cur + 
                (uintptr_t)(sizeof(char *) - 1)) & ~((uintptr_t)sizeof(char *) - 1));
            if (align_ptr < normal_pool->end && (size_t)(normal_pool->end - align_ptr)
                > size) {
                normal_pool->cur = align_ptr + size;
                return align_ptr;
            }

            normal_pool = normal_pool->next;
        }

        return aioperf_memory_pool_create_next(pool, size);    
    }

    return aioperf_memory_pool_create_large(pool, size);
}


void *
aioperf_memory_pool_create_next(aioperf_pool_t *pool, size_t size)
{
    aioperf_normal_pool_t  *new_pool = NULL;
    aioperf_normal_pool_t  *cur_pool = NULL;
    aioperf_normal_pool_t  *p = NULL;
    char            *align_ptr = NULL;
    size_t           pool_size = 0;
    
    if (!pool || size == 0) {
        return NULL;
    }

    cur_pool = pool->cur_normal_pool;
    
    pool_size = (size_t)((char *)cur_pool->end - (char *)cur_pool);
    
    if (!(new_pool = aioperf_memory_alloc(pool_size))) {
        return NULL;
    }
    

    new_pool->end = (char *)new_pool + pool_size;
    new_pool->cur = (char *)new_pool + sizeof(aioperf_normal_pool_t);
    new_pool->next = NULL;
    align_ptr = (char *)(((uintptr_t)new_pool->cur + (uintptr_t)(sizeof(char *) - 1)) 
                &~ ((uintptr_t)sizeof(char *) - 1));
    new_pool->cur = align_ptr + size;

    for (p = cur_pool; p->next; p = p->next) {
        if ((size_t)(p->end - p->cur) < sizeof(char *)) {
            pool->cur_normal_pool = p->next;
        }
    }

    p->next = new_pool;
    
    return align_ptr;
}


void *
aioperf_memory_pool_create_large(aioperf_pool_t *pool, size_t size)
{
    char                 *p = NULL;
    aioperf_large_pool_t *large_pool = NULL;
    
    if (!pool || size == 0) {
        return NULL;
    }

    if (!(p = aioperf_memory_alloc(size))) {
        return NULL;
    }

    if (!(large_pool = aioperf_memory_pool_alloc(pool, 
        sizeof(aioperf_large_pool_t)))) {
        goto fuck_memory_release;
    }

    large_pool->data = p;
    large_pool->size = size;
    large_pool->next = pool->large_pool;
    pool->large_pool = large_pool;

    return p;

fuck_memory_release:
    aioperf_memory_free(p);
    return NULL;
}

void *
aioperf_memory_alloc(unsigned int size)
{
    if (size == 0) {
        return NULL;
    }
    return malloc(size);
}

void *
aioperf_memory_calloc(unsigned int size)
{
    void *p = NULL;
    
    if (size == 0)
        return NULL;

    if (!(p = aioperf_memory_alloc(size))) {
        return NULL;
    }

    aioperf_memory_set(p, 0, size);
    return p;
}

void
aioperf_memory_free(void *p)
{
    if (!p) {
        return;
    }

    free(p);
}

void *
aioperf_memory_memalign(unsigned int alignment, unsigned int size)
{
    void *p = NULL;
    
    if (size == 0) {
        return NULL;
    }

    posix_memalign(&p, alignment, size);

    return p;
}

void
aioperf_memory_set(void *s, int c, size_t n)
{
    memset(s, c, n);
}

