/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
//BIO 数据结构主要有2 个，在crypto/bio.h 中定义如下：
//1）BIO_METHOD
typedef struct bio_method_st
{
    int type;
    const char *name;
    int (*bwrite)(BIO *, const char *, int);
    int (*bread)(BIO *, char *, int);
    int (*bputs)(BIO *, const char *);
    int (*bgets)(BIO *, char *, int);
    long (*ctrl)(BIO *, int, long, void *);
    int (*create)(BIO *);
    int (*destroy)(BIO *);
    long (*callback_ctrl)(BIO *, int, bio_info_cb *);
} BIO_METHOD;
//该结构定义了IO 操作的各种回调函数，根据需要，具体的bio 类型必须实现其中
//的一种或多种回调函数，各项意义如下：
    //type：具体BIO 类型；
    //name：具体BIO 的名字；
    //bwrite：具体BIO 写操作回调函数；
    //bread：具体BIO 读操作回调函数；
    //bputs：具体BIO 中写入字符串回调函数；
    //bgets：具体BIO 中读取字符串函数；
    //ctrl：具体BIO 的控制回调函数；
    //create：生成具体BIO 回调函数；
    //destroy：销毁具体BIO 回调函数；
    //callback_ctrl：具体BIO 控制回调函数，与ctrl 回调函数不一样，该函数可由调用
    //者（而不是实现者）来实现，然后通过BIO_set_callback 等函数来设置。

struct bio_st
{
    BIO_METHOD *method;
    /* bio, mode, argp, argi, argl, ret */
    long (*callback)(struct bio_st *,int,const char *,int, long,long);
    char *cb_arg; /* first argument for the callback */
    int init;
    int shutdown;
    int flags; /* extra storage */
    int retry_reason;
    int num;
    void *ptr;
    struct bio_st *next_bio; /* used by filter BIOs */
    struct bio_st *prev_bio; /* used by filter BIOs */
    int references;
    nsigned long num_read;
    unsigned long num_write;
    CRYPTO_EX_DATA ex_data;
};
//主要项含义：
    //init：具体句柄初始化标记，初始化后为1。比如文件BIO 中，通过BIO_set_fp
    //关联一个文件指针时，该标记则置1；socket BIO 中通过BIO_set_fd 关联一个链接
    //时设置该标记为1。
    //shutdown：BIO 关闭标记，当该值不为0 时，释放资源；改值可以通过控制函
    //数来设置。
    //flags：有些BIO 实现需要它来控制各个函数的行为。比如文件BIO 默认该值
    //为BIO_FLAGS_UPLINK，这时文件读操作调用UP_fread 函数而不是调用fread 函
    //数。
    //retry_reason：重试原因，主要用在socket 和ssl BIO 的异步阻塞。比如socket
    //bio 中，遇到WSAEWOULDBLOCK 错误时，openssl 告诉用户的操作需要重试。
    //num：该值因具体BIO 而异，比如socket BIO 中num 用来存放链接字。
    //ptr：指针，具体bio 有不同含义。比如文件BIO 中它用来存放文件句柄；mem
    //bio 中它用来存放内存地址；connect bio 中它用来存放BIO_CONNECT 数据，accept
    //bio 中它用来存放BIO_ACCEPT 数据。
    //next_bio：下一个BIO 地址，BIO 数据可以从一个BIO 传送到另一个BIO，该
    //值指明了下一个BIO 的地址。
    //references：被引用数量。
    //num_read：BIO 中已读取的字节数。
    //num_write：BIO 中已写入的字节数。
    //ex_data：用于存放额外数据。

