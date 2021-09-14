//digest
#include <openssl/pkcs7.h>
#include <openssl/objects.h>
#include <openssl/pem.h>
int main()
{
    PKCS7 *p7;
    int ret;
    BIO *b;
    p7=PKCS7_new();
    ret=PKCS7_set_type(p7,NID_pkcs7_digest);
    b=BIO_new_file("p7_digest.pem","w");
    PEM_write_bio_PKCS7(b,p7);
    BIO_free(b);
    PKCS7_free(p7);
    return 0;
}
//本例用于生成 digest 类型的pkcs7 消息,并以PEM 格式存储。

//[root@localhost api]# ./compile.sh PKCS7/demo-digest.c 
//[root@localhost api]# ./a.out 
//[root@localhost api]# more p7_d
//p7_data.cer    p7_digest.pem  
//[root@localhost api]# more p7_digest.pem 
//-----BEGIN PKCS7-----
//MBwGCSqGSIb3DQEHBaAPMA0CAQAwAgYAMAIGAAQA
//-----END PKCS7-----


