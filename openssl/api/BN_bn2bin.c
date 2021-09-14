/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/bn.h>
int main()
{
    BIGNUM *ret1=NULL;
    char bin[50],*buf=NULL;
    int len;
    ret1=BN_bin2bn("242424ab",8, NULL);
    len=BN_bn2bin(ret1,bin);
    len=BN_num_bytes(ret1);
    buf=malloc(len);
    len=BN_bn2bin(ret1,buf);
    free(buf);
    BN_free(ret1);
    return 0;
}
//本例的缓冲区分配有两种方法：静态分配和动态分配。动态分配时，先调用
//BN_num_bytes 函数获取大数对应的缓冲区的大小。
