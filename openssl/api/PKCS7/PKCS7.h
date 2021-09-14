//Openssl 的pkcs7 实现在crypto/pkcs7 目录下。pkcs7 的各种消息数据结构和函数在
//crypto/pkcs7/pkcs7.h 中定义，主要数据结构如下：

//加密消息语法（pkcs7），是各种消息存放的格式标准。这些消息包括：数据、签名数据、
//数字信封、签名数字信封、摘要数据和加密数据。


typedef struct pkcs7_st
{
    /* 其他项 */
    ASN1_OBJECT *type;
    union
    {
        char *ptr;
        /* NID_pkcs7_data */
        ASN1_OCTET_STRING *data;
        /* NID_pkcs7_signed */
        PKCS7_SIGNED *sign;
        /* NID_pkcs7_enveloped */
        PKCS7_ENVELOPE *enveloped;
        /* NID_pkcs7_signedAndEnveloped */
        PKCS7_SIGN_ENVELOPE *signed_and_enveloped;
        /* NID_pkcs7_digest */
        PKCS7_DIGEST *digest;
        /* NID_pkcs7_encrypted */
        PKCS7_ENCRYPT *encrypted;
        /* Anything else */
        ASN1_TYPE *other;
    } d;
} PKCS7;

//其中type 用于表示是何种类型的pkcs7 消息， data 、sign 、enveloped 、
//signed_and_enveloped、digest 和ncrypted 对于了6 种不同的具体消息。oher 用于存放任
//意数据类型（也可以是pkcs7 结构），所以，本结构可以是一个嵌套的数据结构。
//pkcs7 各种类型数据结构的DER 编解码通过宏在crypto/pkcs7/pk7_asn1.c 中实现，
//包括new、free、i2d 和d2i 函数。
