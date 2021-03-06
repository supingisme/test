/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/bn.h>
#include <string.h>
#include <openssl/bio.h>
int main()
{
    BIGNUM *a,*b,*sub;
    BIO *out;
    char c[20],d[20];
    int ret;
    a=BN_new();
    strcpy(c,"100");
    ret=BN_hex2bn(&a,c);
    b=BN_new();
    strcpy(d,"32");
    ret=BN_hex2bn(&b,d);
    out=BIO_new(BIO_s_file());
    ret=BIO_set_fp(out,stdout,BIO_NOCLOSE);
    sub=BN_new();
    ret=BN_sub(sub,a,b);
    if(ret!=1)
    {
        printf("err.\n");
        return -1;
    }
    BIO_puts(out,"bn 0x100 - 0x32 = 0x");
    BN_print(out,sub);
    BIO_puts(out,"\n");
    BN_free(a);
    BN_free(b);
    BN_free(sub);
    BIO_free(out);
    return 0;
}

