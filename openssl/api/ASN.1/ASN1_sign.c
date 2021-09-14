//int ASN1_sign(i2d_of_void *i2d, X509_ALGOR *algor1, X509_ALGOR *algor2,
//                ASN1_BIT_STRING *signature, char *data, EVP_PKEY *pkey, const EVP_MD *type);
//        对ASN1 数据类型签名。i2d 为ASN1 数据的DER 方法，signature 用于存放签名结
//        果，data 为ASN1 数据指针，pkey 指明签名密钥，type 为摘要算法，algor1 和algor2
//        无用，可全为NULL。签名时，先将ASN1 数据DER 编码，然后摘要，最后签名运算。
//        在 x509.h 中有很多ASN1 数据类型的签名都通过此函数来定义，有X509_sign、
//        X509_REQ_sign、X509_CRL_sign、NETSCAPE_SPKI_sign 等。示例如下：
#include <openssl/asn1.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
int main()
{
    int ret;
    ASN1_INTEGER *a;
    EVP_MD *md;
    EVP_PKEY *pkey;
    char *data;
    ASN1_BIT_STRING *signature=NULL;
    RSA *r;
    int i,bits=1024;
    unsigned long e=RSA_3;
    BIGNUM *bne;
    bne=BN_new();
    ret=BN_set_word(bne,e);
    r=RSA_new();
    ret=RSA_generate_key_ex(r,bits,bne,NULL);
    if(ret!=1)
    {
        printf("RSA_generate_key_ex err!\n");
        return -1;
    }
    pkey=EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pkey,r);
    a=ASN1_INTEGER_new();
    ASN1_INTEGER_set(a,100);
    md=EVP_md5();
    data=(char *)a;
    signature=ASN1_BIT_STRING_new();
    ret=ASN1_sign(i2d_ASN1_INTEGER,NULL,NULL,signature,data,pkey,md);
    printf("signature len : %d\n, signature %s\n",ret,signature->data);
    EVP_PKEY_free(pkey);
    ASN1_INTEGER_free(a);
    free(signature);
    return 0;
}

//本例将ASN1_INTEGER 整数签名。

