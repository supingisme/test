//Openssl 实现了ECC 算法。ECC 算法系列包括三部分：ECC 算法(crypto/ec)、椭圆曲线
//数字签名算法ECDSA (crypto/ecdsa)以及椭圆曲线密钥交换算法ECDH(crypto/dh)。
//研究椭圆曲线需要注意的有：
//1) 密钥数据结构
//主要是公钥和私钥数据结构。椭圆曲线密钥数据结构如下，定义在crypto/ec_lcl.h
//中，对用户是透明的。
struct ec_key_st
{
    int version;
    EC_GROUP *group;
    EC_POINT *pub_key;
    BIGNUM *priv_key;
    /* 其他项 */
}

//2) 密钥生成
//对照公钥和私钥的表示方法，非对称算法不同有各自的密钥生成过程。椭圆曲
//线的密钥生成实现在crytpo/ec/ec_key.c 中。Openssl 中，椭圆曲线密钥生成时，首
//先用户需要选取一种椭圆曲线(openssl 的crypto/ec_curve.c 中内置实现了67 种，调
//用EC_get_builtin_curves 获取该列表)，然后根据选择的椭圆曲线计算密钥生成参
//数group，最后根据密钥参数group 来生公私钥。
//3） 签名值数据结构
//非对称算法不同，签名的结果表示也不一样。与DSA 签名值一样，ECDSA 的
//签名结果表示为两项。ECDSA 的签名结果数据结构定义在crypto/ecdsa/ecdsa.h 中，
//如下：
typedef struct ECDSA_SIG_st
{
    BIGNUM *r;
    135
    BIGNUM *s;
} ECDSA_SIG;
//4) 签名与验签
//对照签名结果，研究其是如何生成的。crypto/ecdsa/ ecs_sign.c 实现了签名算法，
//crypto/ecdsa/ ecs_vrf.c 实现了验签。
//5） 密钥交换
//研究其密钥交换是如何进行的；crypto/ecdh/ech_ossl.c 实现了密钥交换算法。

