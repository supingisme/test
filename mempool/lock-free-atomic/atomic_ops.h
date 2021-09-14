#ifndef _ATOMIC_OPS_H_
#define _ATOMIC_OPS_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define atomic_set(var, val) __sync_lock_test_and_set(&(var), val)

#define atomic_read(var) __sync_val_compare_and_swap(&(var), 0, 0)

static inline void atomic_inc(uint32_t *ptr)
{
    __sync_fetch_and_add(ptr, 1);
}

static inline void atomic_dec(uint32_t *ptr)
{
    __sync_fetch_and_sub(ptr, 1);
}

static inline int atomic_compare_swap_ptr(void **ptr, void *old_value, void *new_value)
{
    return __sync_bool_compare_and_swap(ptr, old_value, new_value);
}

#ifdef __cplusplus
}
#endif

#endif
