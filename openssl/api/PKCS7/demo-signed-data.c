//signed data本例用于生成 signed 类型的pkcs7 消息。
    
#include <openssl/pem.h>
#include <openssl/pkcs7.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
int main()
{
    PKCS7 *p7;
    int len;
    unsigned char *der,*p;
    FILE *fp;
    X509 *x;
    BIO *in;
    X509_ALGOR *md;
    PKCS7_SIGNER_INFO *si;
    p7=PKCS7_new();
    PKCS7_set_type(p7,NID_pkcs7_signed);
    p7->d.sign->cert=sk_X509_new_null();
    in=BIO_new_file("b64cert.cer","r");
    x=PEM_read_bio_X509(in,NULL,NULL,NULL);
    sk_X509_push(p7->d.sign->cert,x);
    md=X509_ALGOR_new();
    md->algorithm=OBJ_nid2obj(NID_md5);
    sk_X509_ALGOR_push(p7->d.sign->md_algs,md);
    si=PKCS7_SIGNER_INFO_new();
    ASN1_INTEGER_set(si->version,2);
    ASN1_INTEGER_set(si->issuer_and_serial->serial,333);
    sk_PKCS7_SIGNER_INFO_push(p7->d.sign->signer_info,si);
    len=i2d_PKCS7(p7,NULL);
    der=(unsigned char *)malloc(len);
    p=der;
    len=i2d_PKCS7(p7,&p);
    fp=fopen("p7_sign.cer","wb");
    fwrite(der,1,len,fp);
    fclose(fp);
    free(der);
    PKCS7_free(p7);
    return 0;
}


