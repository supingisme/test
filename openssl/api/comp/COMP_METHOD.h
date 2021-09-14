//Openssl 通过函数地址来抽象数据压缩。主要数据结构如下：
//1) COMP_METHOD
//该数据结构定义了具体压缩/解压函数，这些函数可由用户自己实现。

typedef struct comp_method_st
{
    int type;
    const char *name;
    int (*init)(COMP_CTX *ctx);
    void (*finish)(COMP_CTX *ctx);
    int (*compress)(COMP_CTX *ctx,unsigned char *out, unsigned int olen,
    unsigned char *in, unsigned int ilen);
    int (*expand)(COMP_CTX *ctx,unsigned char *out, unsigned int olen,
    unsigned char *in, unsigned int ilen);
    long (*ctrl)(void);
    long (*callback_ctrl)(void);
} COMP_METHOD;

    //各项意义如下：
    //type：压缩算法的nid；
    //name：压缩算法的名字；
    //init：初始化函数；
    //finish：结束操作；
    //commpress：具体的压缩算法，本函数必须实现；
    //expand：具体的解压算法，本函数必须实现；
    //ctrl 和callback_ctrl：控制函数与回调控制函数，用于内部控制。
    
//通过 COMP_METHOD，Openssl 能调用用户自己实现的压缩算法。只要用户实现
//了COMP_METHOD 中的各个函数(主要是compress 和expand 函数)。
//Openssl 压缩源码位于crypto/comp 目录下。它实现了一个空压缩算法和zlib 压缩算
//法。其中空压缩算法由openssl 自己实现，只是简单的拷贝数据。而zlib 算法，openssl
//实现了基于其接口的COMP_METHOD，需要zlib 库支持(/usr/lib/libz.a，/usr/lib/libz.so)。