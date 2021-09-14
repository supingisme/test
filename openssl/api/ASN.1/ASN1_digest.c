int ASN1_digest(i2d_of_void *i2d, const EVP_MD *type, char *data,unsigned char *md, unsigned int *len);
//        ASN1 数据类型签名。将data 指针指向的ASN1 数据类型用i2d 函数进行DER 编
//        码，然后用type 指定的摘要方法进行计算，结果存放在md 中，结果的长度由len 表示。



