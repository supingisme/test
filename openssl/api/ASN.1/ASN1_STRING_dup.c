ASN1_STRING *ASN1_STRING_dup(ASN1_STRING *str);
    //ASN1_STRING 类型拷贝。内部申请空间，需要用户调用ASN1_STRING_free 释放该空间。
