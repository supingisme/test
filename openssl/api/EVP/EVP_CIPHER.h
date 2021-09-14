//EVP_CIPHER
struct evp_cipher_st
{
    int nid;
    int block_size;
    int key_len;
    int iv_len;
    unsigned long flags;
    int (*init)(EVP_CIPHER_CTX *ctx, const unsigned char *key,const unsigned char *iv, int enc);
    int (*do_cipher)(EVP_CIPHER_CTX *ctx, unsigned char *out,const unsigned char *in, unsigned int inl);
    int (*cleanup)(EVP_CIPHER_CTX *); /* cleanup ctx */
    int ctx_size;
    int (*set_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *);
    int (*get_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *);
    int (*ctrl)(EVP_CIPHER_CTX *, int type, int arg, void *ptr);
    void *app_data;
} ;
//该结构用来存放对称加密相关的信息以及算法。主要各项意义如下：
//    nid：对称算法nid；
//    block_size：对称算法每次加解密的字节数；
//    key_len：对称算法的密钥长度字节数；
//    iv_len：对称算法的填充长度；
//    flags：用于标记；
//    init：加密初始化函数，用来初始化ctx，key 为对称密钥值，iv 为初始化向量，enc用于指明是要加密还是解密，这些信息存放在ctx 中；
//    do_cipher：对称运算函数，用于加密或解密；
//    cleanup：清除上下文函数；
//    set_asn1_parameters：设置上下文参数函数；
//    get_asn1_parameters：获取上下文参数函数；
//    ctrl：控制函数；
//    app_data：用于存放应用数据。
//    openssl 对于各种对称算法实现了上述结构，各个源码位于cypto/evp 目录下，文件名以e_开头。Openssl 通过这些结构来封装了对称算法相关的运算。
