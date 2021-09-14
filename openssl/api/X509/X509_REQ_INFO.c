//根据 PKCS#10，openssl 的X509 数字证书申请结构定义在crypto/x509.h 中，如下
//所示，主要由两部分组成：
//1）X509_REQ_INFO
typedef struct X509_req_info_st
{
    ASN1_ENCODING enc;
    ASN1_INTEGER *version;
    X509_NAME *subject;
    X509_PUBKEY *pubkey;
    STACK_OF(X509_ATTRIBUTE) *attributes;
} X509_REQ_INFO;

//该结构为证书申请信息主体，其中version 表示版本，subject 为申请者信息，pubkey
//为申请者公钥信息，attributes 为可选的属性信息。该结构的DER 编码接口在
//crytpo/asn1/x_req.c 中由宏实现，实现了new、free、i2d 和d2i 函数。
