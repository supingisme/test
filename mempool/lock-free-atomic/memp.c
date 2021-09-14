#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "atomic_ops.h"
#include "memp.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

#define MEMP_LOCK

#undef MUTEX_INIT
#undef MUTEX_DESTROY
#undef MUTEX_LOCK
#undef MUTEX_UNLOCK
#undef MUTEX_TRYLOCK

#ifdef MEMP_LOCK
    #define MUTEX_INIT(x)         pthread_mutex_init(x, NULL)
    #define MUTEX_DESTROY(x)      pthread_mutex_destroy(x)
    #define MUTEX_LOCK(x)         pthread_mutex_lock(x)
    #define MUTEX_UNLOCK(x)       pthread_mutex_unlock(x)
    #define MUTEX_TRYLOCK(x)      pthread_mutex_trylock(x)
#else
    #define MUTEX_INIT(x)
    #define MUTEX_DESTROY(x)
    #define MUTEX_LOCK(x)
    #define MUTEX_UNLOCK(x)
    #define MUTEX_TRYLOCK(x)  (0)
#endif

static memp_desc_t g_comm_pool_desc[] = {
    {8, 100},
    {16, 100},
    {32, 100},
    {64, 100},
    {128, 100},
    {256, 100},
    {512, 100},
    {1024, 100},
    {2048, 100},
    {4096, 100},
    {0, 0}
};

static memp_desc_t g_msgb_pool_desc[] = {
    {512, 100},
    {1024, 100},
    {1600, 10000},
    {2048, 10000},
    {0, 0}
};

static memp_ctxt_t g_memp_ctxt[] = {
    {COMMON_MEM_POOL_ID, 0, 0, &g_comm_pool_desc[0], NULL},
    {MSGB_MEM_POOL_ID, 0, 0, &g_msgb_pool_desc[0], NULL}
};

static void memp_pool_config_init(uint16_t pool_id)
{
    uint32_t max_size = 0;
    memp_desc_t *p_pool_desc = g_memp_ctxt[pool_id].mdesc;

    while ((0 != p_pool_desc->num) && (0 != p_pool_desc->size)) {
        p_pool_desc->size = MEM_ALIGN(p_pool_desc->size, 8);
        if (p_pool_desc->size > max_size) {
            max_size = p_pool_desc->size;
        }
        g_memp_ctxt[pool_id].cl_num++;
        p_pool_desc++;
    }
    g_memp_ctxt[pool_id].max_size = max_size;
}

static memp_t *pool_create(uint16_t pool_id, uint16_t cl_id)
{
    uint32_t i = 0;
    uint32_t real_size = 0;
    uint32_t head_len = 0;
    memp_t *p_pool = NULL;
    memp_desc_t *p_desc = NULL;
    memp_block_t *p_block = NULL;
    
    p_desc = &g_memp_ctxt[pool_id].mdesc[cl_id];

    head_len = MEM_ALIGN(sizeof(memp_t), 8);
    real_size = MEM_ALIGN(p_desc->size, 8) + MEM_ALIGN(sizeof(memp_block_t), 8);

    p_pool = (memp_t *)malloc(head_len + real_size * p_desc->num);
    if (NULL == p_pool) {
        return NULL;
    }
    memset((uint8_t *)p_pool, 0, head_len + real_size * p_desc->num);

    p_pool->pool_id = pool_id;
    p_pool->cl_id = cl_id;
    p_pool->size = p_desc->size;
    p_pool->num = p_desc->num;
    p_pool->used = 0;
    p_pool->max =  0;
    p_pool->min_size = p_desc->size;
    plist_init(&p_pool->header);
    MUTEX_INIT(&p_pool->lock);
    
    p_block = (memp_block_t *)((uint8_t *)p_pool + head_len);
    for (i = 0; i < p_pool->num; i++) {
        p_block->magic = MEMP_MAGIC;
        p_block->is_alloc = 0;
        p_block->pool_id = pool_id;
        p_block->cl_id = cl_id;
        p_block->real_size = p_pool->size;
        p_block->alloc_file = NULL;
        p_block->alloc_line = 0;
        p_block->free_file = NULL;
        p_block->free_line = 0;
        p_block->data_ptr = (uint8_t *)p_block + MEM_ALIGN(sizeof(memp_block_t), 8);
        plist_node_init(&p_block->node);
        plist_put_node_atomic(&p_pool->header, &p_block->node);

        p_block = (memp_block_t *)((uint8_t *)p_block + real_size);
    }

    return p_pool;
}

