#include <openssl/dh.h>
#include <memory.h>
//本例主要演示了生成DH 密钥以及密钥交换函数。

int main()
{
    DH *d1,*d2;
    BIO *b;
    int ret,size,i,len1,len2;
    char sharekey1[128],sharekey2[128];
    
    /* 构造DH 数据结构 */
    d1=DH_new();
    d2=DH_new();
    
    /* 生成d1 的密钥参数，该密钥参数是可以公开的 */
    ret=DH_generate_parameters_ex(d1,64,DH_GENERATOR_2,NULL);
    if(ret!=1)
    {
        printf("DH_generate_parameters_ex err!\n");
        return -1;
    }
    
    /* 检查密钥参数 */
    ret=DH_check(d1,&i);
    if(ret!=1)
    {
        printf("DH_check err!\n");
        if(i&DH_CHECK_P_NOT_PRIME)
            printf("p value is not prime\n");
        if(i&DH_CHECK_P_NOT_SAFE_PRIME)
            printf("p value is not a safe prime\n");
        if (i&DH_UNABLE_TO_CHECK_GENERATOR)
            printf("unable to check the generator value\n");
        if (i&DH_NOT_SUITABLE_GENERATOR)
            printf("the g value is not a generator\n");
    }
    printf("DH parameters appear to be ok.\n");
    
    /* 密钥大小 */
    size=DH_size(d1);
    printf("DH key1 size : %d\n",size);
    
    /* 生成公私钥 */
    ret=DH_generate_key(d1);
    if(ret!=1)
    {
        printf("DH_generate_key err!\n");
        return -1;
    }
    
    /* p 和g 为公开的密钥参数，因此可以拷贝 */
    d2->p=BN_dup(d1->p);
    d2->g=BN_dup(d1->g);
    
    /* 生成公私钥,用于测试生成共享密钥 */
    ret=DH_generate_key(d2);
    if(ret!=1)
    {
        printf("DH_generate_key err!\n");
        return -1;
    }
    
    /* 检查公钥 */
    ret=DH_check_pub_key(d1,d1->pub_key,&i);
    if(ret!=1)
    {
        if (i&DH_CHECK_PUBKEY_TOO_SMALL)
            printf("pub key too small \n");
        if (i&DH_CHECK_PUBKEY_TOO_LARGE)
            printf("pub key too large \n");
    }
    
    /* 计算共享密钥 */
    len1=DH_compute_key(sharekey1,d2->pub_key,d1);
    len2=DH_compute_key(sharekey2,d1->pub_key,d2);
    if(len1!=len2)
    {
        printf("生成共享密钥失败1\n");
        return -1;
    }
    if(memcmp(sharekey1,sharekey2,len1)!=0)
    {
        printf("生成共享密钥失败2\n");
        return -1;
    }
    printf("生成共享密钥成功\n");
    
    b=BIO_new(BIO_s_file());
    BIO_set_fp(b,stdout,BIO_NOCLOSE);
    
    /* 打印密钥 */
    DHparams_print(b,d1);
    BIO_free(b);
    DH_free(d1);
    DH_free(d2);
    return 0;
}

