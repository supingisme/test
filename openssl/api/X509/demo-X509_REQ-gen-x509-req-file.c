//生成证书请求文件

#include <string.h>
#include <openssl/x509.h>
#include <openssl/rsa.h>
int main()
{
    X509_REQ *req;
    int ret;
    long version;
    X509_NAME *name;
    EVP_PKEY *pkey;
    RSA *rsa;
    X509_NAME_ENTRY *entry=NULL;
    char bytes[100],mdout[20];
    int len,mdlen;
    int bits=512;
    unsigned long e=RSA_3;
    unsigned char *der,*p;
    
    FILE *fp;
    const EVP_MD *md;
    X509 *x509;
    BIO *b;
    STACK_OF(X509_EXTENSION) *exts;

    req=X509_REQ_new();
    version=1;
    ret=X509_REQ_set_version(req,version);//设置证书请求信息的版本，此函数调用ASN1_INTEGER_set 函数来完成。
    name=X509_NAME_new();
    strcpy(bytes,"openssl");
    len=strlen(bytes);
    entry=X509_NAME_ENTRY_create_by_txt(&entry,"commonName",V_ASN1_UTF8STRING,(unsigned char *)bytes,len);
    X509_NAME_add_entry(name,entry,0,-1);
    
    strcpy(bytes,"bj");
    len=strlen(bytes);
    entry=X509_NAME_ENTRY_create_by_txt(&entry,"countryName",V_ASN1_UTF8STRING,bytes,len);

    X509_NAME_add_entry(name,entry,1,-1);

    /* subject name */
    ret=X509_REQ_set_subject_name(req,name);

    /* pub key */
    pkey=EVP_PKEY_new();
    rsa=RSA_generate_key(bits,e,NULL,NULL);
    EVP_PKEY_assign_RSA(pkey,rsa);
    ret=X509_REQ_set_pubkey(req,pkey);
    
    /* attribute */
    strcpy(bytes,"test");
    len=strlen(bytes);
    ret=X509_REQ_add1_attr_by_txt(req,"organizationName",V_ASN1_UTF8STRING,bytes,len);
    
    strcpy(bytes,"ttt");
    len=strlen(bytes);
    ret=X509_REQ_add1_attr_by_txt(req,"organizationalUnitName",V_ASN1_UTF8STRING,bytes,len);
    
    md=EVP_sha1();
    
    ret=X509_REQ_digest(req,md,mdout,&mdlen);
    ret=X509_REQ_sign(req,pkey,md);
    if(!ret)
    {
        printf("sign err!\n");
        X509_REQ_free(req);
        return -1;
    }

    /* 写入文件PEM 格式 */
    b=BIO_new_file("certreq.txt","w");
    PEM_write_bio_X509_REQ(b,req,NULL,NULL);
    BIO_free(b);
    
    /* DER编码 */
    len=i2d_X509_REQ(req,NULL);
    der=malloc(len);
    p=der;
    len=i2d_X509_REQ(req,&p);
    
    OpenSSL_add_all_algorithms();

    ret=X509_REQ_verify(req,pkey);
    if(ret<0)
    {
        printf("verify err.\n");
    }
    
    fp=fopen("certreq2.txt","wb");
    fwrite(der,1,len,fp);
    fclose(fp);

    free(der);
    X509_REQ_free(req);

    return 0;
}
//本例用于生成一个证书请求文件，并测试了 X509_REQ_verify 和X509_REQ_digest 等
//函数。

