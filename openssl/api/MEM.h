/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */

typedef struct mem_st
{
    void *addr;
    int num;
    const char *file;
    int line;
    unsigned long thread;
    unsigned long order;
    time_t time;
    APP_INFO *app_info;
} MEM;
//各项意义：
//addr：分配内存的地址。
//num：分配内存的大小。
//file：分配内存的文件。
//line：分配内存的行号。
//thread：分配内存的线程ID。
//order：第几次内存分配。
//time：内存分配时间。
//app_info:用于存放用户应用信息，为一个链表，里面存放了文件、行号以及线程ID
//等信息。
//references：被引用次数。

