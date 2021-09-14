############### 30.1 概述

pkcs12 (个人数字证书标准)用于存放用户证书、crl、用户私钥以及证书链。pkcs12 中的
私钥是加密存放的。

################## 30.2 openss 实现

openssl 的pkcs12 实现在crypto/pkcs12 目录，有如下源码：
􀂾 p12_add.c：处理PKCS12_SAFEBAG，PKCS12_SAFEBAG 用于存放证书和私钥相
关的信息；
􀂾 p12_attr.c：属性处理；
􀂾 p12_crt：生成一个完整的pkcs12；
􀂾 p12_init.c：构造一个pkcs12 数据结构；
􀂾 p12_kiss.c：解析pkcs12 结构，获取证书和私钥等信息；
􀂾 p12_npas：设置新口令；
􀂾 p12_p8e.c：加密处理用户私钥(pkcs8 格式)；
􀂾 p12_p8d.c：解密出用户私钥；
􀂾 pk12err.c：错误处理；
􀂾 p12_asn.c：pkcs12 各个数据结构的DER 编解码实现；
􀂾 p12_crpt.c：pkcs12 的pbe(基于口令的加密)函数；
􀂾 p12_decr.c.c：pkcs12 的pbe 解密；
􀂾 p12_key.c：根据用户口令生成对称密钥；
􀂾 p12_mutl.c：pkcs12 的MAC 信息处理；
􀂾 p12_utl.c：一些通用的函数。


##################### 函数

1) int PKCS12_gen_mac(PKCS12 *p12, const char *pass, int passlen,
unsigned char *mac, unsigned int *maclen)
生成MAC 值，pass 为用户口令，passlen 为口令长度，mac 和maclen 用于存
放MAC 值。当p12 中pkcs7 为数据类型时，本函数有效。
2） int PKCS12_verify_mac(PKCS12 *p12, const char *pass, int passlen)
验证pkcs12 的MAC，pass 为用户口令，passlen 为口令长度。PKCS12 的MAC
值存放在p12-> mac-> dinfo->digest 中。本函数根据pass 和passlen 调用
PKCS12_gen_mac 生成一个MAC 值，与p12 中已有的值进行比较。
3） PKCS12_create
成PKCS12 数据结构。
4） PKCS12_parse
解析 PKCS12，得到私钥和证书等信息。
5) PKCS12_key_gen_asc/PKCS12_key_gen_uni
生成pkcs12 密钥，输入口令为ASCII 码/UNICODE。
6）unsigned char * PKCS12_pbe_crypt(X509_ALGOR *algor, const char *pass,
int passlen, unsigned char *in, int inlen, unsigned char **data,
int *datalen, int en_de)
PKCS12 加解密，algor 为对称算法，pass 为口令，passlen 为口令长度，in 为
输入数据，inlen 为输入数据长度，data 和datalen 用于存放结果，en_de 用于指明
时加密还是解密。
7） PKCS7 *PKCS12_pack_p7data(STACK_OF(PKCS12_SAFEBAG) *sk)
打包 PKCS12_SAFEBAG 堆栈，生成PKCS7 数据结构并返回。
8） PKCS12_unpack_p7data
上面函数的逆过程。
9) PKCS12_pack_p7encdata
将 PKCS12_SAFEBAG 堆栈根据pbe 算法、口令和salt 加密，生成pkcs7 并返回。
10）PKCS12_unpack_p7encdata
上述过程的逆过程。
11) int PKCS12_newpass(PKCS12 *p12, char *oldpass, char *newpass)
替换 pkcs12 的口令。
12）PKCS12_setup_mac
设置 pkcs12 的MAC 数据结构。
13）PKCS12_set_mac
设置 pkcs12 的MAC 信息。
14）PKCS12_pack_authsafes
将 pkcs7 堆栈信息打包到pkcs12 中。
15）PKCS12_unpack_authsafes
上面函数的逆过程，从 pkcs12 中解出pkcs7 堆栈，并返回。
16）PKCS12 *PKCS12_init(int mode)
生成一个pkcs12 数据结构，mode 的值必须为NID_pkcs7_data，即pkcs12 中的pkcs7
类型必须是data 类型。
17）PKCS12_PBE_add
加载各种 pbe 算法。
18）PKCS12_PBE_keyivgen
根据口令生成对称密钥，并做加解密初始化。
19）PKCS12_item_pack_safebag
将输入的数据打包为 PKCS12_SAFEBAG 并返回。
20）PKCS12_x5092certbag
将证书打包为 PKCS12_SAFEBAG 并返回。
21）PKCS12_certbag2x509
上述过程的逆过程。
22）PKCS12_x509crl2certbag
将 crl 打包为PKCS12_SAFEBAG 并返回。
23）PKCS12_certbag2x509crl
上述过程的逆过程。
24）PKCS12_item_i2d_encrypt
将数据结构 DER 编码，然后加密，数据存放在ASN1_OCTET_STRING 中并返回。
24）PKCS12_item_decrypt_d2i
上面函数的逆过程，解密输入数据，然后 DER 解码出数据结构，并返回。
25）int PKCS12_add_friendlyname_uni(PKCS12_SAFEBAG *bag,
const unsigned char *name, int namelen)
给PKCS12_SAFEBAG 添加一个属性，属性类型为NID_friendlyName，name 为
unicode 编码。
26）int PKCS12_add_friendlyname_asc(PKCS12_SAFEBAG *bag, const char *name,
int namelen)
给PKCS12_SAFEBAG 添加一个属性，属性类型为NID_friendlyName，name
为ASCII 码。
27) PKCS12_get_friendlyname
上面函数的逆过程，返回一个 ASCII 码值。
28）PKCS12_add_CSPName_asc
给 PKCS12_SAFEBAG 添加一个NID_ms_csp_name 属性，输入参数为ASCII 码。
29）PKCS12_add_localkeyid
给 PKCS12_SAFEBAG 添加一个NID_localKeyID 属性。
30）PKCS12_MAKE_SHKEYBAG
将 pkcs8 密钥转化为PKCS12_SAFEBAG。
30）PKCS8_PRIV_KEY_INFO *
PKCS12_decrypt_skey(PKCS12_SAFEBAG *bag, const char *pass,
int passlen)
上面函数的逆过程，从 bag 中提取pkcs8 密钥信息。




