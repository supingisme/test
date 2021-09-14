/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/dso.h>
#include <openssl/bio.h>
int main()
    {
    DSO *d;
    void (*f)();
    BIO *(*BIO_newx)(BIO_METHOD *a);
    BIO *test;
    char *load_name;
    const char *loaded_name;
    int flags;
    d=DSO_new();
#if 0
    DSO_set_name_converter
    DSO_ctrl(d,DSO_CTRL_SET_FLAGS,DSO_FLAG_NO_NAME_TRANSLATION,NULL);
    DSO_ctrl(d,DSO_CTRL_SET_FLAGS,DSO_FLAG_NAME_TRANSLATION_EXT_ONLY,NU
    LL);
    DSO_ctrl(d,DSO_CTRL_SET_FLAGS,DSO_FLAG_GLOBAL_SYMBOLS,NULL);
    /* 最好写成libeay32 而不是libeay32.dll， 除 非 前 面 调 用 了
    DSO_ctrl(d,DSO_CTRL_SET_FLAGS,DSO_FLAG_NO_NAME_TRANSLATION,NULL)否则
    它会加载libeay32.dll.dll
    */
    load_name=DSO_merge(d,"libeay32","D:\\zcp\\OpenSSL\\openssl-0.9.8b\\out32dll\\Debug");
#endif
    d=DSO_load(d,"libeay32",NULL,0);
    if(d==NULL)
    {
        printf("err");
        return -1;
    }
    loaded_name=DSO_get_loaded_filename(d);
    if(loaded_name!=NULL)
    {
        printf("loaded file is %s\n",loaded_name);
    }
    flags=DSO_flags(d);
    printf("current falgs is %d\n",flags);
    DSO_up_ref(d);
    f=(void (*)())DSO_bind_var(d,"BIO_new");
    BIO_newx=(BIO *(*)(BIO_METHOD *))f;
    test=BIO_newx(BIO_s_file());
    BIO_set_fp(test,stdout,BIO_NOCLOSE);
    BIO_puts(test,"abd\n\n");
    BIO_free(test);
    DSO_free(d);
    printf("handle in dso number is : %d\n",d->meth_data->num);
    DSO_free(d);
    printf("handle in dso number is : %d\n",d->meth_data->num);
    return 0;
}

