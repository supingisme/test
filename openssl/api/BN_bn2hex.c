/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/bn.h>
#include <openssl/crypto.h>
int main()
{
    BIGNUM *ret1=NULL;
    char *p=NULL;
    int len=0;
    ret1=BN_bin2bn("242424ab",8, NULL);
    p=BN_bn2hex(ret1);
    printf("%s\n",p);
    BN_free(ret1);
    OPENSSL_free(p);
    getchar();
    return 0;
}
