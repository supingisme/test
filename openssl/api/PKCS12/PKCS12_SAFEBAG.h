//4）PKCS12_SAFEBAG
typedef struct
{
    ASN1_OBJECT *type;
    union
    {
        struct pkcs12_bag_st *bag;
        struct pkcs8_priv_key_info_st *keybag;
        X509_SIG *shkeybag;
        STACK_OF(PKCS12_SAFEBAG) *safes;
        ASN1_TYPE *other;
    }value;
    STACK_OF(X509_ATTRIBUTE) *attrib;
} PKCS12_SAFEBAG;

//该结构用于存放各种证书、crl 和私钥数据。
//上述两种结构与 pkcs7 数据结构的相互转化可参考p12_add.c。在使用中，用户根据证
//书、私钥以及crl 等信息来构造PKCS12_SAFEBAG 数据结构，然后将这些结构转化为
//pkcs12 中的pkcs7 结构。
