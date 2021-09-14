/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
int main()
{
    /* 加密 */
    BIO *bc=NULL,*b=NULL;
    const EVP_CIPHER *c=EVP_des_ecb();
    int len,i;
    char tmp[1024];
    unsigned char key[8],iv[8];
    for(i=0;i<8;i++)
    {
        memset(&key[i],i+1,1);
        memset(&iv[i],i+1,1);
    }
    
    bc=BIO_new(BIO_f_cipher());
    BIO_set_cipher(bc,c,key,iv,1);/* 加密 *///BIO_set_cipher(bc,c,key,iv,1);设置加密BI
    
    b= BIO_new(BIO_s_null());
    b=BIO_push(bc,b);
    len=BIO_write(b,"openssl",7);
    len=BIO_read(b,tmp,1024);//加/解密结果通过BIO_read 获取。

    printf("tmp: %s\n", tmp);
    
    BIO_free(b);
    
    /* 解密 */
    BIO *bdec=NULL,*bd=NULL;
    const EVP_CIPHER *cd=EVP_des_ecb();

    bdec=BIO_new(BIO_f_cipher());
    BIO_set_cipher(bdec,cd,key,iv,0);/* 解密 *///BIO_set_cipher(bdec,cd,key,iv,0);设置解密BIO。
    
    bd= BIO_new(BIO_s_null());
    bd=BIO_push(bdec,bd);

    len=BIO_write(bdec,tmp,len);
    len=BIO_read(bdec,tmp,1024);//加/解密结果通过BIO_read 获取。

    printf("tmp: %s\n", tmp);
    
    BIO_free(bdec);
    return 0;
}
//说明：本示例采用cipher BIO 对字符串"openssl"进行加密和解密,本示例编译需要用c++
//编译器;
//关键说明:
//BIO_set_cipher(bc,c,key,iv,1);设置加密BI。
//BIO_set_cipher(bdec,cd,key,iv,0);设置解密BIO。
//其中 key 为对称密钥,iv 为初始化向量。
//加/解密结果通过BIO_read 获取。

