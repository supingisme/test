//enveloped本例用于生成 enveloped 类型的pkcs7 消息。

#include <openssl/pkcs7.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
int main()
{
    PKCS7 *p7;
    int len;

    char *der,*p;
    FILE *fp;
    PKCS7_RECIP_INFO *inf;
    p7=PKCS7_new();
    PKCS7_set_type(p7,NID_pkcs7_enveloped);
    ASN1_INTEGER_set(p7->d.enveloped->version,3);
    inf=PKCS7_RECIP_INFO_new();
    ASN1_INTEGER_set(inf->version,4);
    ASN1_INTEGER_set(inf->issuer_and_serial->serial,888888);
    inf->key_enc_algor->algorithm=OBJ_nid2obj(NID_des_ede3_cbc);
    ASN1_OCTET_STRING_set(inf->enc_key,(const unsigned char *)"key info....",12);
    sk_PKCS7_RECIP_INFO_push(p7->d.enveloped->recipientinfo,inf);
    p7->d.enveloped->enc_data->algorithm->algorithm=OBJ_nid2obj(NID_des_ede3_cbc);
    p7->d.enveloped->enc_data->enc_data=ASN1_OCTET_STRING_new();
    ASN1_OCTET_STRING_set(p7->d.enveloped->enc_data->enc_data,(const unsigned char *)"info....",8);
    len=i2d_PKCS7(p7,NULL);
    der=(char *)malloc(len);
    p=der;
    len=i2d_PKCS7(p7,(unsigned char **)&p);
    fp=fopen("p7_enveloped.cer","wb");
    fwrite(der,1,len,fp);
    fclose(fp);
    PKCS7_free(p7);
    free(der);
    return 0;
}


