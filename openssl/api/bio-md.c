/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/bio.h>
#include <openssl/evp.h>

int main()
{
    BIO *bmd=NULL,*b=NULL;
    const EVP_MD *md=EVP_md5();
    int len;
    char tmp[1024];
    bmd=BIO_new(BIO_f_md());
    BIO_set_md(bmd,md);
    b= BIO_new(BIO_s_null());
    b=BIO_push(bmd,b);
    len=BIO_write(b,"openssl",7);
    len=BIO_gets(b,tmp,1024);
    BIO_free(b);
    return 0;
}
//说明：本示例用 md BIO 对字符串"opessl"进行md5 摘要。
//bmd=BIO_new(BIO_f_md());生成一个md BIO。
//BIO_set_md(bmd,md);设置md BIO 为md5 BIO。
//b= BIO_new(BIO_s_null());生成一个null BIO。
//b=BIO_push(bmd,b);构造BIO 链,md5 BIO 在顶部。
//len=BIO_write(b,"openssl",7);将字符串送入BIO 做摘要。
//len=BIO_gets(b,tmp,1024);将摘要结果写入tmp 缓冲区。

// MD类型BIO对通过它的任何数据都进行摘要操作（digest)，事实上，该类型BIO封装
//
//了EVP_DigestInit、EVP_DigestUpdate和EVP_DigestFinal三个函数的功能和行为。该类
//
//型BIO是完全对称的，也就是说，不管是读数据（BIO_read)还是写数据（BIO_write），
//
//都进行相同的摘要操作。
//
//    BIO_gets函数执行的时候，如果给定的size参数足够大，可以完成摘要（digest）
//
//计算，那么就会返回摘要值。BIO_puts函数是不支持的，如果需要支持该函数，可以在
//
//前面附加一个buffer类型的BIO。
//
//    BIO_reset函数重新初始化一个摘要类型的BIO，事实上，它是简单重新调用了EVP_
//
//DigestInit函数进行初始化。
//
//    注意，在从一个摘要BIO里面读取完摘要信息之后，在重新使用该BIO之前，必须调
//
//用BIO_reset或BIO_set_md重新初始化该BIO才行。



//简单接口
//
//简单接口使用一个函数调用就可以完成消息摘要计算，这些接口包括MD2,MD4,MD5,MDC2,RIPEMD,SHA1，函数声明都一样。
//
//以MD5为例，函数声明为：
//
//unsigned char *MD5(const unsigned char *d, unsigned long n, unsigned char *md);
//
//其中 d 指向要计算消息摘要的数据，n 为数据长度，md 指向保存消息摘要的缓冲区。
//如果 md 不为 NULL，那么它的长度必须能够容纳计算出来的消息摘要。
//对MD5，这个长度至少是 MD5_DIGEST_LENGTH。
//如果 md 为 NULL，那么计算出来的消息摘要保存在一个静态数组里，函数返回指向这个数组的指针。

