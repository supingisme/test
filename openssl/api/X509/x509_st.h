struct x509_st
{
    X509_CINF *cert_info;
    X509_ALGOR *sig_alg;
    ASN1_BIT_STRING *signature;
    int valid;
    int references;
    char *name;
    CRYPTO_EX_DATA ex_data;
    long ex_pathlen;
    long ex_pcpathlen;
    unsigned long ex_flags;
    unsigned long ex_kusage;
    unsigned long ex_xkusage;
    unsigned long ex_nscert;
    ASN1_OCTET_STRING *skid;
    struct AUTHORITY_KEYID_st *akid;
    X509_POLICY_CACHE *policy_cache;
#ifndef OPENSSL_NO_SHA
    unsigned char sha1_hash[SHA_DIGEST_LENGTH];
#endif
    X509_CERT_AUX *aux;
};

//该结构表示了一个完整的数字证书。各项意义如下：
//    cert_info：证书主体信息；
//    sig_alg：签名算法；
//    signature：签名值，存放CA 对该证书采用sig_alg 算法签名的结果；
//    valid：是否是合法证书，1 为合法，0 为未知；
//    references：引用次数，被引用一次则加一；
//    name：证书持有者信息，内容形式为/C=CN/O=ourinfo……，该内容在调用d2i_X509的过程中，
//            通过回调函数x509_cb(crypto/asn1/x_x509.c)调用X509_NAME_oneline 来设置；
//    ex_data：扩展数据结构，用于存放用户自定义的信息；
//
//扩展项信息，用于证书验证。下面的扩展项信息由 crypto/x509v3/v3_purp.c 中的
//
//    x509v3_cache_extensions 函数设置：
//    ex_pathlen：证书路径长度，对应扩展项为NID_basic_constraints；
//    ex_flags：通过“与”计算存放各种标记；
//    ex_kusage：密钥用法，对应扩展项为NID_key_usage；
//    ex_xkusage：扩展密钥用法，对应扩展项为NID_ext_key_usage；
//    ex_nscert：Netscape 证书类型，对应扩展项为NID_netscape_cert_type；
//    skid：主体密钥标识，对应扩展项为NID_subject_key_identifier；
//    akid：颁发者密钥标识，对应扩展项为NID_authority_key_identifier；
//    policy_cache ： 各种策略缓存， crypto/x509v3/pcy_cache.c 中由函数
//    policy_cache_create 设置，对应的策略为NID_policy_constraints、NID_certificate_policies、
//    NID_policy_mappings 和NID_inhibit_any_policy（见policy_cache_new 和policy_cache_set函数）；
//    sha1_hash：存放证书的sha1 摘要值；
//    aux：辅助信息；
//
//上述两个结构的 DER 编解码接口由宏在crypto/asn1/x_x509.c 中实现，包括各自的new、free、i2d 和d2i 函数。

