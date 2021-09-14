#include <string.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>

int main()
{
    int ret,inlen,outlen=0;
    unsigned long e=RSA_3;
    char data[100],out[500];
    EVP_MD_CTX md_ctx,md_ctx2;
    EVP_PKEY *pkey;
    RSA *rkey;
    BIGNUM *bne;
    
    /* 待签名数据*/
    strcpy(data,"openssl 编程作者：赵春平");
    
    inlen=strlen(data);
    
    /* 生成RSA 密钥*/
    bne=BN_new();
    ret=BN_set_word(bne,e);
    rkey=RSA_new();

    ret=RSA_generate_key_ex(rkey,1024,bne,NULL);
    if(ret!=1) goto err;
    
    pkey=EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pkey,rkey);

    /* 初始化*/
    EVP_MD_CTX_init(&md_ctx);

    ret=EVP_SignInit_ex(&md_ctx,EVP_md5(), NULL);
    if(ret!=1) goto err;

    ret=EVP_SignUpdate(&md_ctx,data,inlen);
    if(ret!=1) goto err;
    
    ret=EVP_SignFinal(&md_ctx,out,&outlen,pkey);

    /* 验证签名*/
    EVP_MD_CTX_init(&md_ctx2);
    
    ret=EVP_VerifyInit_ex(&md_ctx2,EVP_md5(), NULL);
    if(ret!=1) goto err;

    ret=EVP_VerifyUpdate(&md_ctx2,data,inlen);
    if(ret!=1) goto err;
    
    ret=EVP_VerifyFinal(&md_ctx2,out,outlen,pkey);
    if(ret==1)
        printf("验证成功\n");
    else
        printf("验证错误\n");

err:
    RSA_free(rkey);
    BN_free(bne);
    return 0;
}

