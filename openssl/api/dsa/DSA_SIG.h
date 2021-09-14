//DSA 数据结构定义在crypto/dsa.h 中，如下所示：
//1) DSA_SIG
//签名值数据结构
typedef struct DSA_SIG_st
{
    BIGNUM *r;
    BIGNUM *s;
} DSA_SIG;
//签名结果包括两部分，都是大数。
