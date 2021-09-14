################ 29.1 概述

加密消息语法（pkcs7），是各种消息存放的格式标准。这些消息包括：数据、签名数据、
数字信封、签名数字信封、摘要数据和加密数据。

################# 函数

1) PKCS7_add_attrib_smimecap
给 PKCS7_SIGNER_INFO 添加NID_SMIMECapabilities 属性。
2） int PKCS7_add_attribute(PKCS7_SIGNER_INFO *p7si, int nid, int atrtype,void
*value)
给PKCS7_SIGNER_INFO 添加属性，nid 为属性类型，value 为属性的ASN1 数据
结构，atrtype 为value 的ASN1 类型。
3） int PKCS7_add_certificate(PKCS7 *p7, X509 *x509)
将证书添加到PKCS7 对应消息的证书堆栈中， 只对NID_pkcs7_signed 和
NID_pkcs7_signedAndEnveloped 两种类型有效。
4） PKCS7_add_crl
将crl 添加到PKCS7 对应消息的crl 堆栈中， 只对NID_pkcs7_signed 和
NID_pkcs7_signedAndEnveloped 两种类型有效。
5） PKCS7_add_recipient/ PKCS7_add_recipient_info
添加接收者信息。
6）PKCS7_add_signer
添加一个签名者信息。
7） KCS7_add_signed_attribute
给PKCS7_SIGNER_INFO 添加属性。
8） PKCS7_cert_from_signer_info
从pkcs7 消息中根据颁发者和证书序列号获取证书。
9） PKCS7_ctrl
控制函数。
10）PKCS7_dataDecode
解析输入的pkcs7 消息，将结果存入BIO 链表并返回。
11）PKCS7_dataInit/PKCS7_dataFinal
解析输入的pkcs7 消息，将结果存入BIO。
12）PKCS7_dataVerify
验证pkcs7 数据。
13）PKCS7_sign
签名 pkcs7 消息。
14) PKCS7_verify
验证 pkcs7 消息。
15）PKCS7_set_type
设置 pkcs7 消息类型。
16）PKCS7_dup
拷贝 pkcs7 结构。

############# 消息编解码

PKCS7编码时调用函数i2d_PKCS7，在调用此函数之前，需要填充其内部数据结
构。PKCS7 解码时调用函数d2i_PKCS7 获取内部数据结构。