static void pool_destroy(memp_t *p_pool)
{
    MUTEX_DESTROY(&p_pool->lock);
    free(p_pool);
}

int memp_pool_init(uint16_t pool_id)
{
    int err = 0;
    uint32_t i = 0;
    memp_ctxt_t *p_ctxt = &g_memp_ctxt[pool_id];
    memp_desc_t *p_desc = p_ctxt->mdesc;

    memp_pool_config_init(pool_id);

    p_ctxt->mpool = (memp_t **)malloc(p_ctxt->cl_num * sizeof(memp_t *));
    if (NULL == p_ctxt->mpool) {
        return -1;
    }
    memset(p_ctxt->mpool, 0, p_ctxt->cl_num * sizeof(memp_t *));

    for (i = 0; i < p_ctxt->cl_num; i++) {
        p_ctxt->mpool[i] = pool_create(pool_id, i);
        if (NULL == p_ctxt->mpool[i]) {
            err = -2;
            goto error;
        }
    }

    return 0;
    
error:
    for (i = 0; i < p_desc->num; i++) {
        if (p_ctxt->mpool[i]) {
            pool_destroy(p_ctxt->mpool[i]);
            p_ctxt->mpool[i] = NULL;
        }
    }
    free(p_ctxt->mpool);
    p_ctxt->mpool = NULL;

    return err;
}

static void memp_pool_destroy(uint16_t pool_id)
{
    uint32_t i = 0;
    memp_ctxt_t *p_ctxt = &g_memp_ctxt[pool_id];

    if (p_ctxt->mpool) {
        for (i = 0; i < p_ctxt->cl_num; i++) {
            if (p_ctxt->mpool[i]) {
                pool_destroy(p_ctxt->mpool[i]);
                p_ctxt->mpool[i] = NULL;
            }
        }
        free(p_ctxt->mpool);
        p_ctxt->mpool = NULL;
    }
    p_ctxt->cl_num = 0;
}

int memp_init(void)
{
    int err = 0;
    uint16_t i = 0;

    for (i = 0; i < ARRAY_SIZE(g_memp_ctxt); i++) {
        assert(g_memp_ctxt[i].pool_id == i);
        if (memp_pool_init(i) < 0) {
            err = -1;
            goto error;
        }
    }

    return 0;
    
error:
    memp_destroy();
    return err;
}

int memp_destroy(void)
{
    uint16_t i = 0;

    for (i = 0; i < ARRAY_SIZE(g_memp_ctxt); i++) {
        assert(g_memp_ctxt[i].pool_id == i);
        memp_pool_destroy(i);
    }

    return 0;
}

/*内存踩踏检查，判断魔术字是否被踩*/
int memp_overflow_check(memp_block_t *p_block)
{
    if (MEMP_MAGIC != p_block->magic || 
        MEMP_MAGIC != p_block->data_ptr[p_block->real_size]) {
        return 1;
    }
    
    return 0;
}

static void *memp_pool_alloc(memp_t *p_pool, uint32_t size, const uint8_t *file, uint32_t line)
{
    plist_node_t *p_node = NULL;
    memp_block_t *p_block = NULL;
    
    // if (0 != MUTEX_TRYLOCK(&p_pool->lock)) {
    //     return NULL;
    // }
    
    p_node = plist_get_node_atomic(&p_pool->header);
    if (NULL == p_node) {
        // MUTEX_UNLOCK(&p_pool->lock);
        if (p_pool->header.count > 5) {
            printf("mem pool not empty!\n");
            assert(0);
        }
        return NULL;
    }
    // MUTEX_UNLOCK(&p_pool->lock);
    atomic_inc(&p_pool->used);
    
    p_block = PLIST_ENTRY(p_node, memp_block_t, node);
    if (p_block->magic != MEMP_MAGIC) {
        assert(0);
    }
    if (1 == atomic_read(p_block->is_alloc)) {
        printf("error block, %d %p %p %p\n", p_block->is_alloc, p_block->data_ptr, &p_block->node, p_block->node.next);
        memp_cl_show(p_block->pool_id, p_block->cl_id);
        assert(0);
    }
    if (p_block->pool_id != p_pool->pool_id || p_block->cl_id != p_pool->cl_id) {
        assert(0);
    }
    
    p_block->is_alloc = 1;
    // atomic_set(p_block->is_alloc, 1);
    p_block->real_size = size;
    p_block->alloc_file = file;
    p_block->alloc_line = line;
    p_block->free_file = NULL;
    p_block->free_line = 0;
    p_block->data_ptr[size] = MEMP_MAGIC;
    plist_node_init(&p_block->node);

    if (p_pool->used > p_pool->max)
        p_pool->max = p_pool->used;
    
    if (p_pool->min_size > size) 
        p_pool->min_size = size;
    
    return p_block->data_ptr;
}

