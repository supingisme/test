//该数据结构用来表示算法，它定义在crypto/x509/x509.h 中，如下：
struct X509_algor_st
{
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
};
//包含两项：
//algorithm：ASN1_OBJECT 类型，表明了是何种算法；
//parameter：ASN1_TYPE 类型，代表该算法需要的参数。ASN1_TYPE 类型可以存放任
//意数据。
//该结构的 DER 编解码接口在crypto/asn1/x_algor.c 中由ASN1 宏来实现，其中parameter
//是可选的。该结构相关的函数为：new(生成数据结构)、free(释放数据结构)、i2d(将它
//转换为DER 编码)、d2i(由DER 编码转换为该结构)和dup(拷贝)。
