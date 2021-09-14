//openssl 中，通过unsigned long 类型来存放错误信息。它包含三部分内容：库代码、
//函数代码以及错误原因代码。其中，库代码在crypto/err.h 中定义，函数代码以及错误
//原因代码由各个功能模块定义（同类代码不能与其他的重复，也不能超过一定的大小）。
//比如err.h 中为BIO 定义如下库代码：

/* library */
#define ERR_LIB_BIO 32
//而 crypto/bio.h 中定义了如下函数和错误原因代号：
/* Function codes. */
#define BIO_F_ACPT_STATE 100
/* Reason codes. */
#define BIO_R_ACCEPT_ERROR 100
//错误信息通过上述三部分通过计算得到，并且根据此信息能提取各个代码。计算函
//数在err.h 中定义如下：
#define ERR_PACK(l,f,r) (((((unsigned long)l)&0xffL)*0x1000000)| \
                        ((((unsigned long)f)&0xfffL)*0x1000)| \
                        ((((unsigned long)r)&0xfffL)))
#define ERR_GET_LIB(l) (int)((((unsigned long)l)>>24L)&0xffL)
#define ERR_GET_FUNC(l) (int)((((unsigned long)l)>>12L)&0xfffL)
#define ERR_GET_REASON(l) (int)((l)&0xfffL)
