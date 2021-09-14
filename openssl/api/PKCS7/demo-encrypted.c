//encrypted
#include <openssl/pkcs7.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
int main()
{
    PKCS7 *p7;
    int ret,len;
    char *der,*p;
    FILE *fp;
    p7=PKCS7_new();
    ret=PKCS7_set_type(p7,NID_pkcs7_encrypted);
    ASN1_INTEGER_set(p7->d.encrypted->version,3);
    p7->d.encrypted->enc_data->algorithm->algorithm=OBJ_nid2obj(NID_des_ede3_cbc);
    p7->d.encrypted->enc_data->enc_data=ASN1_OCTET_STRING_new();
    ASN1_OCTET_STRING_set(p7->d.encrypted->enc_data->enc_data,(const unsigned char *)"3434",4);
    len=i2d_PKCS7(p7,NULL);
    der=(char *)malloc(len);
    p=der;
    len=i2d_PKCS7(p7,(unsigned char **)&p);
    fp=fopen("p7_enc.cer","wb");
    fwrite(der,1,len,fp);
    fclose(fp);
    PKCS7_free(p7);
    free(der);
    return 0;
}
//本例用于生成 encrypted 类型的pkcs7 消息。
