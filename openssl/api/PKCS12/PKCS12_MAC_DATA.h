//数据结构定义在 crypto/pkcs12/pkcs12.h 中，如下所示：
//1）PKCS12_MAC_DATA
typedef struct
{
    X509_SIG *dinfo;
    ASN1_OCTET_STRING *salt;
    ASN1_INTEGER *iter;
} PKCS12_MAC_DATA;
//该结构用于存放pkcs12 中的MAC 信息，防止他人篡改。xinfo 用于存放MAC 值和摘
//要算法，salt 和iter 用于根据口令来生成对称密钥(pbe)。

