//如果需要解码PEM 格式的证书，如下例：
#include <openssl/x509.h>
#include <openssl/pem.h>
int main()
{
    X509 *x;
    BIO *b;
    /* cert.cer为PEM 格式的数字证书 */
    b=BIO_new_file("pub.pem","r");
    x=PEM_read_bio_X509(b,NULL,NULL,NULL);
    BIO_free(b);
    X509_free(x);
    return 0;
}
//上例得到 X509 数据结构。

