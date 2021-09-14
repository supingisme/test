//comp_ctx
//该结构用于存放压缩/解压中的上下文数据，主要供crypto/comp/comp_lib.c 使用。
struct comp_ctx_st
{
    COMP_METHOD *meth;
    unsigned long compress_in;
    unsigned long compress_out;
    unsigned long expand_in;
    unsigned long expand_out;
    CRYPTO_EX_DATA ex_data;
};
//    各项意义如下：
//    meth：COMP_METHOD 结构，一个comp_ctx 通过它指明了一种具体的压缩算法；
//    compress_in：被压缩数据总字节数；
//    compress_out：压缩数据(结果)总字节数；
//    expand_in：被解压数据总字节数；
//    expand_out：解压数据（结果）总字节数；
//    ex_data：供用户使用的扩展数据，用于存放用户自定义的信息。
