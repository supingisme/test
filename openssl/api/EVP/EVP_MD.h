//EVP_MD
struct env_md_st
{
    int type;
    int pkey_type;
    int md_size;
    unsigned long flags;
    int (*init)(EVP_MD_CTX *ctx);
    int (*update)(EVP_MD_CTX *ctx,const void *data,size_t count);
    int (*final)(EVP_MD_CTX *ctx,unsigned char *md);
    int (*copy)(EVP_MD_CTX *to,const EVP_MD_CTX *from);
    int (*cleanup)(EVP_MD_CTX *ctx);
    int (*sign)(int type, const unsigned char *m, unsigned int m_length,unsigned char *sigret, unsigned int *siglen, void *key);
    int (*verify)(int type, const unsigned char *m, unsigned int m_length, const unsigned char *sigbuf, unsigned int siglen,void *key);
    int required_pkey_type[5];
    int block_size;
    int ctx_size; /* how big does the ctx->md_data need to be */
} ;

//该结构用来存放摘要算法信息、非对称算法类型以及各种计算函数。主要各项意义如下：
//    type：摘要类型，一般是摘要算法NID；
//    pkey_type：公钥类型，一般是签名算法NID；
//    md_size：摘要值大小，为字节数；
//    flags：用于设置标记；
//    init：摘要算法初始化函数；
//    update：多次摘要函数；
//    final：摘要完结函数；
//    copy：摘要上下文结构复制函数；
//    cleanup：清除摘要上下文函数；
//    sign：签名函数，其中key 为非对称密钥结构地址；
//    verify：摘要函数，其中key 为非对称密钥结构地址。
//    openssl 对于各种摘要算法实现了上述结构，各个源码位于cypto/evp 目录下，文件名以m_开头。Openssl 通过这些结构来封装了各个摘要相关的运算。
