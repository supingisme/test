int ASN1_STRING_set(ASN1_STRING *str, const void *_data, int len);

//设置ASN1 字符串类型的值。str 为ASN1_STRING 地址，_data 为设置值的首地址，
//len 为被设置值的长度。示例如下：
//
//    ASN1_STRING *str=NULL;
//    str=ASN1_STRING_new();
//    ASN1_STRING_set(str,”abc”,3);
//
//此示例生成的ASN1_STRING 类型为OCTET_STRING。其他的ASN1_STRING 类
//型也能用此函数设置，如下：
//
//    ASN1_PRINTABLESTRING *str=NULL;
//    str=ASN1_PRINTABLESTRING_new();
//    ASN1_STRING_set(str,”abc”,3);

