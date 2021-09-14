#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "nmx_palloc.h"

int main(){

   nmx_pool_t *pool = nmx_create_pool(1024);

    int i=0;
    char *s;
    for(i=0;i<10000;i++){
        if(i%100 == 0) {
            printf("%d/%d\n", i, 10000);
        }
        s = nmx_pcalloc (pool,800 * 10);
        nmx_pfree(pool, s);
    }

//    sleep(5);

    nmx_destroy_pool (pool);

//    sleep(5);
}
