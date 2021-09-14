//签名与验证
#include <string.h>
#include <openssl/objects.h>
#include <openssl/dsa.h>


#define RED_START   printf("\033[1;31m");
#define RED_END     printf("\033[m");

int main()
{
    int ret;
    DSA *d;
    int i,bits=1024,signlen,datalen,alg,nid;
    unsigned char data[100],signret[200];
    d=DSA_new();
    ret=DSA_generate_parameters_ex(d,512,NULL,0,NULL,NULL,NULL);
    if(ret!=1)
    {
        DSA_free(d);
        return -1;
    }
    ret=DSA_generate_key(d);
    if(ret!=1)
    {
        DSA_free(d);
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
        datalen=20;
        nid=NID_md5;
    }
    else if(alg==2)
    {
        datalen=20;
        nid=NID_sha;
    }
    else if(alg==3)
    {
        datalen=20;
        nid=NID_sha1;
    }
    else if(alg==4)
    {
        datalen=20;
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
    
    ret=DSA_sign(nid,data,datalen,signret,&signlen,d);
    if(ret!=1)
    {
        printf("DSA_sign err!\n");
        DSA_free(d);
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
    
    ret=DSA_verify(nid,data,datalen,signret,signlen,d);
    if(ret!=1)
    {
        printf("DSA_verify err!\n");
        DSA_free(d);
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
    
    DSA_free(d);
    printf("test ok!\n");
    return 0;
}


