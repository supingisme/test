#include <stdio.h>

#include "memory_pool.h"

int main()
{
    int ret;

    memory_pools_handle_t mhandle = memory_pools_create (3);

    ret = memory_pools_add_pool (mhandle, 5, 256);
    printf("memory_pools_add_pool ret = %d\n", ret);
    ret = memory_pools_add_pool (mhandle, 5, 256);
    printf("memory_pools_add_pool ret = %d\n", ret);
    ret = memory_pools_add_pool (mhandle, 5, 256);
    printf("memory_pools_add_pool ret = %d\n", ret);

    memory_pool_item_handle_t mihandle = memory_pools_allocate (mhandle, 256, 1, 1);

    
    memory_pools_set_info (mhandle, mihandle, 1, 1);

    
    ret = memory_pools_free (mhandle, mihandle, 1);
    printf("memory_pools_free ret = %d\n", ret);

    
    return 0;
}
