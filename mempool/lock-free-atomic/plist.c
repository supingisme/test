#include <stddef.h>
#include "atomic_ops.h"
#include "plist.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

void plist_init(plist_t *p_list)
{
    p_list->tail = &p_list->head;
    p_list->head.next = NULL;
    p_list->count = 0;
}

void plist_node_init(plist_node_t *p_node)
{
    p_node->next = NULL;
}

plist_node_t *plist_get_node_atomic(plist_t *p_list)
{
    plist_node_t *p = NULL;

    do {
        p = p_list->head.next;
        if (NULL == p) {
            return NULL;
        }
    } while (!atomic_compare_swap_ptr((void **)(&p_list->head.next), p, p->next));

    atomic_dec(&p_list->count);
    p->next = NULL;
    
    return p;
}

void plist_put_node_atomic(plist_t *p_list, plist_node_t *p_node)
{
    plist_node_t *q = NULL;
    
    p_node->next = NULL;
    while (1) {
        q = p_list->tail;
        if (atomic_compare_swap_ptr((void *)(&(q->next)), NULL, (void *)p_node)) {
            break;
        } else {
            atomic_compare_swap_ptr((void *)(&(p_list->tail)), (void *)q, (void *)(q->next));
        }
    }
    atomic_compare_swap_ptr((void *)(&(p_list->tail)), (void *)q, (void *)(p_node));
    atomic_inc(&p_list->count);
}

#if 0
plist_node_t *plist_get_node_atomic(plist_t *p_list)
{
    plist_node_t *p = NULL;

    do {
        p = p_list->head;
        if (NULL == p) {
            return NULL;
        }
    } while (!atomic_compare_swap_ptr((void **)(&p_list->head), p, p->next));

    atomic_dec(&p_list->count);

    return p;
}

void plist_put_node_atomic(plist_t *p_list, plist_node_t *p_node)
{
    do {
        p_node->next = p_list->head;
    } while (!atomic_compare_swap_ptr((void **)(&p_list->head), p_node->next, p_node));
    atomic_inc(&p_list->count);
}
#endif