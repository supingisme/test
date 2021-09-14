//DSA_METHOD
struct dsa_method
{
    const char *name;
    DSA_SIG * (*dsa_do_sign)(const unsigned char *dgst, int dlen, DSA *dsa);
    int (*dsa_sign_setup)(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp, BIGNUM **rp);
    int (*dsa_do_verify)(const unsigned char *dgst, int dgst_len, DSA_SIG *sig, DSA *dsa);
    /* 其他 */
    int (*dsa_paramgen)(DSA *dsa, int bits,unsigned char *seed, int seed_len, int *counter_ret, unsigned long *h_ret,BN_GENCB *cb);
    int (*dsa_keygen)(DSA *dsa);
};
//本结构是一个函数集合，DSA 的各种计算都通过它来实现。drypto/dsa_ossl.c
    //中实现了一个默认的DSA_METHOD。如果用户实现了自己的DSA_METHOD，
    //通过调用 DSA_set_default_method 或DSA_set_method，用户可以让openssl 采用自
    //己的DSA 计算函数。
    
//主要项意义如下：
//name：DSA_METHOD 的名字；
//dsa_do_sign：签名算法函数；
//dsa_sign_setup：根据密钥参数生成公私钥的函数；
//dsa_do_verify：签名验证函数；
//dsa_paramgen：生成密钥参数函数；
//dsa_keygen：生成公私钥函数。

