#include <string.h>
#include <openssl/evp.h>


int main()
{
    int cnid,ret,i,msize,mtype;
    int mpktype,cbsize,mnid,mbsize;
    const EVP_CIPHER *type;
    const EVP_MD *md;
    int datal,count,keyl,ivl;
    unsigned char salt[20],data[100],*key,*iv;
    const char *cname,*mname;
    
    type=EVP_des_ecb();
    cnid=EVP_CIPHER_nid(type);
    cname=EVP_CIPHER_name(type);
    cbsize=EVP_CIPHER_block_size(type);
    
    printf("encrypto nid : %d\n",cnid);
    printf("encrypto name: %s\n",cname);
    printf("encrypto bock size : %d\n",cbsize);
    
    md=EVP_md5();
    mtype=EVP_MD_type(md);
    mnid=EVP_MD_nid(md);
    mname=EVP_MD_name(md);
    mpktype=EVP_MD_pkey_type(md);
    msize=EVP_MD_size(md);
    mbsize=EVP_MD_block_size(md);
    
    printf("md info>>>>>\n");
    printf("md type : %d\n",mtype);
    printf("md nid : %d\n",mnid);
    printf("md name : %s\n",mname);
    printf("md pkey type : %d\n",mpktype);
    printf("md size : %d\n",msize);
    printf("md block size : %d\n",mbsize);
    
    keyl=EVP_CIPHER_key_length(type);
    key=(unsigned char *)malloc(keyl);
    ivl=EVP_CIPHER_iv_length(type);
    iv=(unsigned char *)malloc(ivl);
    
    for(i=0;i<100;i++)
        memset(&data[i],i,1);
    for(i=0;i<20;i++)
        memset(&salt[i],i,1);

    datal=100;
    count=2;

    ret=EVP_BytesToKey(type,md,salt,data,datal,count,key,iv);
    printf("generate key value: \n");
    for(i=0;i<keyl;i++)
        printf("%x ",*(key+i));
    printf("\n");
    printf("generate iv value: \n");
    
    for(i=0;i<ivl;i++)
        printf("%x ",*(iv+i));
    printf("\n");
    
    return 0;
}
//EVP_BytesToKey 函数通过salt 以及data 数据来生成所需要的key 和iv。
//输出：
//    encrypto nid : 29
//    encrypto name: DES-ECB
//    encrypto bock size : 8
//    md info :
//    md type : 4
//    md nid : 4
//    md name : MD5
//    md pkey type : 8
//    md size : 16
//    md block size : 64
//    generate key value:
//    54 0 b1 24 18 42 8d dd
//    generate iv value:
//    ba 7d c3 97 a0 c9 e0 70
//但是我的输出是：
//# ./a.out 
//    encrypto nid : 29
//    encrypto name: DES-ECB
//    encrypto bock size : 8
//    md info : 
//    md type : 4
//    md nid : 4
//    md name : MD5
//    md pkey type : 8
//    md size : 16
//    md block size : 64
//    generate key value: 
//    54 0 b1 24 18 42 8d dd 
//    generate iv value:

