struct rsa_meth_st
{
    const char *name;
    int (*rsa_pub_enc)(int flen,const unsigned char *from,unsigned char *to,RSA *rsa,int padding);
    int (*rsa_pub_dec)(int flen,const unsigned char *from,unsigned char *to,RSA *rsa,int padding);
    int (*rsa_priv_enc)(int flen,const unsigned char *from,unsigned char *to,RSA *rsa,int padding);
    int (*rsa_priv_dec)(int flen,const unsigned char *from,unsigned char *to,RSA *rsa,int padding);
    /* 其他函数 */
    int (*rsa_sign)(int type,const unsigned char *m, unsigned int m_length,unsigned char *sigret, unsigned int *siglen, const RSA *rsa);
    int (*rsa_verify)(int dtype,const unsigned char *m, unsigned int m_length,unsigned char *sigbuf, unsigned int siglen, const RSA *rsa);
    int (*rsa_keygen)(RSA *rsa, int bits, BIGNUM *e, BN_GENCB *cb);
};

//主要项说明：
//    name：RSA_METHOD 名称；
//    rsa_pub_enc：公钥加密函数，padding 为其填充方式，输入数据不能太长，否则无法填充；
//    rsa_pub_dec：公钥解密函数，padding 为其去除填充的方式，输入数据长度为RSA 密钥长度的字节数；
//    rsa_priv_enc：私钥加密函数，padding 为其填充方式，输入数据长度不能太长，否则无法填充；
//    rsa_priv_dec：私钥解密函数，padding 为其去除填充的方式，输入数据长度为RSA 密钥长度的字节数；
//    rsa_sign：签名函数；
//    rsa_verify：验签函数；
//    rsa_keygen：RSA 密钥对生成函数。
//    
//用户可实现自己的 RSA_METHOD 来替换openssl 提供的默认方法。