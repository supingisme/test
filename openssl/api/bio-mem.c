/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <stdio.h>
#include <openssl/bio.h>

int main()
{
    BIO *b=NULL;
    int len=0;
    char *out=NULL;
    b=BIO_new(BIO_s_mem());
    len=BIO_write(b,"openssl",4);
    len=BIO_printf(b,"%s","zcp");
    len=BIO_ctrl_pending(b);
    out=(char *)OPENSSL_malloc(len);
    len=BIO_read(b,out,len);

    printf("out : %s\n", (char*)out);
    
    OPENSSL_free(out);
    BIO_free(b);
    return 0;
}
//说明：
//b=BIO_new(BIO_s_mem());生成一个mem 类型的BIO。
//len=BIO_write(b,"openssl",7);将字符串"openssl"写入bio。
//len=BIO_printf(b,"bio test",8);将字符串"bio test"写入bio。
//len=BIO_ctrl_pending(b);得到缓冲区中待读取大小。
//len=BIO_read(b,out,50);将bio 中的内容写入out 缓冲区。
