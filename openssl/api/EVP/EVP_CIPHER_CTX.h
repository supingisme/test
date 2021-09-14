struct evp_cipher_ctx_st
{
    const EVP_CIPHER *cipher;
    ENGINE *engine;
    int encrypt;
    int buf_len;
    unsigned char oiv[EVP_MAX_IV_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char buf[EVP_MAX_BLOCK_LENGTH];
    /* 其他 */
    unsigned char final[EVP_MAX_BLOCK_LENGTH];
};

//对称算法上下文结构，此结构主要用来维护加解密状态，存放中间以及最后结果。因
//为加密或解密时，当数据很多时，可能会用到Update 函数，并且每次加密或解密的
//输入数据长度任意的，并不一定是对称算法block_size 的整数倍，所以需要用该结构
//来存放中间未加密的数据。主要项意义如下：
//    cipher：指明对称算法；
//    engine：硬件引擎；
//    encrypt：是加密还是解密；非0 为加密，0 为解密；
//    buf 和buf_len：指明还有多少数据未进行运算；
//    oiv：原始初始化向量；
//    iv：当前的初始化向量；
//    final：存放最终结果，一般与Final 函数对应。
