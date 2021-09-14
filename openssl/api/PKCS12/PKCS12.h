//2）PKCS12
typedef struct
{
    ASN1_INTEGER *version;
    PKCS12_MAC_DATA *mac;
    PKCS7 *authsafes;
} PKCS12;
//pkcs12 数据结构，version 为版本，mac 用于存放MAC 信息以及对称密钥相关的信息
//authsafes 为pkcs7 结构，用于存放的证书、crl 以及私钥等各种信息。
