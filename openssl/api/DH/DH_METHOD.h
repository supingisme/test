//DH 数据结构定义在crypto/dh/dh.h 中，主要包含两项，如下：
//1) DH_METHOD
struct dh_method
{
    const char *name;
    int (*generate_key)(DH *dh);
    int (*compute_key)(unsigned char *key,const BIGNUM *pub_key,DH *dh);
    int (*bn_mod_exp)(const DH *dh, BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,BN_MONT_CTX *m_ctx);
    int (*init)(DH *dh);
    int (*finish)(DH *dh);
    int flags;
    char *app_data;
    int (*generate_params)(DH *dh, int prime_len, int generator, BN_GENCB *cb);
};
//
//DH_METHOD 指明了一个DH 密钥所有的计算方法函数。用户可以实现自己的
//DH_METHOD 来替换openssl 提供默认方法。各项意义如下：
//
//    name：DH_METHOD 方法名称。
//    generate_key：生成DH 公私钥的函数。
//    compute_key：根据对方公钥和己方DH 密钥来生成共享密钥的函数。
//    bn_mod_exp：大数模运算函数，如果用户实现了它，生成DH 密钥时，将采用用户实现的该回调函数。用于干预DH 密钥生成。
//    init：初始化函数。
//    finish：结束函数。
//    flags：用于记录标记。
//    app_data：用于存放应用数据。
//    generate_params：生成DH 密钥参数的回调函数，生成的密钥参数是可以公开的。
