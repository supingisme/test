#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdint.h>

typedef struct _plist_node_s
{
    struct _plist_node_s *next;
} plist_node_t;

typedef struct _plist_s
{
    plist_node_t head;
    plist_node_t *tail;
    uint32_t count;
} plist_t;

#define PLIST_ENTRY(ptr, type, member) ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

#ifdef __cplusplus
extern "C" {
#endif

    void plist_init(plist_t *p_list);
    
    void plist_node_init(plist_node_t *p_node);

    plist_node_t *plist_get_node_atomic(plist_t *p_list);

    void plist_put_node_atomic(plist_t *p_list, plist_node_t *p_node);

#ifdef __cplusplus
}
#endif

#endif