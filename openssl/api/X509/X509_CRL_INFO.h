//2）X509_CRL_INFO
typedef struct X509_crl_info_st
{
    ASN1_INTEGER *version;
    X509_ALGOR *sig_alg;
    X509_NAME *issuer;
    ASN1_TIME *lastUpdate;
    ASN1_TIME *nextUpdate;
    STACK_OF(X509_REVOKED) *revoked;
    STACK_OF(X509_EXTENSION) *extensions;
    ASN1_ENCODING enc;
} X509_CRL_INFO;
//crl 信息主体，各项意义如下：
//version：crl 版本；
//sig_alg：crl 签名法；
//issuer：签发者信息；
//lastUpdate：上次更新时间；
//nextUpdate：下次更新时间；
//revoked：被撤销证书信息；
//extensions：扩展项，可选。
//上述三个结构的 DER 编解码通过宏在crypto/asn1/x_crl.c 中实现，包括new、free、i2d 和d2i
//函数。

