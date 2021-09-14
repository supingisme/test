#################### 27.1 概述

	在线证书状态协议（OCSP，Online Certificate Status Protocol，rfc2560）用于实时表明
	证书状态。OCSP 客户端通过查询OCSP 服务来确定一个证书的状态。OCSP 可以通过HTTP
	协议来实现。rfc2560 定义了OCSP 客户端和服务端的消息格式。
	
################# 27.2 openssl 实现

	openssl 在crypto/ocsp 目录实现了ocsp 模块，包括客户端和服务端各种函数。主要
	源码如下：
	􀂾 ocsp_asn.c：ocsp 消息的DER 编解码实现，包括基本的new、free、i2d 和d2i 函数；
	􀂾 ocsp_cl.c：ocsp 客户端函数实现，主要用于生成ocsp 请求；
	􀂾 ocsp_srv.c：ocsp 服务端思想，主要用于生成ocsp 响应；
	􀂾 ocsp_err.c：ocsp 错误处理；
	􀂾 ocsp_ext.c：ocsp 扩展项处理；
	􀂾 ocsp_ht.c：基于HTTP 协议通信的OCSP 实现；
	􀂾 ocsp_lib.c：通用库实现；
	􀂾 ocsp_prn：打印OCSP 信息；
	􀂾 ocsp_vfy：验证ocsp 请求和响应；
	􀂾 ocsp.h：定义了ocsp 请求和响应的各种数据结构和用户接口。
	
############### 27.3 主要函数

	1） d2i_OCSP_REQUEST_bio
	将 bio 中的DER 编码的数据转换为OCSP_REQUEST 数据结构。
	2） d2i_OCSP_RESPONSE_bio
	将bio 中的DER 编码的数据转换为OCSP_RESPONSE 数据结构。
	3） i2d_OCSP_RESPONSE_bio
	将OCSP_RESPONSE 数据结构DER 编码，并输出到BIO 中。
	4） i2d_OCSP_REQUEST_bio
	将OCSP_REQUEST 数据结构DER 编码，并输出到BIO 中。
	5） PEM_read_bio_OCSP_REQUEST
	读取PEM 格式的OCSP_REQUEST 信息，返回其数据结构。
	6） PEM_read_bio_OCSP_RESPONSE
	读取PEM 格式的OCSP_RESPONSE 信息，返回其数据结构。
	7） PEM_write_bio_OCSP_REQUEST
	将OCSP_REQUEST 结构写成PEM 格式。
	8） PEM_write_bio_OCSP_RESPONSE
	将OCSP_RESPONSE 结构写成PEM 格式。
	9） OCSP_REQUEST_sign
	本函数由宏来定义，它用于给OCSP_REQUEST 数据结构签名。签名的对象为
	DER 编码的OCSP_REQINFO 信息，签名算法为OCSP_SIGNATURE 指定的的算
	法，签名私钥以及摘要算法由输入参数指定。
	10）int OCSP_request_sign(OCSP_REQUEST *req,
	X509 *signer,
	EVP_PKEY *key,
	const EVP_MD *dgst,
	STACK_OF(X509) *certs,
	unsigned long flags)
	本函数用于给OCSP 请求消息签名，通过OCSP_REQUEST_sign 函数进行签
	名，将signer 持有者信息写入req，如果flags 不为OCSP_NOCERTS，将certs 信息
	写入req。
	11) OCSP_BASICRESP_sign
	对OCSP_BASICRESP 结构进行签名，签名结果放在OCSP_BASICRESP 的
	signature 中，摘要算法由输入参数指定。
	12）OCSP_REQUEST_verify
	验证 ocsp 请求签名，公钥由输入参数指定。
	13）OCSP_BASICRESP_verify
	验证 ocsp 响应签名，公钥由输入参数指定。
	14）OCSP_request_verify
	验证 ocsp 响应，该函数做全面的验证，包括签名、证书目的以及证书链等。
	15）int OCSP_basic_sign(OCSP_BASICRESP *brsp,X509 *signer, EVP_PKEY *key,
	const EVP_MD *dgst,STACK_OF(X509) *certs, unsigned long flags)
	本函数用输入参数signer、key、dgst、certs 和flags 来填充brsp 数据结构，并
	对brsp 结构签名，成功返回1，否则返回0。
	16) int OCSP_check_validity(ASN1_GENERALIZEDTIME *thisupd,
	ASN1_GENERALIZEDTIME *nextupd, long nsec, long maxsec)
	时间检查计算，合法返回1，thisupd 为本次更新时间，nextupd 为下次更新时
	间。thisupd 和nextupd 由响应服务生成，他们被传给请求者。请求者收到响应之后
	需要验证ocsp 消息的时间有效性。要求如下：
	􀂾 本次更新时间不能比当前时间提前太多，提前时间不能大于 nsec，比如ocsp
	服务器多时间比请求者系统时间快很多，导致thisupd 错误非法；
	􀂾 本次更新时间不能晚于当前时间太多，否则 ocsp 消息失效，晚的时间不能大
	于maxsec；
	􀂾 下次更新时间不能晚于当前时间太多，晚多时间不大于 nsec(由于下一条规则
	限制，也不能大于maxsec)；
	􀂾 下次更新时间必须大于本次更新时间。
	总之，本次更新时间和下次更新时间必须在以当前时间为中心的一个窗口内。
	17）OCSP_CERTID_dup
	复制函数。
	18）OCSP_CERTSTATUS_dup
	复制函数。
	19）OCSP_ONEREQ *OCSP_request_add0_id(OCSP_REQUEST *req,
	OCSP_CERTID *cid)
	本函数用于往请求消息中添加一个证书ID；它将一个OCSP_CERTID 信息存
	入OCSP_REQUEST 结构，返回内部生成的OCSP_ONEREQ 指针。根据cid 构造
	一个OCSP_ONEREQ 信息，并将此信息放入req 请求消息的堆栈。
	20）int OCSP_request_set1_name(OCSP_REQUEST *req, X509_NAME *nm)
	本函数用于设置消息请求者的名字。
	21）int OCSP_request_add1_cert(OCSP_REQUEST *req, X509 *cert)
	本函数往消息请求中添加一个证书。此证书信息放在OCSP_REQUEST 结构的
	一个堆栈中，并将此证书结构的引用加1。
	22）int OCSP_response_status(OCSP_RESPONSE *resp)
	本函数获取 OCSP 响应状态。
	23）OCSP_BASICRESP *OCSP_response_get1_basic(OCSP_RESPONSE *resp)
	本函数从响应数据结构中获取 OCSP_BASICRESP 信息。
	24）int OCSP_resp_count(OCSP_BASICRESP *bs)
	本函数获取响应消息中包含的证书状态的个数。
	25）OCSP_SINGLERESP *OCSP_resp_get0(OCSP_BASICRESP *bs, int idx);
	给定单个响应的序号，从堆栈中取出。
	26）int OCSP_resp_find(OCSP_BASICRESP *bs, OCSP_CERTID *id, int last)
	根据ocsp 证书ID 查询对应的响应在堆栈中的位置，last 为搜索堆栈时的起始
	位置，如果小于0，从0 开始。
	27）int OCSP_single_get0_status(OCSP_SINGLERESP *single, int *reason,
	ASN1_GENERALIZEDTIME **revtime,
	ASN1_GENERALIZEDTIME **thisupd,
	ASN1_GENERALIZEDTIME **nextupd)
	获取单个证书的状态，返回值为其状态，ocsp.h 中定义如下：
