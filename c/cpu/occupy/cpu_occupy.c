#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "cpu_occupy.h"

/* 一个核心的详细信息，该数据用于计算利用率 */
struct __cpu_core_stat {        
    //"/proc/stat"
    //---------------------------------
    //      user     nice system    idle      iowait irq softirq  steal guest guest_nice.
    //cpu  195044598 6619 410450970 967314001 64039   0   85058  394458   0     0
    //cpu0 48705507  1701 102480874 241499274 14130   0   82302  103069   0     0
    long double user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
};

/* 数据对儿，用于计算瞬时利用率 */
struct __cpu_core_stat_pair {
    struct __cpu_core_stat stat[2]; //0-start, 1-end
    struct {
        int integer, decimal;
    }occupy;
};

/* 利用率实体，将在初始化时初始化一个全局变量实例 */
struct cpu_cores_occupy {
    
    pthread_t chk_task;
    pthread_rwlock_t info_rwlock;
    
    int nr_cpu_core;
    struct __cpu_core_stat_pair *cpus_stat;
    
};


/* 所有CPU的信息，将被 init 函数初始化 */
static struct cpu_cores_occupy all_cpu_cores_occupy;

static struct cpu_cores_occupy *cco = NULL;/* 初始化函数调用后，该指针将指向 all_cpu_cores_occupy */

/* 获取核心总数 */
int nr_cpu_cores()
{
    return sysconf(_SC_NPROCESSORS_ONLN);
}

/* 获取所有核心的详细信息 */
static int __cpu_cores_occupy_chk_get(int stat_idx/*0-start, 1-end*/)
{
    if(!cco)
        return -1;
    
    int icore = 0;
    FILE *fp;
    struct __cpu_core_stat_pair *cpus_stat = cco->cpus_stat;
    
    fp = fopen("/proc/stat","r");

    for(icore=0;icore<=cco->nr_cpu_core;icore++) {
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
                &cpus_stat[icore].stat[stat_idx].user, 
                &cpus_stat[icore].stat[stat_idx].nice, 
                &cpus_stat[icore].stat[stat_idx].system, 
                &cpus_stat[icore].stat[stat_idx].idle, 
                &cpus_stat[icore].stat[stat_idx].iowait, 
                &cpus_stat[icore].stat[stat_idx].irq, 
                &cpus_stat[icore].stat[stat_idx].softirq, 
                &cpus_stat[icore].stat[stat_idx].steal, 
                &cpus_stat[icore].stat[stat_idx].guest, 
                &cpus_stat[icore].stat[stat_idx].guest_nice);
    }
    fclose(fp);
    
    return 0;
}

/* 获取详细信息，用于计算瞬时利用率的先前时间点记录 */
static int cpu_cores_occupy_chk_getstart()
{
    return __cpu_cores_occupy_chk_get(0);
}
/* 获取详细信息，用于计算瞬时利用率的第二次的时间点记录 */
static int cpu_cores_occupy_chk_getend()
{
    return __cpu_cores_occupy_chk_get(1);
}

/* 计算所有核心的利用率 */
static int cpu_cores_occupy_chk_call()
{
    
    if(!cco)
        return -1;
    /* 写锁定 */
    pthread_rwlock_wrlock(&cco->info_rwlock);
    
    int icore = 0, idx;
    
    struct __cpu_core_stat_pair *cpus_stat = cco->cpus_stat;
    
    for(icore=0;icore<=cco->nr_cpu_core;icore++) {
        
        struct __cpu_core_stat *s0 = &cpus_stat[icore].stat[0];
        struct __cpu_core_stat *s1 = &cpus_stat[icore].stat[1];

        long double s0_0 = (s0->user+s0->nice+s0->system);
        long double s1_0 = (s1->user+s1->nice+s1->system);
        
        long double s0_1 = (s0->user+s0->nice+s0->system+s0->idle);
        long double s1_1 = (s1->user+s1->nice+s1->system+s1->idle);

        /* 计算公式 */
        long double occupy = (s1_0 - s0_0) / (s1_1 - s0_1);

        cpus_stat[icore].occupy.integer = (int)(occupy*100);
        cpus_stat[icore].occupy.decimal = (int)(occupy*10000);

//        printf("cpu%d %Lf = (%Lf - %Lf) / (%Lf - %Lf)\n", icore-1, cpus_stat[icore].occupy, s1_0, s0_0, s1_1, s0_1);                            
    }
    /* 写锁释放 */
    pthread_rwlock_unlock(&cco->info_rwlock);

    return 0;
}

/* 使用者将的回调函数将在这里被调用 */
int cpu_cores_occupy_chk_display(core_display_fn display, void *arg)
{
    if(!cco)
        return -1;
    
    assert(display!=NULL);
    
    int icore = 0;
    
    pthread_rwlock_rdlock(&cco->info_rwlock);
    struct __cpu_core_stat_pair *cpus_stat = cco->cpus_stat;
    
    for(icore=0;icore<=cco->nr_cpu_core;icore++) {
        struct core_occupy occ;
        occ.cpuid = icore-1;
        occ.occupy.integer = cpus_stat[icore].occupy.integer;
        occ.occupy.decimal = cpus_stat[icore].occupy.decimal;
        display(icore-1, &occ, arg);
        
//        printf("cpu%d \t%3d.%-4d %%\n", icore-1,cpus_stat[icore].occupy.integer, cpus_stat[icore].occupy.decimal);
    }
    pthread_rwlock_unlock(&cco->info_rwlock);

    return 0;
}

/* 定时查询参数的任务 */
void *sche_chk_task(void *arg) 
{
    if(!cco)
        return NULL;
    
    for(;;)
    {
        cpu_cores_occupy_chk_getstart(cco);/* 获取上一时刻的参数 */

        sleep(2);
        
        cpu_cores_occupy_chk_getend(cco);/* 获取当前时刻的参数 */
        
        cpu_cores_occupy_chk_call(cco);/* 利用两个时刻的数据，计算利用率 */
        
    }
    return NULL;
}

/* 初始化实体 */
int cpu_cores_occupy_chk_init()
{
    volatile static int call_once = 0;
    if(call_once != 0) return 0;
    call_once=1;
    
    cco = &all_cpu_cores_occupy;

    if(!cco)
        return -1;
    int ret;

    cco->nr_cpu_core = nr_cpu_cores();
    cco->cpus_stat = malloc(sizeof(struct __cpu_core_stat_pair)*(nr_cpu_cores()+1));

    ret = pthread_rwlock_init(&cco->info_rwlock, NULL);
    assert(ret==0);
    
    ret = pthread_create(&cco->chk_task, NULL, sche_chk_task, NULL);
    assert(ret==0);
    
    return 0;
}


