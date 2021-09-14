#include <string.h>
#include <openssl/x509.h>
int main()
{
    X509_SIG *sig;
    unsigned char data[50]={"123456789"};
    unsigned char dgst[20];
    int len;
    unsigned char *buf,*p;
    FILE *fp;
    SHA1(data,strlen(data),dgst);
    sig=X509_SIG_new();
    /* sig->algor->algorithm 不是动态分配的，所有不需要释放
    ASN1_OBJECT_free(sig->algor->algorithm); */
    sig->algor->algorithm=OBJ_nid2obj(NID_sha1);
    ASN1_OCTET_STRING_set(sig->digest,dgst,20);
    len=i2d_X509_SIG(sig,NULL);
    p=buf=malloc(len);
    len=i2d_X509_SIG(sig,&p);
    fp=fopen("sig.cer","wb");
    fwrite(buf,1,len,fp);
    fclose(fp);
    free(buf);
    X509_SIG_free(sig);
    return 0;
}

