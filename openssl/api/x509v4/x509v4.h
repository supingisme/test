//属性证书编码
//对属性证书（x509v4）编码
//以下是采用 Openssl 的asn.1 库对属性证书编/解码的源代码：
/* x509v4.h */
/* valid time */
typedef struct X509V4_VALID_st
{
    ASN1_GENERALIZEDTIME *notBefore;
    ASN1_GENERALIZEDTIME *notAfter;
}X509V4_VALID;
DECLARE_ASN1_FUNCTIONS(X509V4_VALID)
/* issuer */
typedef struct ISSUERSERIAL_st
{
    GENERAL_NAMES *issuer;
    ASN1_INTEGER *subjectSN;
    ASN1_BIT_STRING *issuerUID;
}ISSUERSERIAL;
DECLARE_ASN1_FUNCTIONS(ISSUERSERIAL)
/* objdigest */
typedef struct OBJDIGEST_st
{
    ASN1_ENUMERATED *digestType;
    ASN1_OBJECT *otherType;
    X509_ALGOR *digestAlg;
    ASN1_BIT_STRING *digestBit;
}OBJDIGEST;
DECLARE_ASN1_FUNCTIONS(OBJDIGEST)
/* holder */
typedef struct ACHOLDER_st
{
    ISSUERSERIAL *baseCertificateID;
    GENERAL_NAMES *entityName;
    OBJDIGEST *objDigest;
}ACHOLDER;
DECLARE_ASN1_FUNCTIONS(ACHOLDER)
/* version 2 form */
typedef struct V2FORM_st
{
    GENERAL_NAMES *entityName;
    ISSUERSERIAL *baseCertificateID;
    OBJDIGEST *objDigest;
}V2FORM;
DECLARE_ASN1_FUNCTIONS(V2FORM)
typedef struct ACISSUER_st
{
    int type;
    union
    {
        V2FORM *v2Form;
    }form;
} ACISSUER;
DECLARE_ASN1_FUNCTIONS(ACISSUER)
/* X509V4_CINF */
typedef struct X509V4_CINF_st
{
    ASN1_INTEGER *version;
    ACHOLDER *holder;
    ACISSUER *issuer;
    X509_ALGOR *signature;
    ASN1_INTEGER *serialNumber;
    X509V4_VALID *valid;
    STACK_OF(X509_ATTRIBUTE) *attributes;
    ASN1_BIT_STRING *issuerUID;
    STACK_OF(X509_EXTENSION *extensions;
}X509V4_CINF;
DECLARE_ASN1_FUNCTIONS(X509V4_CINF)
/* x509v4 */
typedef struct X509V4_st
{
    X509V4_CINF *cert_info;
    X509_ALGOR *sig_alg;
    ASN1_BIT_STRING *signature;
}X509V4;
DECLARE_ASN1_FUNCTIONS(X509V4)

