//26.1 X509 数字证书
//        数字证书是将用户(或其他实体)身份与公钥绑定的信息载体。一个合法的数字证书
//        不仅要符合X509 格式规范，还必须有CA 的签名。用户不仅有自己的数字证书，还必
//        须有对应的私钥。
//        X509v3 数字证书主要包含的内容有[1]：证书版本、证书序列号、签名算法、颁发
//        者信息、有效时间、持有者信息、公钥信息、颁发者ID、持有者ID 和扩展项。
//26.2 opessl 实现
//        openssl 实现了标准的x509v3 数字证书，其源码在crypto/x509 和crypto/x509v3 中。
//        其中x509 目录实现了数字证书以及证书申请相关的各种函数，包括了X509 和
//        X509_REQ 结构的设置、读取、打印和比较；数字证书的验证、摘要；各种公钥的导入
//        导出等功能。x509v3 目录主要实现了数字证书扩展项相关的函数。
//26.3 X509 数据结构
//        该结构定义在 crypto/x509.h 中，如下：

typedef struct x509_cinf_st
{
    ASN1_INTEGER *version; /* 版本 */
    ASN1_INTEGER *serialNumber; /* 序列号 */
    X509_ALGOR *signature; /* 签名算法 */
    X509_NAME *issuer; /* 颁发者 */
    X509_VAL *validity; /* 有效时间 */
    X509_NAME *subject; /* 持有者 */
    X509_PUBKEY *key; /* 公钥 */
    ASN1_BIT_STRING *issuerUID; /* 颁发者唯一标识 */
    ASN1_BIT_STRING *subjectUID; /* 持有者唯一标识 */
    STACK_OF(X509_EXTENSION) *extensions; /* 扩展项 */
} X509_CINF;

//本结构是数字证书的信息主体；
//上述两个结构的 DER 编解码接口由宏在crypto/asn1/x_x509.c 中实现，包括各自的new、free、i2d 和d2i 函数。

