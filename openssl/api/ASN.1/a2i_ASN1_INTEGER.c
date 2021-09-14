//int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)
//将bp 中的ASC 码转换为ASN1_INTEGER,buf 存放BIO 中的ASC 码。示例如下：
#include <openssl/asn1.h>
int main()
{
    BIO *bp;
    ASN1_INTEGER *i;
    unsigned char buf[50];
    int size,len;

    /**
     *  
     */
    bp=BIO_new(BIO_s_mem());
    len=BIO_write(bp,"0FAB08BBDDEECC",14);
    size=50;
    i=ASN1_INTEGER_new();
    a2i_ASN1_INTEGER(bp,i,buf,size);

    printf("i = %d, buf = %s\n", i, buf);
    
    BIO_free(bp);
    ASN1_INTEGER_free(i);
    return 0;
}
