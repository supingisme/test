//X509_CERT_AUX
//该结构定义在x509.h 中，如下：
typedef struct x509_cert_aux_st
{
    STACK_OF(ASN1_OBJECT) *trust;
    STACK_OF(ASN1_OBJECT) *reject;
    ASN1_UTF8STRING *alias;
    ASN1_OCTET_STRING *keyid;
    STACK_OF(X509_ALGOR) *other;
} X509_CERT_AUX;
//该结构是 X509 的一项，用于决定一个证书是否受信任。trust 堆栈中存放了受信任的
//ASN1_OBJECT ， reject 堆栈中存放了应该拒绝的ASN1_OBJECT 。trust 堆栈通过
//X509_add1_trust_object 函数来存放一个可信的ASN1_OBJECT ， reject 堆栈通过
//X509_add1_reject_object 来存放一个应该拒绝的ASN1_OBJECT 。这两个堆栈在
//x509/x509_trs.c 的obj_trust 函数中使用。obj_trust 函数是默认的check_trust 函数。
//上述两个结构在证书验证中的作用如下：
//􀂾 在 X509 结构中构造X509_CERT_AUX；
//􀂾 调用 X509_add1_trust_object 和X509_add1_reject_object，将受信任和要拒绝的
//ASN1_OBJECT 添加到X509_CERT_AUX 的两个堆栈中；
//􀂾 验证证书时，如果要验证某个ASN1_OBJECT 是否受信任，查表找到相应的
//check_trust ， 进行计算。如果对应的项在标准表trstandard 中， 除了
//X509_TRUST_COMPAT(检查证书用途)都会调用obj_trust 函数。
