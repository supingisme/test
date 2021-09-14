/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <openssl/dso.h>
#include <openssl/bio.h>
int main()
{
    DSO *d;
    
    void (*f1)();
    void (*f2)();
    
    BIO *(*BIO_newx)(BIO_METHOD *a);
    BIO *(*BIO_freex)(BIO_METHOD *a);
    BIO *test;
    
    d=DSO_new();
    d=DSO_load(d,"./libtest.so",NULL,0);
    
    f1=DSO_bind_func(d,"func1");
    f2=DSO_bind_var(d,"func2");
    
    BIO_newx=(BIO *(*)(BIO_METHOD *))f1;
    BIO_freex=(BIO *(*)(BIO_METHOD *))f2;
    
    test=BIO_newx(BIO_s_file());
    
    BIO_set_fp(test,stdout,BIO_NOCLOSE);
    BIO_puts(test,"abd\n\n");
    
    BIO_freex(test);
    DSO_free(d);
    return 0;
}

