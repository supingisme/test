//X509_REQ
typedef struct X509_req_st
{
    X509_REQ_INFO *req_info;
    X509_ALGOR *sig_alg;
    ASN1_BIT_STRING *signature;
    int references;
} X509_REQ;
//该结构为证书申请信息，req_info 为信息主体，sig_alg 为签名算法，signature 为签
//名值(申请者对req_info 的DER 编码值用自己的私钥签名)。该结构的DER 编码接口在
//crytpo/asn1/x_req.c 中由宏实现，实现了new、free、i2d 和d2i 函数。
