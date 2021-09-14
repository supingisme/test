//该结构用来存放摘要或者签名值，定义在crypto/x509/x509.h 中，如下：
typedef struct X509_sig_st
{
    X509_ALGOR *algor;
    ASN1_OCTET_STRING *digest;
} X509_SIG;
//其中，algor 为算法，digest 用于存放摘要或者签名值。对数据进行签名时，要先对数据
//摘要，摘要的结果要通过本结构进行DER 编码，然后才能用私钥进行计算，此时digest
//中存放的就是摘要值。
//本结构的 DER 编码通过ASN1 宏在crypto/asn1/x_sig.c 中实现，包括new、free、i2d 和
//d2i 函数。
