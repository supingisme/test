#ifndef _AIOPERF_MEMORY_H
#define _AIOPERF_MEMORY_H

typedef struct aioperf_pool_s           aioperf_pool_t;
typedef struct aioperf_normal_pool_s    aioperf_normal_pool_t;
typedef struct aioperf_large_pool_s     aioperf_large_pool_t;

struct aioperf_pool_s {
    aioperf_normal_pool_t   *normal_pool;
    aioperf_normal_pool_t   *cur_normal_pool;
    aioperf_large_pool_t    *large_pool;
};

struct aioperf_normal_pool_s {
    size_t                 max_size;
    char                  *cur;
    char                  *end;
    aioperf_normal_pool_t *next;
};

struct aioperf_large_pool_s {
    char    *data;
    size_t   size;
    aioperf_large_pool_t    *next;
};

    
aioperf_pool_t *
aioperf_memory_pool_create(size_t size, size_t syspagesize);
void
aioperf_memory_pool_release(aioperf_pool_t *pool);
void *
aioperf_memory_pool_alloc(aioperf_pool_t *pool, size_t size);
void *
aioperf_memory_pool_create_next(aioperf_pool_t *pool, size_t size);
void *
aioperf_memory_pool_create_large(aioperf_pool_t *pool, size_t size);
void *
aioperf_memory_alloc(unsigned int size);
void *
aioperf_memory_calloc(unsigned int size);
void
aioperf_memory_free(void *p);
void *
aioperf_memory_memalign(unsigned int alignment, unsigned int size);
void
aioperf_memory_set(void *s, int c, size_t n);

#endif
