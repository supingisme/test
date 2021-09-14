
//本例用于生成 data 类型的pkcs7 消息
//。
/* pkcs7 data */
#include <string.h>
#include <openssl/pkcs7.h>
#include <openssl/objects.h>
int main()
{
    PKCS7 *p7;
    int len;
    char buf[1000],*der,*p;
    FILE *fp;
    p7=PKCS7_new();
    PKCS7_set_type(p7,NID_pkcs7_data);
    strcpy(buf,"pkcs7 data !\n");
    len=strlen(buf);
    ASN1_OCTET_STRING_set(p7->d.data,(const unsigned char *)buf,len);
    len=i2d_PKCS7(p7,NULL);

    der=(char *)malloc(len);
    p=der;
    len=i2d_PKCS7(p7,(unsigned char **)&p);

    fp=fopen("p7_data.cer","wb");
    fwrite(der,1,len,fp);
    fclose(fp);
    
    PKCS7_free(p7);
    free(der);
    return 0;
}

//# more p7_data.cer 
//pkcs7 data !

