//摘要函数用于将任意数据通过计算获取唯一对应值，而这个值的长度比较短。它是一种
//多对一的关系。理论上，这个短的值就对应于原来的数据。这个过程是不可逆的，即不能通
//过摘要值来计算原始数据。摘要在信息安全中有非常重要的作用。很多网络应用都通过摘要
//计算来存放口令。摘要是安全协议中不可或却的要素，特别是身份认证与签名。用户需要对
//数据进行签名时，不可能对大的数据进行运算，这样会严重影响性能。如果只对摘要结果进
//行计算，则会提供运算速度。常用摘要算法有：sha、sha1、sha256 以及md5 等。其他还有
//md4、md2、mdc2 以及ripemd160 等。
//
//所有的摘要算法都有如下几个函数：
//1) XXX_Init
//XXX 为具体的摘要算法名称，该函数初始化上下问，用于多数据摘要。
//2) XXX_Update
//XXX 为具体的摘要算法名称，进行摘要计算，该函数可运行多次，对多个数
//据摘要。
//3) XXX_Final
//XXX 为具体的摘要算法名称，进行摘要计算，该函数与1)和2）一起用。
//4) XXX
//对一个数据进行摘要。该函数由上述1）2）和3）实现，只是XXX_Update
//只调用一次。对应源码为XXX_one.c。
//这些函数的测试程序，可参考各个目录下对应的测试程序源码。
//


#include <stdio.h>
#include <string.h>
#include <openssl/md2.h>
#include <openssl/md4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
int main()
{
    unsigned char in[]="3dsferyewyrtetegvbzVEgarhaggavxcv";
    unsigned char out[20];
    size_t n;
    int i;
    n=strlen((const char*)in);
#ifdef OPENSSL_NO_MDC2
    printf("默认openssl 安装配置无MDC2\n");
#else
    MDC2(in,n,out);
    printf("MDC2 digest result :\n");
    for(i=0;i<16;i++)
        printf("%x ",out[i]);
#endif
    RIPEMD160(in,n,out);
    printf("RIPEMD160 digest result :\n");
    for(i=0;i<20;i++)
        printf("%x ",out[i]);
    MD2(in,n,out);
    printf("MD2 digest result :\n");
    for(i=0;i<16;i++)
        printf("%x ",out[i]);
    MD4(in,n,out);
    printf("\n\nMD4 digest result :\n");
    for(i=0;i<16;i++)
        printf("%x ",out[i]);
    MD5(in,n,out);
    printf("\n\nMD5 digest result :\n");
    for(i=0;i<16;i++)
        printf("%x ",out[i]);
    SHA(in,n,out);
    printf("\n\nSHA digest result :\n");
    for(i=0;i<20;i++)
        printf("%x ",out[i]);
    SHA1(in,n,out);
    printf("\n\nSHA1 digest result :\n");
    for(i=0;i<20;i++)
        printf("%x ",out[i]);
    SHA256(in,n,out);
    printf("\n\nSHA256 digest result :\n");
    for(i=0;i<32;i++)
        printf("%x ",out[i]);
    SHA512(in,n,out);
    printf("\n\nSHA512 digest result :\n");
    for(i=0;i<64;i++)
        printf("%x ",out[i]);
    printf("\n");
    return 0;
}
//以上示例中演示了各种摘要计算函数的使用方法。对输入数据 in 进行摘要计算，
//结果存放在out 缓冲区中。其中：
//mdc2、md4 和md5 摘要结果为16 字节，128 比特；
//ripemd160、sha 和sha1 摘要结果为20 字节，160bit；
//sha256摘要结果为32 字节，256bit；
//sha512摘要结果为64 字节，512bit。
//# ./a.out 
//默认openssl 安装配置无MDC2
//RIPEMD160 digest result :
//4b 4e 20 7a 5a eb af b0 a8 73 b2 1e b8 94 8d 60 c7 21 a0 c5 MD2 digest result :
//14 64 1e ed d c0 1e 74 3 d6 3e 38 c2 76 9d fc 
//
//MD4 digest result :
//b9 8e 2a 21 5 23 ac e3 3f bf a6 fa db f9 a3 ec 
//
//MD5 digest result :
//8 d2 5 b0 7a 1e 24 65 73 a1 87 49 49 a0 bc 65 
//
//SHA digest result :
//d4 2a 1d c4 c0 98 26 74 bc e 11 21 57 fd 47 8b b7 d 3d 4f 
//
//SHA1 digest result :
//f5 6e 4c a3 f3 58 27 ba 96 c 7b dc ab 24 c0 c5 d6 ff e1 d1 
//
//SHA256 digest result :
//a 8e 4e e9 32 20 da 8 3 1b 49 df 6f 5f d2 13 27 c6 a6 2a e6 ad 8 99 f a2 70 1f 96 62 c f9 
//
//SHA512 digest result :
//d df cc b0 d3 d3 9 17 f ad eb c1 85 73 9e fb c1 83 78 9f 19 a5 7f 8 df c3 80 45 a9 bc 78 fa 1d 96 fb 63 a6 bc 9a 23
// 65 9a b3 bf 94 b0 60 db 13 dc 10 3c f9 fd b8 34 5 e9 6c 2a ca fb 7a b6 

