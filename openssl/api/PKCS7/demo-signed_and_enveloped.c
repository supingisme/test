//signed_and_enveloped
#include <openssl/pkcs7.h>
#include <openssl/objects.h>
int main()
{
    PKCS7 *p7;
    int len;
    char *der,*p;
    FILE *fp;
    p7=PKCS7_new();
    PKCS7_set_type(p7,NID_pkcs7_signedAndEnveloped);
    len=i2d_PKCS7(p7,NULL);
    der=(char *)malloc(len);
    p=der;
    len=i2d_PKCS7(p7,(unsigned char **)&p);
    fp=fopen("p7_signAndEnv.cer","wb");
    fwrite(der,1,len,fp);
    fclose(fp);
    PKCS7_free(p7);
    free(der);
    return 0;
}
//本例用于生成 signedAndEnveloped 类型的pkcs7 消息,不过省略了数据结构的填充。

