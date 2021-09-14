//RSA 数据结构中包含了公/私钥信息（如果仅有n 和e，则表明是公钥），定义如下：
struct rsa_st
{
    /* 其他 */
    const RSA_METHOD *meth;
    ENGINE *engine;
    BIGNUM *n;
    BIGNUM *e;
    BIGNUM *d;
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *dmp1;
    BIGNUM *dmq1;
    BIGNUM *iqmp;
    CRYPTO_EX_DATA ex_data;
    int references;
    /* 其他数据项 */
};
//各项意义：
//    meth：RSA_METHOD 结构，指明了本RSA 密钥的各种运算函数地址；
//    engine：硬件引擎；
//    n，e，d，p，q，dmp1，dmq1，iqmp：RSA 密钥的各个值；
//    ex_data：扩展数据结构，用于存放用户数据；
//    references：RSA 结构引用数。

