//X509_CRL
struct X509_crl_st
{
    X509_CRL_INFO *crl;
    X509_ALGOR *sig_alg;
    ASN1_BIT_STRING *signature;
    int references;
} ;
//完整 crl 数据结构，各项意义如下：
//crl：crl 信息主体；
//sig_alg：签名算法，与X509_CRL_INFO 中的一致；
//signature：签名值；
//references：引用。
//上述三个结构的 DER 编解码通过宏在crypto/asn1/x_crl.c 中实现，包括new、free、i2d 和d2i
//函数。
