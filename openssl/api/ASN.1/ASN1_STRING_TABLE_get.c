ASN1_STRING_TABLE *ASN1_STRING_TABLE_get(int nid);

//    根据nid 来查找ASN1_STRING_TABLE 表。此函数先查找标准表tbl_standard，再
//    查找扩展表stable。ASN1_STRING_TABLE 数据结构在asn1.h 中定义，它用于约束
//    ASN1_STRING_set_by_NID 函数生成的ASN1_STRING 类型。
    
typedef struct asn1_string_table_st {
    int nid;
    long minsize;
    long maxsize;
    unsigned long mask;
    unsigned long flags;
} ASN1_STRING_TABLE;

//    其中nid 表示对象id，minsize 表示此nid 值的最小长度，maxsize 表示此nid 值的
//    最大长度，mask 为此nid 可以采用的ASN1_STRING 类型：B_ASN1_BMPSTRING、
//    B_ASN1_UTF8STRING、B_ASN1_T61STRING 和B_ASN1_UTF8STRING，flags 用于
//    标记是否为扩展或是否已有mask。
