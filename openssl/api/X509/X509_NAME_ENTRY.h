//X509_NAME_ENTRY
//该数据结构代表了一个名称，数据结构在crypto/x509/x509.h 中定义如下：
typedef struct X509_name_entry_st
{
    ASN1_OBJECT *object;
    ASN1_STRING *value;
    int set;
    int size;
} X509_NAME_ENTRY;
//每个 X509_NAME_ENTRY 对应于一个证书中的C、OU 和O 等实体名称，其中object
//表明了实体的类型是C 还是OU 等；value 表明了该实体的内容，这两项用于DER 编解码。
//该结构的DER 编解码在crypto/asn1/x_name.c 中由宏实现，包括new、free、i2d、d2i 和dup
//函数。
