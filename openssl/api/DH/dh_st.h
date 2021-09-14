struct dh_st
{
    /* 其他 */
    BIGNUM *p;
    BIGNUM *g;
    long length; /* optional */
    BIGNUM *pub_key;
    BIGNUM *priv_key;
    int references;
    CRYPTO_EX_DATA ex_data;
    const DH_METHOD *meth;
    ENGINE *engine;
    /* 其他 */
};
//    p、g、length：DH 密钥参数；
//    pub_key：DH 公钥；
//    priv_key：DH 私钥；
//    references：引用；
//    ex_data：扩展数据；
//    meth：DH_METHOD，本DH 密钥的各种计算方法，明确指明了DH 的各种运算方式；
//    engine：硬件引擎。

