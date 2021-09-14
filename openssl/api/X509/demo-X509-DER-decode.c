//DER 解码编程示例如下：
#include <openssl/x509.h>

int main()
{
    X509 *x;
    FILE *fp;
    unsigned char buf[5000],*p;
    int len,ret;
    BIO *b;
    
    /* cert.cer 为DER 编码的数字证书
    用户如果是 windows 系统，可以从IE 中导出一个x509v3 的数字证书作为解析目
    标
    */
    fp=fopen("cert.cer","rb");
    if(!fp) return -1;
    len=fread(buf,1,5000,fp);
    fclose(fp);
    p=buf;
    x=X509_new();
    d2i_X509(&x,(const unsigned char **)&p,len);

    b=BIO_new(BIO_s_file());
    BIO_set_fp(b,stdout,BIO_NOCLOSE);
    
    ret=X509_print(b,x);
    
    BIO_free(b);
    
    X509_free(x);

    return 0;
}

//程序输出：
//Certificate:
//Data:
//Version: 3 (0x2)
//Serial Number:
//06:37:6c:00:aa:00:64:8a:11:cf:b8:d4:aa:5c:35:f4
//Signature Algorithm: md5WithRSAEncryption
//Issuer: CN=Root Agency
//Validity
//Not Before: May 28 22:02:59 1996 GMT
//Not After : Dec 31 23:59:59 2039 GMT
//Subject: CN=Root Agency
//Subject Public Key Info:
//Public Key Algorithm: rsaEncryption
//RSA Public Key: (512 bit)
//Modulus (512 bit):
//00:81:55:22:b9:8a:a4:6f:ed:d6:e7:d9:66:0f:55:
//bc:d7:cd:d5:bc:4e:40:02:21:a2:b1:f7:87:30:85:
//5e:d2:f2:44:b9:dc:9b:75:b6:fb:46:5f:42:b6:9d:
//23:36:0b:de:54:0f:cd:bd:1f:99:2a:10:58:11:cb:
//40:cb:b5:a7:41
//Exponent: 65537 (0x10001)
//X509v3 extensions:
//commonName:
//.GFor Testing Purposes Only Sample Software Publishing Credentials Agency
//2.5.29.1:
//0>.....-...O..a!..dc..0.1.0...U....Root Agency...7l...d......\5.
//Signature Algorithm: md5WithRSAEncryption
//2d:2e:3e:7b:89:42:89:3f:a8:21:17:fa:f0:f5:c3:95:db:62:
//69:5b:c9:dc:c1:b3:fa:f0:c4:6f:6f:64:9a:bd:e7:1b:25:68:
//72:83:67:bd:56:b0:8d:01:bd:2a:f7:cc:4b:bd:87:a5:ba:87:
//20:4c:42:11:41:ad:10:17:3b:8c
//上述示例解码DER 编码的数字证书，X509_print 用于打印数字证书信息。

