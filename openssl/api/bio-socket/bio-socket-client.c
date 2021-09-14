/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/bio.h>

int main()
{
    BIO *cbio, *out;
    int len;
    char tmpbuf[1024];
    cbio = BIO_new_connect("localhost:http");
    out = BIO_new_fp(stdout, BIO_NOCLOSE);
    if(BIO_do_connect(cbio) <= 0)
    {
        fprintf(stderr, "Error connecting to server\n");
    }
    BIO_printf(out, "###############\n");
    BIO_puts(cbio, "GET / HTTP/1.0\n\n");
    for(;;)
    {
        len = BIO_read(cbio, tmpbuf, 1024);
        if(len <= 0) break;
        BIO_write(out, tmpbuf, len);
    }
    BIO_free(cbio);
    BIO_free(out);
    return 0;
}

//说明：本示例用来获取本机的web 服务信息。
//cbio = BIO_new_connect("localhost:http");用来生成建立连接到本地web 服务的BIO。
//out = BIO_new_fp(stdout, BIO_NOCLOSE);生成一个输出到屏幕的BIO。
//BIO_puts(cbio, "GET / HTTP/1.0\n\n");通过BIO 发送数据。
//len = BIO_read(cbio, tmpbuf, 1024);将web 服务响应的数据写入缓存,此函数循环调用
//直到无数据。
//BIO_write(out, tmpbuf, len);通过BIO 打印收到的数据

