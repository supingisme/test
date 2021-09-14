/**
 *  fs_occupy - 遍历系统文件系统，并查询其磁盘使用率（有效磁盘）
 *  
 *  日期：2020年10月15日
 *  作者：荣涛
 */
#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>
#include <pthread.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <sys/statfs.h>

#include "list.h"
#include "fs_occupy.h"

#ifndef weak_alias
#define weak_alias(name, aliasname) extern typeof (name) aliasname __attribute__ ((weak, alias(#name)))
#endif


/* 文件系统列表 */
struct crypto_fs_system {
    struct fs_occupy_info occupy_info;
    struct list_head list;
};


/* 为了线程安全 */
static pthread_rwlock_t fs_rwlock = PTHREAD_RWLOCK_INITIALIZER;
static LIST_HEAD(fs_list);/*多文件系统链表头  */

/* 返回0，有效的文件系统，可以统计出使用率
   返回其他，无效的文件系统，不可以统计使用率
*/
static int calculate_fs_occupy_nonlock(struct fs_occupy_info *info)
{
    struct statfs diskInfo;
    memset(&diskInfo, 0, sizeof(struct statfs));

    /* 获取文件系统属性 */
    statfs(info->fs_mnt_dir, &diskInfo);

    /* 获取参数，计算总MB数 */
    unsigned long long totalBlocks = diskInfo.f_bsize;
    unsigned long long totalSize = totalBlocks * diskInfo.f_blocks;
    size_t mbTotalsize = totalSize>>20;
    info->totalMB = mbTotalsize;
    
//    printf(">>>>>>>>> %-15s %ld\t%ld\t\n",
//                info->fs_mnt_dir,
//                diskInfo.f_blocks,      /* total data blocks in file system */
//                diskInfo.f_bfree        /* free blocks in fs */
//            );
    /* 检测参数有效性 */
    if(mbTotalsize <= 0) return -1;

    /* 计算参数 */
    unsigned long long freeDisk = diskInfo.f_bfree*totalBlocks;
    size_t mbFreedisk = freeDisk>>20;
    info->freeMB = mbFreedisk;

    /* 检测参数有效性 */
    if(mbFreedisk <= 0) return -1;

    /* 计算使用率 */
    double occupy = (mbTotalsize-mbFreedisk)*1.0/mbTotalsize;
    int occupy_integer = (int) (occupy*100.0);
    int occupy_decimal = (int) (occupy*100000.0) - occupy_integer*100;

    if(occupy_integer < 0) return -1;
    if(occupy_decimal < 0) return -1;

    info->occupy.integer = occupy_integer;
    info->occupy.decimal = occupy_decimal;

    return 0;
}

/* 从系统中获取 */
static void fs_list_alloc_nonlock()
{
    struct mntent *ent, mntbuf;
    FILE *aFile;
    aFile = setmntent("/proc/mounts", "r"); 
    assert(aFile != NULL);
    
    char buf[512] = {0};
    
    while (NULL != (ent = getmntent_r(aFile, &mntbuf, buf, 512))) {
        struct crypto_fs_system *fs = malloc(sizeof(struct crypto_fs_system));
        assert(fs != NULL);
        memset(fs, 0, sizeof(struct crypto_fs_system));

        /* 这里需要拷贝新实例 */
        strcpy(fs->occupy_info.fs_name, ent->mnt_fsname);
        strcpy(fs->occupy_info.fs_type, ent->mnt_type);
        strcpy(fs->occupy_info.fs_mnt_dir, ent->mnt_dir);

        /* 计算使用率 */
        int ret = calculate_fs_occupy_nonlock(&fs->occupy_info);
        if(ret == 0) {
            list_add_tail(&fs->list, &fs_list);
        } else {
            free(fs);
        }
    }
    
    endmntent(aFile);
}

/* 释放链表 */
static void fs_list_free_nonlock()
{
    struct crypto_fs_system *ifs = NULL, *next_fs = NULL;

    list_for_each_entry_safe(ifs, next_fs, &fs_list, list) {
        if(ifs) {
            list_del(&ifs->list);
            free(ifs);
        }
    }
}
/* 初始化/创建/填充链表 */
static void fs_list_init_safe()
{
    volatile static int load_already = 0;

    /* 线程锁 */
    pthread_rwlock_wrlock(&fs_rwlock);
    
    load_already += 1;  
    if(load_already == 1) {
        fs_list_alloc_nonlock();
    }
    if(load_already == 3) {
        load_already = 1;
        fs_list_free_nonlock();
        fs_list_alloc_nonlock();
    }
    pthread_rwlock_unlock(&fs_rwlock);
}

/* 轮询链表 */
static void for_each_fs_nonlock(fs_info_ops_fn display)
{   
    if(list_empty_careful(&fs_list)) {
        return ;
    }
    
    struct crypto_fs_system *ifs = NULL, *next_fs = NULL;
    list_for_each_entry_safe(ifs, next_fs, &fs_list, list) {
        if(ifs) {
            struct fs_occupy_info *info = &ifs->occupy_info;
            if(display) display(info);
        }
    }
}

/* 轮询链表，线程安全 */
static void for_each_fs_safe(fs_info_ops_fn display)
{
    pthread_rwlock_rdlock(&fs_rwlock);
    for_each_fs_nonlock(display);
    pthread_rwlock_unlock(&fs_rwlock);
}

/** 
 *  __fs_storage_occupy - 查询有效文件系统使用率
 *      
 *   该接口会轮询调用 display 有效文件系统个数次，每次将 struct fs_occupy_info 结构
 *  传递给 fs_info_ops_fn 回调函数。
 */
static void __fs_storage_occupy(fs_info_ops_fn display)
{
    if(!display) return ;
    
    fs_list_init_safe();
    for_each_fs_safe(display);
}
weak_alias(__fs_storage_occupy, fs_storage_occupy);



