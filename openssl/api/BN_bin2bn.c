/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
//将内存中的数据转换为大数，为内存地址，len 为数据长度，ret 为返回值。
//示例：
#include <stdio.h>
#include <openssl/bio.h>
#include <openssl/bn.h>

int main()
{
    BIGNUM *ret1,*ret2;
    ret1=BN_new();
    ret1=BN_bin2bn("242424ab",8, ret1);
    ret2=BN_bin2bn("242424ab",8,NULL);

    BIO * fp=BIO_new(BIO_s_file());
    BIO_set_fp(fp,stdout,BIO_NOCLOSE);
    
    BN_print(fp, ret1);
    
    BN_free(ret1);
    BN_free(ret2);
    return 0;
}
//注意：输入参数“242424ab”是asc码，对应的大数值为16进制的
