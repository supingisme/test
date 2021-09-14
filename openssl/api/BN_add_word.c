/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/bn.h>
int main()
{
    int ret;
    BIGNUM *a;
    BN_ULONG w;
    a=BN_new();
    BN_one(a);
    w=2685550010;
    ret=BN_add_word(a,w);//给大数a加上w，如果成功，返回1。
    if(ret!=1)
    {
        printf("a+=w err!\n");
        BN_free(a);
        return -1;
    }
    BN_free(a);
    return 0;
}

