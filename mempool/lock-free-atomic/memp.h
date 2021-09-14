#ifndef __MEMP_H__
#define __MEMP_H__

#include <stdint.h>
#include <pthread.h>
#include "plist.h"

#define MEM_ALIGN(size, align_size) (((size) + (align_size) - 1U) & ~((align_size) - 1U))

#define ARRAY_SIZE(array) ((sizeof(array)) / (sizeof(array[0])))

#define MEMP_MAGIC (0xcf)

typedef enum {
    COMMON_MEM_POOL_ID = 0,
    MSGB_MEM_POOL_ID
}pool_id_e;

typedef struct _memp_desc_s {
    uint32_t size;
    uint32_t num;
} memp_desc_t;

typedef struct _memp_s {
    uint16_t pool_id;
    uint16_t cl_id;
    uint32_t size;              /* 内存块大小 */
    uint32_t num;               /* 内存块个数 */
    uint32_t used;              /* 当前使用个数 */
    uint32_t max;               /* 最大使用个数 */
    uint32_t min_size;          /* 最小分配大小 */
    plist_t header;
    pthread_mutex_t lock;
} memp_t;

/*mbuf留待以后做数据包管理使用*/
typedef struct _mbuf_s {
    uint32_t len;
    uint8_t *head;
    uint8_t *data;
    uint8_t *tail;
    uint8_t *end;
} mbuf_t;

typedef struct _memp_block_s {
    uint8_t magic;
    uint8_t is_alloc;
    uint16_t pool_id;           /* 内存池ID */
    uint16_t cl_id;             /* 内存簇ID */
    uint16_t padding;
    uint32_t real_size;         /* 实际使用的大小 */
    uint32_t alloc_line;              /* 申请内存的行号 */
    uint32_t free_line;
    const uint8_t *alloc_file;        /* 申请内存的文件名 */
    const uint8_t *free_file;
    uint8_t *data_ptr;
    plist_node_t node;
} memp_block_t;

typedef struct _memp_ctxt_s {
    uint16_t pool_id;
    uint16_t cl_num;
    uint32_t max_size;
    memp_desc_t *mdesc;
    memp_t **mpool;
} memp_ctxt_t;

#define memp_alloc(pool_id, size)    memp_alloc_debug(pool_id, size, __FILE__, __LINE__)
#define memp_free(ptr)    memp_free_debug(ptr, __FILE__, __LINE__)

#ifdef __cplusplus
extern "C" {
#endif

void *memp_alloc_debug(uint16_t pool_id, uint32_t size, const uint8_t *file, uint32_t line);
void memp_free_debug(void *ptr, const uint8_t *file, uint32_t line);
int memp_init(void);
int memp_destroy(void);
void memp_pool_show(uint16_t pool_id);
void memp_cl_show(uint16_t pool_id, uint16_t cl_id);

int memp_overflow_check(memp_block_t *p_block);


#ifdef __cplusplus
}
#endif

#endif
