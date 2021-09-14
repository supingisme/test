//解码证书请求文件

#include <string.h>
#include <openssl/x509.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#define debug() printf("%s:%d\n", __func__, __LINE__);

int main()
{
    BIO *in;
    X509_REQ *req=NULL,**req2=NULL;
    FILE *fp;
    unsigned char buf[1024],*p;
    int len;
    
    in=BIO_new_file("certreq.txt","r");

    req=PEM_read_bio_X509_REQ(in,NULL,NULL,NULL);
    if(req==NULL)
    {
        printf("DER解码错误!\n");
    }
    else
    {
        printf("DER解码成功!\n");
    }

    fp=fopen("certreq2.txt","r");
    len=fread(buf,1,1024,fp);
    debug();
    p=buf;
    printf("buf{%d}: %s\n", len, buf);
    debug();
    
    req2=(X509_REQ **)malloc(sizeof(X509_REQ *));
    *req2=(X509_REQ *)malloc(sizeof(X509_REQ ));
    
    printf("req2 %p; buf %p\n", req2, buf);
    
    debug();
#if 0
    d2i_X509_REQ(req2,(const unsigned char**)&p,len); //??????????????????????????????
                                                      //将证书请求从文件中读入并转化成X509_REQ内部结构。
#else    
    d2i_X509_REQ_fp(fp,req2);
#endif         
    fclose(fp);

    debug();
    if(*req2==NULL)
    {
        printf("DER解码错误!\n");
    }
    else
    {
        printf("DER解码成功!\n");
    }
    debug();
    
    X509_REQ_free(*req2);
    
    debug();
    free(req2);
    return 0;
}
//其中 certreq.txt 是PEM 格式的证书请求文件，certreq2.txt 为DER 编码格式。

