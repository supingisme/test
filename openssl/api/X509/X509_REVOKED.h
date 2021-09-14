//Openssl 中的crl 数据结构定义在crypto/x509/x509.h 中。
//1） X509_REVOKED
typedef struct X509_revoked_st
{
    ASN1_INTEGER *serialNumber;
    ASN1_TIME *revocationDate;
    STACK_OF(X509_EXTENSION) *extensions;
    int sequence;
} X509_REVOKED;
//本结构用于存放一个被撤销证书的信息，各项意义如下：
//serialNumber：被撤销证书的序列号；
//revocationDate：撤销时间；
//extensions：扩展项，可选；
//sequence：顺序号，用于排序，表示当前被撤销证书信息在crl 中的顺序。
//上述三个结构的 DER 编解码通过宏在crypto/asn1/x_crl.c 中实现，包括new、free、i2d 和d2i
//函数。

