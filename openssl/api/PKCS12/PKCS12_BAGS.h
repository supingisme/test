//PKCS12_BAGS
typedef struct pkcs12_bag_st
{
    ASN1_OBJECT *type;
    union
    {
        ASN1_OCTET_STRING *x509cert;
        ASN1_OCTET_STRING *x509crl;
        ASN1_OCTET_STRING *octet;
        ASN1_IA5STRING *sdsicert;
        ASN1_TYPE *other;
    }value;
} PKCS12_BAGS;

//该结构用于存放各种实体对象。
