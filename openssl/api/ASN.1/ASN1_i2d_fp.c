int ASN1_i2d_fp(i2d_of_void *i2d, FILE *out, void *x);
//将ASN1 数据结构DER 编码并写入FILE，此函数调用了ASN1_i2d_bio。
