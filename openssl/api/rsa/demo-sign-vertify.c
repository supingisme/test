//签名与验证
//签名运算：
#include <string.h>
#include <openssl/objects.h>
#include <openssl/rsa.h>

#define RED_START   printf("\033[1;31m");
#define RED_END     printf("\033[m");


int main()
{
    int ret;
    RSA *r;
    int i,bits=1024,signlen,datalen,alg,nid;
    unsigned long e=RSA_3;
    BIGNUM *bne;
    unsigned char data[100],signret[200];
    bne=BN_new();
    ret=BN_set_word(bne,e);
    r=RSA_new();
    ret=RSA_generate_key_ex(r,bits,bne,NULL);
    if(ret!=1)
    {
        printf("RSA_generate_key_ex err!\n");
        return -1;
    }
    for(i=0;i<100;i++)
        memset(&data[i],i+1,1);

    printf("please select digest alg: \n");
    printf("1.NID_md5\n");
    printf("2.NID_sha\n");
    printf("3.NID_sha1\n");
    printf("4.NID_md5_sha1\n");
    
    scanf("%d",&alg);

    if(alg==1)
    {
        datalen=55;
        nid=NID_md5;
    }
    else if(alg==2)
    {
        datalen=55;
        nid=NID_sha;
    }
    else if(alg==3)
    {
        datalen=55;
        nid=NID_sha1;
    }
    else if(alg==4)
    {
        datalen=36;
        nid=NID_md5_sha1;
    }

    RED_START;
    printf("---------------------------data\n");
    for(i=0;i<100;i++)
        printf("%2d ",data[i]);
    printf("\n");
    printf("---------------------------signret\n");
    for(i=0;i<200;i++)
        printf("%c ",signret[i]);
    printf("\n");
    RED_END;
    
    ret=RSA_sign(nid,data,datalen,signret,&signlen,r);
    if(ret!=1)
    {
        printf("RSA_sign err!\n");
        RSA_free(r);
        return -1;
    }

    RED_START;
    printf("---------------------------data\n");
    for(i=0;i<100;i++)
        printf("%2d ",data[i]);
    printf("\n");
    printf("---------------------------signret\n");
    for(i=0;i<200;i++)
        printf("%c ",signret[i]);
    printf("\n");
    RED_END;
    
    ret=RSA_verify(nid,data,datalen,signret,signlen,r);
    if(ret!=1)
    {
        printf("RSA_verify err!\n");
        RSA_free(r);
        return -1;
    }

    RED_START;
    printf("---------------------------data\n");
    for(i=0;i<100;i++)
        printf("%2d ",data[i]);
    printf("\n");
    printf("---------------------------signret\n");
    for(i=0;i<200;i++)
        printf("%c ",signret[i]);
    printf("\n");
    RED_END;
    
    RSA_free(r);
    printf("test ok!\n");
    return 0;
}

//注意：本示例并不是真正的数据签名示例，因为没有做摘要计算。
//
//ret=RSA_sign(nid,data,datalen,signret,&signlen,r)将需要运算的数据放入X509_ALGOR
    //数据结构并将其DER 编码，对编码结果做RSA_PKCS1_PADDING 再进行私钥加密。
    //被签名数据应该是摘要之后的数据，而本例没有先做摘要，直接将数据拿去做运算。因
    //此datalen 不能太长，要保证RSA_PKCS1_PADDING 私钥加密运算时输入数据的长度限制。
//ret=RSA_verify(nid,data,datalen,signret,signlen,r)用来验证签名。

