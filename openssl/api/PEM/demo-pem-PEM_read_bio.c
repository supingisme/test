#include <string.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
int main()
{
    BIO *bp;
    char *name=NULL,*header=NULL;
    unsigned char *data=NULL;
    long int len;
    int ret,ret2;
    EVP_CIPHER_INFO cipher;

    OpenSSL_add_all_algorithms();
    
    bp=BIO_new_file("server2.pem","r");
    while(1)
    {
        ret2=PEM_read_bio(bp,&name,&header,&data,&len);
        printf("data: %s\n", data);
        if(ret2==0)
            break;
        if(strlen(header)>0)
        {
            ret=PEM_get_EVP_CIPHER_INFO(header,&cipher);//根据头信息获取对称算法，并加载初始化向量iv。
            ret=PEM_do_header(&cipher,data,&len,NULL,NULL);//根据对称算法，解密数据。
            if(ret==0)
            {
                printf("PEM_do_header err!\n");
                return -1;
            }
            printf("data: %s\n", data);
        }
        OPENSSL_free(name);
        OPENSSL_free(header);
        OPENSSL_free(data);
    }
    
    printf("test ok.\n");
    BIO_free(bp);
    return 0;
}

//PEM_read_bio函数可以循环读取文件中的内容。
//PEM_do_header 用于解密数据，之前必须调用函数OpenSSL_add_all_algorithms。
//PEM_do_header 解密后的数据放在data 中，长度由len 表示，len 即是输入参数又是输出参数。
//
//name、header 和data 等用OPENSSL_free 释放内存。

/*                  server2.pem

-----BEGIN CERTIFICATE-----
MIIB6TCCAVICAQYwDQYJKoZIhvcNAQEEBQAwWzELMAkGA1UEBhMCQVUxEzARBg
NVBAgTClF1ZWVuc2xhbmQxGjAYBgNVBAoTEUNyeXB0U29mdCBQdHkgTHRkMRswGQ
YDVQQDExJUZXN0IENBICgxMDI0IGJpdCkwHhcNMDAxMDE2MjIzMTAzWhcNMDMwM
TE0MjIzMTAzWjBjMQswCQYDVQQGEwJBVTETMBEGA1UECBMKUXVlZW5zbGFuZDE
aMBgGA1UEChMRQ3J5cHRTb2Z0IFB0eSBMdGQxIzAhBgNVBAMTGlNlcnZlciB0ZXN0IG
NlcnQgKDUxMiBiaXQpMFwwDQYJKoZIhvcNAQEBBQADSwAwSAJBAJ+zw4Qnlf8SMVIP
Fe9GEcStgOY2Ww/dgNdhjeD8ckUJNP5VZkVDTGiXav6ooKXfX3j/7tdkuD8Ey2//Kv7+ue0CA
wEAATANBgkqhkiG9w0BAQQFAAOBgQCT0grFQeZaqYb5EYfk20XixZV4GmyAbXMftG1E
o7qGiMhYzRwGNWxEYojf5PZkYZXvSqZ/ZXHXa4g59jK/rJNnaVGMk+xIX8mxQvlV0n5O9P
Iha5BX5teZnkHKgL8aKKLKW1BK7YTngsfSzzaeame5iKfzitAE+OjGF+PFKbwX8Q==
-----END CERTIFICATE-----

-----BEGIN RSA PRIVATE KEY-----
Proc-Type: 4,ENCRYPTED
DEK-Info: DES-EDE3-CBC,8FDB648C1260EDDA
CPdURB7aZqM5vgDzZoim/qtoLi5PdrrJol9LrH7CNqJfr9kZfmiexZrE4pV738Hh
UBoidqT8moxzDtuBP54FaVri1IJgbuTZPiNbLn00pVcodHdZrrttrjy1eWLlFmN/QcCRQhIo
Row+f1AhYGhsOhVH+m4fRb8P9KXpPbEDYVcG0R0EQq6ejdmhS0vV+YXGmghBSGH12i3
OfRJXC0TXvazORsT322jiVdEmajND6+DpAtmMmn6JTYm2RKwgFr9vPWv9cRQaMP1yrrBC
tMiSINS4mGieN1sE1IvZLhn+/QDNfS4NxgnMfFjSl26TiNd/m29ZNoeDDXEcc6HXhoS/PiT+zP
Bq7t23hmAroqTVehV9YkFsgr71okOTBwlYMbFJ9goC87HYjJo4t0q9IY53GCuoI1Mont3Wm9I
8QlWh2tRq5uraDlSq7U6Z8fwvC2O+wFF+PhRJrgD+4cBETSQJhj7ZVrjJ8cxCbtGcE/QiZTmmy
Y3sirTlUnIwpKtlfOa9pwBaoL5hKk9ZYa8L1ZCKKMoB6pZw4N9OajVkMUtLiOv3cwIdZk4OI
FSSm+pSfcfUdG45a1IQGLoqvt9svckz1sOUhuu5zDPIQUYrHFn3arqUO0zCPVWPMm9oeYOk
B2WCz/OiNhTFynyX0r+Hd3XeT26lgFLfnCkZlXiW/UQXqXQFSjC5sWd5XJ1+1ZgAdXq0L5q
v/vAIrfryNNZHRFxC8QDDI504OA1AHDkHuH9NO9Ur8U0z7qrsUAf5OnMRUK//QV11En5o/
pWcZKD0SVGS03+FVqMhtTsWKzsil5CLAfMbOWUw+/1k1A==
-----END RSA PRIVATE KEY-----

*/
