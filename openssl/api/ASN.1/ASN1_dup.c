void *ASN1_dup(i2d_of_void *i2d, d2i_of_void *d2i, char *x);
//        ASN1 数据复制。x 为ASN1 内部数据结构，本函数先将x 通过i2d 将它变成DER
//        编码，然后用d2i 再DER 解码，并返回解码结果。
