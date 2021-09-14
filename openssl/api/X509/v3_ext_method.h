//2）通过X509V3_EXT_METHOD 进行DER 编解码
//Openssl 通过X509V3_EXT_METHOD 来实现对扩展项的编解码。
//X509V3_EXT_METHOD 定义在crypto/x509v3/x509v3.h 中，如下：
struct v3_ext_method
{
    int ext_nid;
    int ext_flags;
    ASN1_ITEM_EXP *it;
    X509V3_EXT_NEW ext_new;
    X509V3_EXT_FREE ext_free;
    X509V3_EXT_D2I d2i;
    X509V3_EXT_I2D i2d;
    X509V3_EXT_I2S i2s;
    X509V3_EXT_S2I s2i;
    X509V3_EXT_I2V i2v;
    X509V3_EXT_V2I v2i;
    X509V3_EXT_I2R i2r;
    X509V3_EXT_R2I r2i;
    void *usr_data;
};
typedef struct v3_ext_method X509V3_EXT_METHOD;
//该结构以ext_nid 表示是何种扩展项，以it、d2i 和i2d 函数来指明来它的DER 编解码
//函数。这样，只要知道了ext_nid，就能够对数据进行DER 编解码


//######### 主要函数：
//􀂾 X509V3_EXT_add：在扩展X509V3_EXT_METHOD 表ext_list 中添加一个方
//法。
//􀂾 X509V3_EXT_get_nid：根据nid 来查找X509V3_EXT_METHOD。
//􀂾 X509V3_EXT_get：根据扩展项来查找X509V3_EXT_METHOD，它调用了
//X509V3_EXT_get_nid
//􀂾 X509V3_EXT_add_alias：添加一个X509V3_EXT_METHOD，使具有相同方
//法的X509V3_EXT_METHOD 有不同的扩展项nid。
//􀂾 X509V3_get_d2i：从扩展项堆栈中查找具体的扩展项，并返回具体扩展项数据
//结构地址。
//􀂾 X509V3_EXT_print：打印单个扩展项。
//􀂾 int X509V3_add1_i2d(STACK_OF(X509_EXTENSION) **x, int nid, void
//*value,int crit, unsigned long flags)。