void *memp_alloc_debug(uint16_t pool_id, uint32_t size, const uint8_t *file, uint32_t line)
{
    uint32_t i = 0;
    uint8_t *p = NULL;
    memp_ctxt_t *p_ctxt = NULL;
    
    if (pool_id > ARRAY_SIZE(g_memp_ctxt)) {
        return NULL;
    }
    
    p_ctxt = &g_memp_ctxt[pool_id];
    if (p_ctxt->max_size < size) {
        return NULL;
    }
    
    for (i = 0; i < p_ctxt->cl_num; i++) {
        if (p_ctxt->mpool[i]->size < size) {
            continue;
        }
        
        p = memp_pool_alloc(p_ctxt->mpool[i], size, file, line);
        if (NULL == p) {
            continue;
        }
        
        return p;
    }
    
    assert(0);
    return NULL;
}

void memp_free_debug(void *ptr, const uint8_t *file, uint32_t line)
{
    memp_t *p_pool = NULL;
    memp_block_t *p_block = NULL;
    
    p_block = (memp_block_t *)((uint8_t *)ptr - MEM_ALIGN(sizeof(memp_block_t), 8));
    if (0 == atomic_read(p_block->is_alloc)) {
        printf("double free!\n");
        memp_cl_show(p_block->pool_id, p_block->is_alloc);
        assert(0);
        return;
    }
    
    /*内存踩踏检查*/
    if (memp_overflow_check(p_block)) {
        assert(0);
    }
    
    p_block->is_alloc = 0;
    p_block->free_file = file;
    p_block->free_line = line;
    
    p_pool = g_memp_ctxt[p_block->pool_id].mpool[p_block->cl_id];    
    atomic_dec(&p_pool->used);
    plist_put_node_atomic(&p_pool->header, &p_block->node);
}

void memp_cl_show(uint16_t pool_id, uint16_t cl_id)
{
    int i = 0;
    memp_ctxt_t *p_ctxt = NULL;
    memp_t *p_memp = NULL;
    memp_block_t *p_block = NULL;
    
    p_memp = g_memp_ctxt[pool_id].mpool[cl_id];
    
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
        "pool_id",
        "cl_id",
        "size",
        "is_alloc",
        "magic",
        "data_ptr",
        "node_ptr",
        "next_ptr");
        
    p_block = (memp_block_t *)((uint8_t *)p_memp + MEM_ALIGN(sizeof(memp_t), 8));
    for (i = 0; i < p_memp->num; i++) {
        printf("%-10d %-10d %-10d %-10d %-10d %-10p %-10p %-10p\n",
                p_block->pool_id,
                p_block->cl_id,
                p_block->real_size,
                p_block->is_alloc,
                p_block->magic,
                p_block->data_ptr,
                &p_block->node,
                p_block->node.next);

        p_block = (memp_block_t *)((uint8_t *)p_block + MEM_ALIGN(p_memp->size, 8) + MEM_ALIGN(sizeof(memp_block_t), 8));
    }
}

void memp_pool_show(uint16_t pool_id)
{
    int i = 0;
    memp_ctxt_t *p_ctxt = NULL;
    
    p_ctxt = &g_memp_ctxt[pool_id];
        
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
        "pool_id",
        "cl_id",
        "size",
        "is_alloc",
        "data_ptr",
        "node_ptr",
        "next_ptr");
    
    for (i = 0; i < p_ctxt->cl_num; i++) {
        plist_node_t *p_node = NULL;
        memp_t *p_memp = p_ctxt->mpool[i];
        memp_block_t *p_block = NULL;
        if (p_memp) {
            p_node = p_memp->header.head.next;
            
            while (NULL != p_node) {
                p_block = PLIST_ENTRY(p_node, memp_block_t, node);
                
                printf("%-10d %-10d %-10d %-10d %-10p %-10p %-10p\n",
                    p_block->pool_id,
                    p_block->cl_id,
                    p_block->real_size,
                    p_block->is_alloc,
                    p_block->data_ptr,
                    &p_block->node,
                    p_block->node.next);
                
                p_node = p_block->node.next;
            }
        }
    }
}