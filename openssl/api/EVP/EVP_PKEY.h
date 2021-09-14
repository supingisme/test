//EVP_PKEY
struct evp_pkey_st
{
    int references;
    union
    {
        char *ptr;
#ifndef OPENSSL_NO_RSA
        struct rsa_st *rsa; /* RSA */
#endif
#ifndef OPENSSL_NO_DSA
        struct dsa_st *dsa; /* DSA */
#endif
#ifndef OPENSSL_NO_DH
        struct dh_st *dh; /* DH */
#endif
#ifndef OPENSSL_NO_EC
        struct ec_key_st *ec; /* ECC */
#endif
    } pkey;
    STACK_OF(X509_ATTRIBUTE) *attributes; /* [ 0 ] */
};
//该结构用来存放非对称密钥信息，可以是RSA、DSA、DH 或ECC 密钥。其中，ptr 用
//来存放密钥结构地址，attributes 堆栈用来存放密钥属性。


