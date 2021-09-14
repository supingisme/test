//生成pkcs12 证书
//之一：
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
    p12=PKCS12_init(NID_pkcs7_data);
    /*
    p12->mac=PKCS12_MAC_DATA_new();
    p12->mac->dinfo->algor->algorithm=OBJ_nid2obj(NID_sha1);
    ASN1_STRING_set(p12->mac->dinfo->digest,"aaa",3);
    ASN1_STRING_set(p12->mac->salt,"test",4);
    p12->mac->iter=ASN1_INTEGER_new();
    ASN1_INTEGER_set(p12->mac->iter,3);
    */
    /* pkcs7 */
    bags=sk_PKCS12_SAFEBAG_new_null();
    fp=fopen("time.cer","rb");
    len=fread(tmp,1,5000,fp);
    fclose(fp);
    p=tmp;
    /* cert */
    d2i_X509(&cert,&p,len);
    bag=PKCS12_x5092certbag(cert);
    sk_PKCS12_SAFEBAG_push(bags,bag);
    /* private key */
    fp=fopen("prikey.cer","rb");
    len=fread(tmp,1,5000,fp);
    fclose(fp);
    p=tmp;
    pkey=d2i_PrivateKey(EVP_PKEY_RSA,NULL,&p,len);
    PKCS12_add_key(&bags,pkey,KEY_EX,PKCS12_DEFAULT_ITER,NID_pbe_WithSHA1And3_Key_TripleDES_CBC,"openssl");
    p7=PKCS12_pack_p7data(bags);
    safes=sk_PKCS7_new_null();
    sk_PKCS7_push(safes,p7);
    ret=PKCS12_pack_authsafes(p12,safes);
    len=i2d_PKCS12(p12,NULL);
    buf=p=malloc(len);
    len=i2d_PKCS12(p12,&p);
    fp=fopen("myp12.pfx","wb");
    fwrite(buf,1,len,fp);
    fclose(fp);
    printf("ok\n");
    return 0;
}





