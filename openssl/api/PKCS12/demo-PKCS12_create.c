//：采用 PKCS12_create 函数：
#include <openssl/pkcs12.h>
#include <openssl/pkcs7.h>
int main()
{
    int ret,len,key_usage,iter,key_nid;
    PKCS12 *p12;
    PKCS7 *p7;
    STACK_OF(PKCS7) *safes;
    STACK_OF(PKCS12_SAFEBAG) *bags;
    PKCS12_SAFEBAG *bag;
    FILE *fp;
    unsigned char *buf,*p,tmp[5000];
    X509 *cert=NULL;
    EVP_PKEY *pkey=NULL;
    OpenSSL_add_all_algorithms();
    fp=fopen("time.cer","rb");
    len=fread(tmp,1,5000,fp);
    fclose(fp);
    p=tmp;
    /* cert */
    d2i_X509(&cert,&p,len);
    /* private key */
    fp=fopen("prikey.cer","rb");
    len=fread(tmp,1,5000,fp);
    fclose(fp);
    p=tmp;
    pkey=d2i_PrivateKey(EVP_PKEY_RSA,NULL,&p,len);
    p12=PKCS12_create("ossl","friend name",pkey,cert,NULL,
                    NID_pbe_WithSHA1And3_Key_TripleDES_CBC,    NID_pbe_WithSHA1And40BitRC2_CBC,PKCS12_DEFAULT_ITER,
                    -1,KEY_EX);
    len=i2d_PKCS12(p12,NULL);
    buf=p=malloc(len);
    len=i2d_PKCS12(p12,&p);
    fp=fopen("myp12.pfx","wb");
    fwrite(buf,1,len,fp);
    fclose(fp);
    printf("ok\n");
    return 0;
}