#define V_OCSP_CERTSTATUS_GOOD 0
#define V_OCSP_CERTSTATUS_REVOKED 1
#define V_OCSP_CERTSTATUS_UNKNOWN 2
	如果证书被撤销，并且reason 和revtime 参数不为空，将撤销原因以及撤销时
	间返回。并且对于这个证书给出thisUpdate 和nextUpdate。
	28）int OCSP_resp_find_status(OCSP_BASICRESP *bs, OCSP_CERTID *id, int *status,
	int *reason,
	ASN1_GENERALIZEDTIME **revtime,
	ASN1_GENERALIZEDTIME **thisupd,
	ASN1_GENERALIZEDTIME **nextupd);
	功能同OCSP_single_get0_status 函数，id 为OCSP 证书ID，它依次调用
	OCSP_resp_find、OCSP_resp_get0 和 OCSP_single_get0_status 函数，其中status 为
	返回的证书状态。
	29）int OCSP_request_add1_nonce(OCSP_REQUEST *req, unsigned char *val, int len)
	添加nonce 扩展项,val 和len 表明了nonce 值,如果val 为空,则内部生成长度为
	len 的随机数作为nonce。
	30）int OCSP_basic_add1_nonce(OCSP_BASICRESP *resp, unsigned char *val, int len)
	功能同上。
	31）int OCSP_check_nonce(OCSP_REQUEST *req, OCSP_BASICRESP *bs)
	检测nonce，用于防止重放攻击；检查请求和响应的nonce 扩展项，看他们是
	否相等，OCSP 服务端应当将请求中的nonce 拷贝到响应中。如果请求和响应中的
	nonce 扩展项都存在，比较nonce 值，如果不相等，返回错误，或者，请求中有nonce，
	而响应中没有nonce，也返回错误。验证正确时返回值大于0。
	32）int OCSP_copy_nonce(OCSP_BASICRESP *resp, OCSP_REQUEST *req)
	将请求中都 nonce 拷贝到响应中。
	33）X509_EXTENSION *OCSP_crlID_new(char *url, long *n, char *tim)
	根据 crl 的url，crl 个数以及生成crl 的时间生成X509_EXTENSION 扩展项。
	34）X509_EXTENSION *OCSP_accept_responses_new(char **oids)
	根据多个oid 的名字生成扩展项，其中oids 指针数组，以NULL 结尾。本函
	数由客户端调用，告诉服务端它所要的端响应的类型，参考rfc2560 对于
	AcceptableResponses 扩展项的说明。
	35）X509_EXTENSION *OCSP_archive_cutoff_new(char* tim)
	生成单个证书的Archive Cutoff 扩展项，某已被撤销的证书的Archive Cutoff
	时间为本次OCSP 生效时间(producedAt)减去被撤销时的时间。可以将它看作已撤
	销了多长时间。
	36）X509_EXTENSION *OCSP_url_svcloc_new(X509_NAME* issuer, char **urls);
	根据颁发者名字和一个或多个url 生成扩展项。扩展项内容为
	AuthorityInfoAccess。urls 为指针数组，以NULL 结束。
	37）OCSP_CERTID *OCSP_cert_to_id(const EVP_MD *dgst, X509 *subject, X509 *issuer)
	根据摘要算法、持有者证书和颁发者证书生成 OCSP_CERTID 数据结构。
	38）OCSP_CERTID *OCSP_cert_id_new(const EVP_MD *dgst,
	X509_NAME *issuerName,
	ASN1_BIT_STRING* issuerKey,
	ASN1_INTEGER *serialNumber)；
	本函数根据摘要算法、颁发者名字、颁发者公钥 DER 编码以及证书持有者的
	证书序列号生成OCSP_CERTID；奇怪的是serialNumber 可以为空，无法标识需要
	查询状态证书。
	39）int OCSP_id_issuer_cmp(OCSP_CERTID *a, OCSP_CERTID *b)
	比较OCSP_CERTID，如果相等返回0，不相等返回非0。本函数不比较证书
	序列号。
	40）int OCSP_id_cmp(OCSP_CERTID *a, OCSP_CERTID *b)
	比较OCSP_CERTID，如果相等返回0，不相等返回非0。本函数比较所有项，
	包括证书序列号。
	41) int OCSP_parse_url(char *url, char **phost, char **pport, char **ppath, int *pssl);
	分析 url，获取主机、端口、路径和协议(http 还是https)等信息。
	42) char *OCSP_response_status_str(long s)
	根据 OCSP 响应码获取响应状态信息。
	43）char *OCSP_cert_status_str(long s)
	根据证书状态码获取证书状态信息。
	44) char *OCSP_crl_reason_str(long s)
	根据状态码获取证书撤销原因。
	45）int OCSP_REQUEST_print(BIO *bp, OCSP_REQUEST* o, unsigned long flags)
	将 OCSP 请求OCSP_REQUEST 的信息输出到bp 中,flags 表明不支持到扩展项
	的处理方式，参考 X509V3_extensions_print 以及X509V3_EXT_print 函数。
	46）int OCSP_RESPONSE_print(BIO *bp, OCSP_RESPONSE* o, unsigned long flags)
	将OCSP 请求OCSP_RESPONSE 的信息输出到bp 中,flags 表明不支持到扩展
	项到处理方式,参考X509V3_extensions_print 以及X509V3_EXT_print 函数。
	47）int OCSP_request_onereq_count(OCSP_REQUEST *req)
	获取 OCSP 请求中请求列表的个数,即多少个证书状态需要查询。
	48）OCSP_ONEREQ *OCSP_request_onereq_get0(OCSP_REQUEST *req, int i)
	根据在堆栈中到位置获取OCSP_ONEREQ,OCSP_ONEREQ 包含了单个证书
	的信息。
	49）OCSP_CERTID *OCSP_onereq_get0_id(OCSP_ONEREQ *one)
	获取 OCSP_ONEREQ 中到证书ID 信息。
	50）int OCSP_id_get0_info(ASN1_OCTET_STRING **piNameHash,
	ASN1_OBJECT **pmd,ASN1_OCTET_STRING **pikeyHash,
	ASN1_INTEGER **pserial, OCSP_CERTID *cid)
	从cid 中获取颁发者名字摘要值、摘要算法、颁发者公钥摘要值以及持有者证
	书序列号,成功返回1,否则为0。
	51) int OCSP_request_is_signed(OCSP_REQUEST *req)
	判断请求是否已签名，如果已签名返回1,否则返回0。
	52）OCSP_RESPONSE *OCSP_response_create(int status, OCSP_BASICRESP *bs)
	生成 OCSP 响应数据，status 为响应状态，bs 为响应的具体内容。
	53）OCSP_SINGLERESP *OCSP_basic_add1_status(OCSP_BASICRESP *rsp,
	OCSP_CERTID *cid,
	int status, int reason,
	ASN1_TIME *revtime,
	ASN1_TIME *thisupd, ASN1_TIME *nextupd);
	根据输入参数证书ID、证书状态、撤销原因、撤销时间、本次OCSP 时间以
	及下次OCSP 时间生成一个单一证书的状态信息，将此状态信息放入rsp 的堆栈中，
	并返回此状态信息。
	54）int OCSP_basic_add1_cert(OCSP_BASICRESP *resp, X509 *cert)
	添加一个证书到响应信息中。
	55）ASN1_STRING *ASN1_STRING_encode(ASN1_STRING *s, i2d_of_void *i2d,
	void *data, STACK_OF(ASN1_OBJECT) *sk)
	本函数将数据进行DER 编码,编码后的结果放在ASN1_STRING 中，并返回此
	ASN1_STRING。其中，s 为要设置的ASN1_STRING，i2d 为输入数据的i2d 方法,data
	为输入数据结构，sk 为输入对象堆栈。如果data 不为空，则DER 编码data 指向的
	数据结构；如果data 为空，sk 不为空，则DER 编码sk 堆栈表示的内容。
	56）int OCSP_REQUEST_get_ext_count(OCSP_REQUEST *x)
	获取 OCSP_REQUEST 结构中tbsRequest 成员的扩展项的个数。
	57）int OCSP_REQUEST_get_ext_by_NID(OCSP_REQUEST *x, int nid, int lastpos)
	根据对象 nid 获取扩展项在x->tbsRequest->requestExtensions 中的位置。
	58）int OCSP_REQUEST_get_ext_by_OBJ(OCSP_REQUEST *x,
	ASN1_OBJECT *obj, int lastpos)
	获取对象在x->tbsRequest->requestExtensions 中的位置。
	59）int OCSP_REQUEST_get_ext_by_critical(OCSP_REQUEST *x, int crit, int lastpos)
	根据是否关键crit 以及堆栈搜索基准lastpos 获取
	x->tbsRequest->requestExtensions 中扩展项的位置。
	60）X509_EXTENSION *OCSP_REQUEST_get_ext(OCSP_REQUEST *x, int loc)
	根据扩展项在堆栈中的位置获取扩展项。
	61）X509_EXTENSION *OCSP_REQUEST_delete_ext(OCSP_REQUEST *x, int loc)
	根据扩展项在堆栈中的位置删除扩展项。
	62）void *OCSP_REQUEST_get1_ext_d2i(OCSP_REQUEST *x, int nid, int *crit, int *idx)
	根据扩展项nid 获取扩展项信息，其中返回值为扩展项数据结构的指针地址，
	crit 返回是否时关键扩展，idx 表明它在堆栈中的位置。
	63）int OCSP_REQUEST_add1_ext_i2d(OCSP_REQUEST *x, int nid, void *value, int crit,
	unsigned long flags)
	将具体的扩展项添加到x 中，成功则返回1。其中，nid 表明是什么扩展项，
	crit 表明是否是关键扩展，value 是具体扩展项数据结构的地址，flags 表明了何种
	操作，参考函数X509V3_add1_i2d。
	64）int OCSP_REQUEST_add_ext(OCSP_REQUEST *x, X509_EXTENSION *ex, int loc)
	将扩展项添加到 x->tbsRequest->requestExtensions 堆栈中,loc 表示堆栈位置。
	65）int OCSP_basic_verify(OCSP_BASICRESP *bs, STACK_OF(X509) *certs,
	X509_STORE *st, unsigned long flags)
	验证OCSP 响应消息,成功返回1。验证内容有：验证OCSP 签名、验证签名者
	证书、检查每个证书状态信息的颁发者是否是相同、检查颁发者证书的扩展密钥用
	法中是否支持OCSP 签名。

################ 编程示例

	ocsp 的编程主要是生成ocsp 请求、解析ocsp 请求、生成ocsp 响应、解析ocsp 响
	应得到结果以及消息的签名和验证。客户端可用ocsp_cl.c 中提供的函数，服务端可用
	ocsp_srv.c 中提供的函数。典型的应用程序请参考apps/ocsp.c。
