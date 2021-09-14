//X509_TRUST
//X509_TRUST
//该结构定义在crypto/x509v3/x509v3.h 中，如下：
typedef struct x509_trust_st
{
    int trust;
    int flags;
    int (*check_trust)(struct x509_trust_st *, X509 *, int);
    char *name;
    int arg1;
    void *arg2;
} X509_TRUST;
//信任检查数据结构，本结构用来检查数字证书是否是受信任的，其主要的函数实现在
//x509/x509_trs.c 中。其主要项为回调函数check_trust，该函数用于判断证书是受信任的。
//Openssl 在x509_trs.c 中维护了两个表，标准表和扩展表，用于判断特定NID 的信任情
//况。如下：
//标准表：
//static X509_TRUST trstandard[] = {
//{X509_TRUST_COMPAT, 0, trust_compat, "compatible", 0, NULL},
//{X509_TRUST_SSL_CLIENT, 0, trust_1oidany, "SSL Client", NID_client_auth, NULL},
//{X509_TRUST_SSL_SERVER, 0, trust_1oidany, "SSL Server", NID_server_auth, NULL},
//{X509_TRUST_EMAIL, 0, trust_1oidany, "S/MIME email", NID_email_protect, NULL},
//{X509_TRUST_OBJECT_SIGN, 0, trust_1oidany, "Object Signer", NID_code_sign,
//NULL},
//{X509_TRUST_OCSP_SIGN, 0, trust_1oid, "OCSP responder", NID_OCSP_sign, NULL},
//{X509_TRUST_OCSP_REQUEST, 0, trust_1oid, "OCSP request", NID_ad_OCSP, NULL}
//};
//扩展表：
//static STACK_OF(X509_TRUST) *trtable = NULL;
//扩展表通过X509_TRUST_add 函数来添加。当用户需要对某个NID 做判断时，查找这
//两个表，然后通过check_trust 得到结果。

