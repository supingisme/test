//该数据结构用来表示有效时间，定义在crypto/x509/x509.h 中，如下：
typedef struct X509_val_st
{
    ASN1_TIME *notBefore;
    ASN1_TIME *notAfter;
} X509_VAL;
//包含两项：
//notBefore：生效日期；
//notAfter：失效日期；
//该结构的 DER 编解码通过宏在crypto/asn1/x_val.c 中。包括是个函数：new、free、i2d
//和d2i。
