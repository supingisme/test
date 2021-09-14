//该结构用于检查证书用途，它定义在x509v3.h 中，如下：
typedef struct x509_purpose_st
{
    int purpose;
    int trust;
    int flags;
    int (*check_purpose)(const struct x509_purpose_st *,const X509 *, int);
    char *name;
    char *sname;
    void *usr_data;
} X509_PURPOSE;
//purpose 为证书用途ID，check_purpose 为检查证书用途函数。基本的用途ID 在x509v3.h
//中定义，如下：
#define X509_PURPOSE_SSL_CLIENT 1
#define X509_PURPOSE_SSL_SERVER 2
#define X509_PURPOSE_NS_SSL_SERVER 3
#define X509_PURPOSE_SMIME_SIGN 4
#define X509_PURPOSE_SMIME_ENCRYPT 5
#define X509_PURPOSE_CRL_SIGN 6
#define X509_PURPOSE_ANY 7
#define X509_PURPOSE_OCSP_HELPER 8
//Openssl 在x509v3/v3_purp.c 中维护了两个表，用来检查各种证书用途
//标准表：
static X509_PURPOSE xstandard[] = {
{X509_PURPOSE_SSL_CLIENT, X509_TRUST_SSL_CLIENT, 0,
check_purpose_ssl_client, "SSL client", "sslclient", NULL},
{X509_PURPOSE_SSL_SERVER, X509_TRUST_SSL_SERVER, 0,
check_purpose_ssl_server, "SSL server", "sslserver", NULL},
{X509_PURPOSE_NS_SSL_SERVER, X509_TRUST_SSL_SERVER, 0,
check_purpose_ns_ssl_server, "Netscape SSL server", "nssslserver", NULL},
{X509_PURPOSE_SMIME_SIGN, X509_TRUST_EMAIL, 0,
check_purpose_smime_sign, "S/MIME signing", "smimesign", NULL},
{X509_PURPOSE_SMIME_ENCRYPT, X509_TRUST_EMAIL, 0,
check_purpose_smime_encrypt, "S/MIME encryption", "smimeencrypt", NULL},
{X509_PURPOSE_CRL_SIGN, X509_TRUST_COMPAT, 0, check_purpose_crl_sign,
"CRL signing", "crlsign", NULL},
{X509_PURPOSE_ANY, X509_TRUST_DEFAULT, 0, no_check, "Any Purpose",
"any", NULL},
{X509_PURPOSE_OCSP_HELPER, X509_TRUST_COMPAT, 0, ocsp_helper, "OCSP
helper", "ocsphelper", NULL},
};
//扩展表：
static STACK_OF(X509_PURPOSE) *xptable = NULL;
//扩展表由用户通过X509_PURPOSE_add 函数来添加。
//当用户需要检查某个证书用途时，先查表，找到对应的 X509_PURPOSE，然后调用其
//check_purpose 函数来判断证书用途是否合法。
//检查证书用途的函数为 int X509_check_purpose(X509 *x, int id, int ca)，该函数用于检查
//证书的用途。x 为待检查待证书，id 为证书用途NID，ca 表明x 是否是ca 证书。

//##### 主要函数

//1） X509_STORE_add_cert
//将证书添加到X509_STORE 中。
//2) X509_STORE_add_crl
//将crl 添加到X509_STORE 中。
//3) void X509_STORE_set_flags(X509_STORE *ctx, long flags)
//将flags 赋值给ctx 里面的flags，表明了验证证书时需要验证哪些项。
//4） X509_TRUST_set_default
//设置默认的 X509_TRUST 检查函数。
//5） int X509_verify(X509 *a, EVP_PKEY *r)
//验证证书的签名。
//6） X509_verify_cert
//验证证书，用法可参考 apps/verify.c。
//7） X509_verify_cert_error_string
//根据错误号，获取错误信息。
//8） X509_add1_ext_i2d
//根据具体的扩展项数据结构添加一个扩展项。
//9） X509_add_ext
//X509_EXTENSION 堆栈中，在指定位置添加一项。
//10）X509_ALGOR_dup
//算法拷贝。
//11）X509_alias_get0/X509_alias_set1
//获取/设置别名。
//12）X509_asn1_meth
//获取 X509 的ASN1_METHOD，包括new、free、i2d 和d2i 函数。
//13）X509_certificate_type
//获取证书和公钥类型。
//14）int X509_check_issued(X509 *issuer, X509 *subject);
//检查subject 证书是否由issuer 颁发，如果是则返回X509_V_OK，即0。
//15）X509_check_private_key
//检查私钥与证书中的公钥是否匹配，匹配返回 1。
//16）X509_cmp
//证书比较。
//17) int X509_cmp_current_time(ASN1_TIME *s)
//将s 与当前时间进行比较，返回值小于0 则s 早于当前时间，大于0 则s 晚与
//当前时间。
//18）int X509_cmp_time(ASN1_TIME *ctm, time_t *cmp_time)
//如果 ctm 时间在cmp_time 之后，则返回值大于0。
//19) X509_delete_ext
//删除扩展项堆栈中指定位置的扩展项。
//20）X509_digest
//根据指定的摘要算法对 X509 结构做摘要。
//20) X509_dup
//拷贝函数。
//21）X509_find_by_issuer_and_serial
//根据颁发者的X509_NAME 名称和证书序列号，在X509 堆栈中查找对应的证
//书并返回。
//22) X509_find_by_subject
//从证书堆栈中根据持有者名字查询证书，并返回。
//23）X509_get0_pubkey_bitstr
//获取X509 结构中的DER 编码的公钥信息。
//24）X509_load_cert_crl_file
//加载证书和crl，用于验证证书。
//25）X509_PURPOSE_get0
//根据 X509_PURPOSE 的位置获取对应的X509_PURPOSE。
//26）X509_PURPOSE_get0_name
//获取X509_PURPOSE 的名字。
//27）X509_PURPOSE_get0_sname
//获取 X509_PURPOSE 的别名。
//28）X509_PURPOSE_get_by_id
//根据证书用途ID 获取X509_PURPOSE 在当前数组(xstandard)或堆栈(xptable)
//中的位置，如果没有返回-1。
//29）X509_PURPOSE_get_by_sname
//根据别名获取对应的X509_PURPOSE 在数组或堆栈中的位置。
//30）X509_PURPOSE_get_count
//获取所有的X509_PURPOSE 个数，包括标准的和用户动态添加的。
//31）X509_PURPOSE_get_id
//获取X509_PURPOSE 的ID。
//32) int X509_PURPOSE_set(int *p, int purpose)
//检查是否有purpose 标识的X509_PURPOSE，并将purpose 值写入p。
//33) STACK_OF(X509_EXTENSION) X509v3_add_ext
//(STACK_OF(X509_EXTENSION) **x, X509_EXTENSION *ex, int loc)
//添加扩展项,堆栈操作，将ex 表示的扩展项根据loc 指定的位置插入到
//X509_EXTENSION 堆栈中。
//34) X509v3_delete_ext
//堆栈操作，去除指定位置的扩展项。
//35）int X509V3_EXT_print(BIO *out, X509_EXTENSION *ext,
//unsigned long flag, int indent)
//本函数用于打印单个扩展项，out 为BIO 类型的输出对象,ext 为扩展项,flag 表
//明不支持扩展项的处理方式,indent 表明输出时第一列的位置。
//flag 的值在x509v3.h 中定义，可以有：
//􀂾 #define X509V3_EXT_DEFAULT 0
//打印DER 编码内容，调用M_ASN1_OCTET_STRING_print。
//􀂾 #define X509V3_EXT_ERROR_UNKNOWN (1L << 16)
//打印一行语句。
//􀂾 #define X509V3_EXT_PARSE_UNKNOWN (2L << 16)
//分析扩展项的DER 编码，并打印。
//􀂾 #define X509V3_EXT_DUMP_UNKNOWN (3L << 16)
//打印出DER 编码的内容，调用BIO_dump_indent。
//36）int X509V3_extensions_print(BIO *bp, char *title,
//STACK_OF(X509_EXTENSION) *exts, unsigned long flag, int indent)
//本函数将堆栈中的所有扩展项打印，参数意义同上。
//37) int X509v3_get_ext_by_critical(const STACK_OF(X509_EXTENSION) *sk, int crit,
//int lastpos)
//获取扩展项在堆栈中的位置，crit 表面扩展项是否关键，lastpos 为指定堆栈搜
//索起始位置。此函数从给定的lastpos 开始搜索扩展项堆栈，找到与crit 匹配的扩
//展项后，返回其位置，如果找不到扩展项，返回-1。
//38）int X509v3_get_ext_by_NID(const STACK_OF(X509_EXTENSION) *x, int nid,
//int lastpos)
//获取扩展项在其堆栈中的位置，此函数根据扩展项标识nid 以及堆栈搜索的起
//始进行搜索，如果找到，返回它在堆栈中的位置，如果没找到，返回-1。
//39) int X509v3_get_ext_by_OBJ(const STACK_OF(X509_EXTENSION) *sk,
//ASN1_OBJECT *obj, int lastpos)
//功能同上。
//40）X509_EXTENSION *X509v3_get_ext(const STACK_OF(X509_EXTENSION) *x,
//int loc)
//获取扩展项，loc 为扩展项在堆栈x 中的位置，如果不成功，返回NULL。
//41）int X509v3_get_ext_count(const STACK_OF(X509_EXTENSION) *x)
//获取扩展项的个数，此函数调用堆栈操作sk_X509_EXTENSION_num(x)来获
//取扩展项的个数。
//42）STACK_OF(CONF_VALUE) * X509V3_get_section(X509V3_CTX *ctx, char *section)
//获取配置信息，section 为配置信息中的“段”信息。比如有配置信息如下：
//[CA]
//Name1=A
//Name2=B
//则section 应是”CA”，返回的信息为它包含的内容信息。
//43）char * X509V3_get_string(X509V3_CTX *ctx, char *name, char *section)
//根据段和属性获取值，比如有如下配置信息：
//[CA]
//Name1=A
//Name2=B
//调用此函数时name 为”Name1”,sectionwei “CA”，则返回值为”A”。
//44）int X509V3_get_value_bool(CONF_VALUE *value, int *asn1_bool)
//判断配置信息的布尔值，如果value 表示的值为true、TRUE、y、Y、yes、YES，
//*asn1_bool 的值设为xff，并返回1，如果为false、FALSE、n、N、NO、no, *asn1_bool
//设置为 0，并返回1。此函数调用不成功时返回0。
//45) int X509V3_get_value_int(CONF_VALUE *value, ASN1_INTEGER **aint)
//将value 中的值转换为ASN1_INTEGER 类型，结果存放在**aint 中，函数调
//用成功返回1，否则返回0。
//46）STACK_OF(CONF_VALUE) *X509V3_parse_list(const char *line)
//分析配置信息的一行数据，返回结果。
//

