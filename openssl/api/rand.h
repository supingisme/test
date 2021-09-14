/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
struct rand_meth_st
{
    void (*seed)(const void *buf, int num);
    int (*bytes)(unsigned char *buf, int num);
    void (*cleanup)(void);
    void (*add)(const void *buf, int num, double entropy);
    int (*pseudorand)(unsigned char *buf, int num);
    int (*status)(void);
};
//seed：种子函数，为了让openssl 内部维护的随机数据更加无序，可使用本函数。buf
//    为用户输入的随机数地址，num 为其字节数。Openssl 将用户提供的buf 中的随机内容与其
//    内部随机数据进行摘要计算，更新其内部随机数据。本函数无输出；
//bytes：生成随机数，openssl 根据内部维护的随机数状态来生成结果。buf 用于存放生成
//    的随机数。num 为输入参数，用来指明生成随机数的字节长度；
//cleanup：清除函数，本函数将内部维护的随机数据清除；
//add：与seed 类似，也是为了让openssl 内部随机数据更加无序，其中entropy(信息熵)
//    可以看作用户本次加入的随机数的个数。Openssl 默认的随机数熵为32 字节，在rand_lcl.h
//    中由ENTROPY_NEEDED 定义。Openssl 给出随机数之前，用户提供的所有的随机种子数
//    之和必须达到32 字节。在openssl 实现的md_rand 中，即使用户不调用种子函数来直接生
//    成随机数，openssl 也会调用RAND_poll 函数来完成该操作。
//pseudorand：本函数与bytes 类似也是来生成随机数。
//status：查看熵值是否达到预定值，openssl 中为32 字节，如果达到则返回1，否则返回
//    0。在openssl 实现的md_rand 中该函数会调用RAND_poll 函数来使熵值合格。如果本函数
//    返回0，则说明此时用户不应生成随机数，需要调用seed 和add 函数来添加熵值。

