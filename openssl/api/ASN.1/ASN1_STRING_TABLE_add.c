int ASN1_STRING_TABLE_add(int nid, long minsize, long maxsize, unsigned long mask, unsigned long flags);
//    添加扩展的ASN1_STRING_TABLE 项。说明： a_strnid.c 中定义了基本的
//    ASN1_STRING_TABLE 项，如果用户要添加新的ASN1_STRING_TABLE 项，需要调
//    此次函数。Openssl 源代码中有好几处都有这种用法，Openssl 定义标准的某种表，并且
//    提供扩展函数供用户去扩充。
//    示例：ASN1_STRING_TABLE_add（NID_yourNID,1,100, DIRSTRING_TYPE,0）。
