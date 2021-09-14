//检查证书用途的函数为 int X509_check_purpose(X509 *x, int id, int ca)，该函数用于检查
//证书的用途。x 为待检查待证书，id 为证书用途NID，ca 表明x 是否是ca 证书。
//基本用法如下：
#include <openssl/x509.h>
#include <openssl/x509v3.h>
int main()
{
    X509 *x=0;
    int id,len,ret;
    FILE *fp;
    unsigned char buf[5000],*p;
    fp=fopen("der.cer","rb");
    len=fread(buf,1,5000,fp);
    fclose(fp);
    p=buf;
    d2i_X509(&x,&p,len);
    id=X509_PURPOSE_OCSP_HELPER;
    ret=X509_check_purpose(x,id,0);
    if(ret==1)
    {
        printf("purpose check ok!\n");
    }
    else
    {
        printf("purpose check failed!\n");
    }
    X509_free(x);
    return 0;
}
//如果输入的id 小于0，不做任何检查，只是证书的各个扩展项信息写入到将X509 数据
//结构中。
