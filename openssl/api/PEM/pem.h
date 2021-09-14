//openssl 的PEM 实现

//Openssl 的PEM 模块实现位于crypto/pem 目录下，并且还依赖于openssl 的ASN1 模块。
//Openssl 支持的PEM 类型在crypto/pem/pem.h 中定义如下：
#define PEM_STRING_X509_OLD "X509 CERTIFICATE"
#define PEM_STRING_X509 "CERTIFICATE"
#define PEM_STRING_X509_PAIR "CERTIFICATE PAIR"
#define PEM_STRING_X509_TRUSTED "TRUSTED CERTIFICATE"
#define PEM_STRING_X509_REQ_OLD "NEW CERTIFICATE REQUEST"
#define PEM_STRING_X509_REQ "CERTIFICATE REQUEST"
#define PEM_STRING_X509_CRL "X509 CRL"
#define PEM_STRING_EVP_PKEY "ANY PRIVATE KEY"
#define PEM_STRING_PUBLIC "PUBLIC KEY"
#define PEM_STRING_RSA "RSA PRIVATE KEY"
#define PEM_STRING_RSA_PUBLIC "RSA PUBLIC KEY"
#define PEM_STRING_DSA "DSA PRIVATE KEY"
#define PEM_STRING_DSA_PUBLIC "DSA PUBLIC KEY"
#define PEM_STRING_PKCS7 "PKCS7"
#define PEM_STRING_PKCS8 "ENCRYPTED PRIVATE KEY"
#define PEM_STRING_PKCS8INF "PRIVATE KEY"
#define PEM_STRING_DHPARAMS "DH PARAMETERS"
#define PEM_STRING_SSL_SESSION "SSL SESSION PARAMETERS"
#define PEM_STRING_DSAPARAMS "DSA PARAMETERS"
#define PEM_STRING_ECDSA_PUBLIC "ECDSA PUBLIC KEY"
#define PEM_STRING_ECPARAMETERS "EC PARAMETERS"
#define PEM_STRING_ECPRIVATEKEY "EC PRIVATE KEY"

//Openssl 生成PEM 格式文件的大致过程如下：
//    1) 将各种数据DER 编码；
//    2) 将1）中的数据进行加密处理（如果需要）；
//    3) 根据类型以及是否加密，构造PEM 头；
//    4) 将2）中的数据进行BASE64 编码，放入PEM 文件。
//    
//Openssl 各个类型的PEM 处理函数主要是write 和read 函数。write 函数用于生成PEM
//    格式的文件，而read 函数主要用于读取PEM 格式的文件。各种类型的调用类似。
