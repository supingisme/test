/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <omp.h>
 
typedef struct ID{
    char *name;
    int score;    
} id;
 
static id * _id = NULL;
static omp_lock_t lock;
 
id *getInstance(){
 
    omp_set_lock(&lock);
    if(_id != NULL) {
        omp_unset_lock(&lock);
        return _id;
    } else {
 
        _id = (id*)malloc(sizeof(id));
        assert(_id != NULL);
        omp_unset_lock(&lock);
        return _id;
    }
}
 
int main(){
 
    omp_set_num_threads(20);
 
    id * i1, *i2;
 
    omp_init_lock(&lock);
    #pragma omp parallel
    {
        i1 = getInstance() ;
        i1->name = "Rong";
        i1->score = omp_get_thread_num();
    }
    #pragma omp parallel 
    {
        i2 = getInstance() ;
        i2->name = "Tao";
    }
    omp_destroy_lock(&lock);
 
    if(i1 == i2)
        fprintf(stdout, " i1 == i2 \n");
 
    fprintf(stdout, "i1->name = %s, i1->score = %d\n",i1->name, i1->score);
    fprintf(stdout, "i2->name = %s, i2->score = %d\n",i2->name, i2->score);
 
    return 0 ;
}
