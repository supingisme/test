//X509_NAME
//该结构是一个名称集合，在crypto/x509/x509.h 中定义如下：
struct X509_name_st
{
    STACK_OF(X509_NAME_ENTRY) *entries;
    int modified;
#ifndef OPENSSL_NO_BUFFER
    BUF_MEM *bytes;
#else
    char *bytes;
#endif
    unsigned long hash;
};
//它主要包含了X509_NAME_ENTRY 堆栈信息，bytes 用于存放DER 编码值，hash 为该
//结构的摘要计算值

//该结构的DER 编解码在crypto/asn1/x_name.c 中由宏实现。
//主要函数：
//    1) int X509_NAME_add_entry(X509_NAME *name, X509_NAME_ENTRY *ne, int loc,int set)
//    将一个X509_NAME_ENTRY 放入X509_NAME 的堆栈中，在堆栈中的位置
//    由loc 指定。
//    2) int X509_NAME_add_entry_by_NID(X509_NAME *name, int nid, int type,
//    unsigned char *bytes, int len, int loc, int set)
//    根据nid 在X509_NAME 的X509_NAME_ENTRY 堆栈中添加一项；bytes 为
//    要添加项的值，type 指明了types 的ASN1 类型，loc 为堆栈中的位置；根据nid 能
//    够获取ASN1_OBJECT(OBJ_nid2obj 函数)。
//    3) X509_NAME_add_entry_by_OBJ
//    与2）类似，只是要添加的项由ASN1_OBJECT 来表示。
//    4） X509_NAME_add_entry_by_txt
//    与2 ） 类似， 只是要添加的项由字符串来表示， 根据txt 能获取
//    ASN1_OBJECT(OBJ_txt2obj 函数)。
//    5） X509_NAME_ENTRY 509_NAME_ENTRY_create_by_NID(X509_NAME_ENTRY
//    **ne, int nid, int type, unsigned char *bytes, int len)
//    根据nid 来生成一个X509_NAME_ENTRY，bytes 为要添加项的值，type 指
//    明了types 的ASN1 类型。
//    6） X509_NAME_ENTRY_create_by_OBJ
//    与5）类似，生成的项由ASN1_OBJECT 来表示。
//    7） X509_NAME_ENTRY_create_by_txt
//    与5）类似，生成的项有字符串来表示。
//    8） int X509_NAME_get_text_by_NID(X509_NAME *name, int nid, char *buf, int len)
//    根据NID 来获取值，结果存放在buf 中。
//    9） X509_NAME_get_text_by_OBJ
//    根据ASN1_OBJECT 来获取值。
//    10) int X509_NAME_get_index_by_OBJ(X509_NAME *name,
//    ASN1_OBJECT *obj, int lastpos)
//    根据 ASN1_OBJECT 获取NAME_ENTRY 在堆栈中的位置。
//    11） X509_NAME_get_index_by_NID
//    根据 NID 获取X509_NAME_ENTRY 在堆栈中的位置。
//    12）X509_NAME_cmp
//    名字比较。
//    13）X509_NAME_delete_entry
//    从堆栈中删除一个指定位置的X509_NAME_ENTRY，并将它返回。
//    14）X509_NAME_digest
//    根据指定的算法，对X509_NAME 做摘要计算。
//    15）X509_NAME_dup
//    名字拷贝。
//    16）X509_NAME_entry_count
//    获取X509_NAME 的X509_NAME_ENTRY 堆栈中元素个数。
//    17）X509_NAME_ENTRY_dup
//    X509_NAME_ENTRY 拷贝。
//    18）X509_NAME_ENTRY_get/set_data
//    获取/设置一项名称的值；set 函数还需指明值的ASN1 类型。
//    19）X509_NAME_ENTRY_get/set_object
//    获取/设置一项名称的ASN1_OBJECT。
//    20）X509_NAME_get_entry
//    根据指定堆栈位置获取一个X509_NAME_ENTRY。
//    21）X509_NAME_hash
//    摘要计算，该结果是对MD5 的结果处理后的值。
//    22）char *X509_NAME_oneline(X509_NAME *a, char *buf, int len)
//    将a 表示的名字变成：/OU=z/CN=的形式放在buf 中，返回buf 首地址。
//    23) X509_NAME_print/ X509_NAME_print_ex
//    打印X509_NAME 到bio 中。
//    24) X509_NAME_print_ex_fp
//    打印X509_NAME 到FILE 中。
//    25) int X509_NAME_set(X509_NAME **xn, X509_NAME *name)
//    通过dup 函数，设置*xn 的值为name。
//

