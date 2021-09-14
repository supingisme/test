//RSA 加解密运算
#include <openssl/rsa.h>
#include <openssl/sha.h>

#define RED_START   printf("\033[1;31m");
#define RED_END     printf("\033[m");


int main()
{
    RSA *r;
    int bits=1024,ret,len,flen,padding,i;
    unsigned long e=RSA_3;
    BIGNUM *bne;
    unsigned char *key,*p;
    BIO *b;
    unsigned char from[500],to[500],out[500];
    bne=BN_new();
    ret=BN_set_word(bne,e);
    r=RSA_new();
    ret=RSA_generate_key_ex(r,bits,bne,NULL);
    if(ret!=1)
    {
        printf("RSA_generate_key_ex err!\n");
        return -1;
    }
    /* 私钥i2d */
    b=BIO_new(BIO_s_mem());
    ret=i2d_RSAPrivateKey_bio(b,r);
    key=malloc(1024);
    len=BIO_read(b,key,1024);
    BIO_free(b);
    b=BIO_new_file("rsa.key","w");
    ret=i2d_RSAPrivateKey_bio(b,r);
    BIO_free(b);

    /* 私钥d2i */
    /* 公钥i2d */
    /* 公钥d2i */
    /* 私钥加密 */
    flen=RSA_size(r);
    
    printf("please select private enc padding : \n");
    printf("1.RSA_PKCS1_PADDING\n");
    printf("3.RSA_NO_PADDING\n");
    printf("5.RSA_X931_PADDING\n");
    
    scanf("%d",&padding);
    
    if(padding==RSA_PKCS1_PADDING)
        flen-=11;
    else if(padding==RSA_X931_PADDING)
        flen-=2;
    else if(padding==RSA_NO_PADDING)
        flen=flen;
    else
    {
        printf("rsa not surport !\n");
        return -1;
    }
    for(i=0;i<flen;i++)
        memset(&from[i],i,1);
    
    len=RSA_private_encrypt(flen,from,to,r,padding);
    if(len<=0)
    {
        printf("RSA_private_encrypt err!\n");
        return -1;
    }

    printf("-------------------------------------------------out\n");
    for(i=0;i<len;i++)
        printf("%2d ", out[i]);
    printf("\n");
    
    RED_START;
    printf("-------------------------------------------------from\n");
    for(i=0;i<len;i++)
        printf("%2d ", from[i]);
    printf("\n");

    printf("-------------------------------------------------to\n");
    for(i=0;i<len;i++)
        printf("%2d ", to[i]);
    printf("\n");
    RED_END;
    
    len=RSA_public_decrypt(len,to,out,r,padding);
    if(len<=0)
    {
        printf("RSA_public_decrypt err!\n");
        return -1;
    }
    if(memcmp(from,out,flen))
    {
        printf("err!\n");
        return -1;
    }
    
    RED_START;
    printf("-------------------------------------------------out\n");
    for(i=0;i<len;i++)
        printf("%2d ", out[i]);
    printf("\n");
    RED_END;
    
    printf("-------------------------------------------------from\n");
    for(i=0;i<len;i++)
        printf("%2d ", from[i]);
    printf("\n");

    printf("-------------------------------------------------to\n");
    for(i=0;i<len;i++)
        printf("%2d ", to[i]);
    printf("\n");
    
    /* */
    printf("please select public enc padding : \n");
    printf("1.RSA_PKCS1_PADDING\n");
    printf("2.RSA_SSLV23_PADDING\n");
    printf("3.RSA_NO_PADDING\n");
    printf("4.RSA_PKCS1_OAEP_PADDING\n");
    
    scanf("%d",&padding);
    flen=RSA_size(r);
    
    if(padding==RSA_PKCS1_PADDING)
        flen-=11;
    else if(padding==RSA_SSLV23_PADDING)
        flen-=11;
    else if(padding==RSA_X931_PADDING)
        flen-=2;
    else if(padding==RSA_NO_PADDING)
        flen=flen;
    else if(padding==RSA_PKCS1_OAEP_PADDING)
        flen=flen-2 * SHA_DIGEST_LENGTH-2 ;
    else
    {
        printf("rsa not surport !\n");
        return -1;
    }
    
    for(i=0;i<flen;i++)
        memset(&from[i],i+1,1);
    
    len=RSA_public_encrypt(flen,from,to,r,padding);
    if(len<=0)
    {
        printf("RSA_public_encrypt err!\n");
        return -1;
    }

    printf("-------------------------------------------------out\n");
    for(i=0;i<len;i++)
        printf("%2d ", out[i]);
    printf("\n");

    RED_START;
    printf("-------------------------------------------------from\n");
    for(i=0;i<len;i++)
        printf("%2d ", from[i]);
    printf("\n");

    printf("-------------------------------------------------to\n");
    for(i=0;i<len;i++)
        printf("%2d ", to[i]);
    printf("\n");
    RED_END;
    
    len=RSA_private_decrypt(len,to,out,r,padding);
    if(len<=0)
    {
        printf("RSA_private_decrypt err!\n");
        return -1;
    }
    if(memcmp(from,out,flen))
    {
        printf("err!\n");
        return -1;
    }
    
    RED_START;
    printf("-------------------------------------------------out\n");
    for(i=0;i<len;i++)
        printf("%2d ", out[i]);
    printf("\n");
    RED_END;
    
    printf("-------------------------------------------------from\n");
    for(i=0;i<len;i++)
        printf("%2d ", from[i]);
    printf("\n");

    printf("-------------------------------------------------to\n");
    for(i=0;i<len;i++)
        printf("%2d ", to[i]);
    printf("\n");
    

    
    printf("test ok!\n");
    RSA_free(r);
    return 0;
}

//原书中提及的这个错误这里没有发生，荣涛 2020.01.17
//上述程序中当采用公钥 RSA_SSLV23_PADDING 加密，用私钥RSA_SSLV23_PADDING
//    解密时会报错，原因是openssl 源代码错误：
//    rsa_ssl.c 函数RSA_padding_check_SSLv23 有：
//    if (k == -1) /* err */
//    {
//    RSAerr(RSA_F_RSA_PADDING_CHECK_SSLV23,RSA_R_SSLV3_ROLLBACK_ATTA
//    CK);
//    return (-1);
//    }
//    修改为 k!=-1 即可。
//    各种 padding 对输入数据长度的要求：
//    私钥加密：
//    RSA_PKCS1_PADDING RSA_size-11
//    RSA_NO_PADDING RSA_size-0
//    RSA_X931_PADDING RSA_size-2
//    公钥加密
//    RSA_PKCS1_PADDING RSA_size-11
//    RSA_SSLV23_PADDING RSA_size-11
//    RSA_X931_PADDING RSA_size-2
//    RSA_NO_PADDING RSA_size-0
//    RSA_PKCS1_OAEP_PADDING RSA_size-2 * SHA_DIGEST_LENGTH-2


