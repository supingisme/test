typedef struct ERR_string_data_st
{
    unsigned long error;
    const char *string;
} ERR_STRING_DATA;

//该数据结构的内容由各个功能模块来设置。其中，error 用来存放错误信息（由库
//代码、函数代码以及错误原因代码计算得来），string 用来存放文本信息，可以是函数名
//也可以是错误原因。以crypto/bio_err.c 为例，它定义了两个全局表，分别用来存放函数
//信息和错误信息

#define ERR_FUNC(func) ERR_PACK(ERR_LIB_BIO,func,0)
#define ERR_REASON(reason) ERR_PACK(ERR_LIB_BIO,0,reason)
static ERR_STRING_DATA BIO_str_functs[]=
{
{ERR_FUNC(BIO_F_ACPT_STATE), "ACPT_STATE"},
……
}
static ERR_STRING_DATA BIO_str_reasons[]=
{
{ERR_REASON(BIO_R_ACCEPT_ERROR) ,"accept error"},
{ERR_REASON(BIO_R_BAD_FOPEN_MODE) ,"bad fopen mode"},
……
}

