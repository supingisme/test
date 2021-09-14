
void *ASN1_d2i_fp(void *(*xnew)(void), d2i_of_void *d2i, FILE *in, void **x);
//        将in 指向的文件进行DER 解码，其内部调用了ASN1_d2i_bi 函数，用法与
//        ASN1_d2i_bi 类似。



