//本结构用于存放各种扩展项信息。
//1）结构定义
//数字证书扩展项，定义在 crypto/x509/x509.h 中，如下：
typedef struct X509_extension_st
{
    ASN1_OBJECT *object;
    ASN1_BOOLEAN critical;
    ASN1_OCTET_STRING *value;
} X509_EXTENSION;
//其中 object 指明是哪种扩展项；critical 指明是否为关键扩展项，为0xFF 时为关键扩展
//项，-1 为非关键扩展项；value 为DER 编码的具体扩展项的值。该结构的DER 编解码在
//crypto/asn1/x_exten.c 中由宏实现，包括new、free、i2d、d2i 和dup 函数。扩展项的DER 编
//    解码可直接采用i2d 和d2i 来完成，也可用采用openssl 提供的其他函数。


