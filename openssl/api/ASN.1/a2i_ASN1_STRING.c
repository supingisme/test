//int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)
//将ASCII 码转换为ASN1_STRING，示例：
#include <openssl/asn1.h>
int main()
{
    BIO *bp;
    ASN1_STRING *str;
    unsigned char buf[50];
    int size,len;
    bp=BIO_new(BIO_s_mem());
    len=BIO_write(bp,"B2E2CAD4",8);
    size=50;
    str=ASN1_STRING_new();
    a2i_ASN1_STRING(bp,str,buf,size);

    printf("buf = %s, str = %s\n", buf, str->data);
    
    BIO_free(bp);
    ASN1_STRING_free(str);
    return 0;
}
//转换后str->data 的前四个字节即变成"测试"。
