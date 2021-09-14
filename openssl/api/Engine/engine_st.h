//Engine 数据结构定义在crypto/engine/eng_int.h 文件中，是对用户透明的数据结构，如
//下：
struct engine_st
{
    const char *id;
    const char *name;
    const RSA_METHOD *rsa_meth;
    const DSA_METHOD *dsa_meth;
    const DH_METHOD *dh_meth;
    const ECDH_METHOD *ecdh_meth;
    const ECDSA_METHOD *ecdsa_meth;
    const RAND_METHOD *rand_meth;
    const STORE_METHOD *store_meth;
    ENGINE_CIPHERS_PTR ciphers;
    ENGINE_DIGESTS_PTR digests;
    ENGINE_GEN_INT_FUNC_PTR destroy;
    ENGINE_GEN_INT_FUNC_PTR init;
    ENGINE_GEN_INT_FUNC_PTR finish;
    ENGINE_CTRL_FUNC_PTR ctrl;
    ENGINE_LOAD_KEY_PTR load_privkey;
    ENGINE_LOAD_KEY_PTR load_pubkey;
    
    /* 其他项 */
    CRYPTO_EX_DATA ex_data;
    struct engine_st *prev;
    struct engine_st *next;
};
//本结构包含大量的运算集合函数(包括各种METHOD)供用户来实现。各项意义如下：
//    id：Engine 标识；
//    name：Engine 的名字；
//    rsa_meth：RSA 方法集合；
//    dsa_meth：DSA 方法集合；
//    dh_meth：DH 方法集合；
//    ecdh_meth：ECDH 方法结合；
//    ecdsa_meth：ECDSA 方法集合；
//    rand_meth：随机数方法集合；
//    store_meth：存储方法集合；
//    ciphers：对称算法选取函数。硬件一般会支持多种对称算法，该回调函数用来从用户实现的多个对称算法中根据某种条件(一般是算法nid)来选择其中的一种；
//    digests：摘要算法选取函数。该回调函数用来从用户实现的多个摘要算法中根据某种条件(一般是算法nid)来选择其中的一种；
//    destroy：销毁引擎函数；
//    init：初始化引擎函数；
//    finish：完成回调函数；
//    ctrl：控制函数；
//    load_privkey：加载私钥函数；
//    load_pubkey：加载公钥函数；
//    ex_data：扩展数据结构，可用来存放用户数据；
//    prev/next：用于构建Engine 链表，openssl 中的硬件Engine 可能不止一个。
//    上述这些函数，用户根据应用的需求来实现其中的一种或多种。

