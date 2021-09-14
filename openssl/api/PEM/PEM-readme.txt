#################### PEM 概述

Openssl 使用PEM（Privacy Enhanced Mail）格式来存放各种信息，它是openssl 默认采
用的信息存放方式。Openssl 中的PEM 文件一般包含如下信息：
	1） 内容类型
	表明本文件存放的是什么信息内容，它的形式为“-------BEGIN XXXX ------”，
	与结尾的“------END XXXX------”对应。
	2) 头信息
	表明数据是如果被处理后存放，openssl 中用的最多的是加密信息，比如加密
	算法以及初始化向量iv。
	3) 信息体
	为 BASE64 编码的数据。
	
举例如下：

	-----BEGIN RSA PRIVATE KEY-----
	Proc-Type: 4,ENCRYPTED
	DEK-Info: DES-EDE3-CBC,9CFD51EC6654FCC3
	g2UP/2EvYyhHKAKafwABPrQybsxnepPXQxpP9qkaihV3k0uYJ2Q9qD/nSV2AG9Slqp0HBom
	nYS35NSB1bmMb+oGD5vareO7Bt+XZgFv0FINCclTBsFOmZwqs/m95Af+BBkCvNCct+ngM+
	UWB2N8jXYnbDMvZGyI3ma+Sfcf3vX7gyPOEXgr5D5NgwwNyu/LtQZvM4k2f7xn7VcAFGm
	mtvAXvqVrhEvk55XR0plkc+nOqYXbwLjYMO5LSLFNAtETm9aw0nYMD0Zx+s+8tJdtPq+Ifu
	3g9UZkvh2KpEg7he8Z8vaV7lpHiTjmpgkKpx9wKUCHnJq8U3cNcYdRvCWNf4T2jYLSS4kxd
	K2p50KjH8xcfWXVkU2CK9NQGlh18TmPueZOkSEHf76KTE9DWKAo7mNmcByTziyofe5qK
	htqkYYVBbaCFC0+pKTak4EuLgznt6j87ktuXDXFc+50DnWi1FtQN3LuQH5htl7autzaxCvenfG
	QByIh7gxCygBVCJdWca3xE1H0SbRV6LbtjeB/NdCvwgJsRLBXXkjU2TKy/ljsG29xHP2xzlvOt
	ATxq1zMMwMKt7kJMFpgSTIbxgUeqzgGbR7VMBmWSF4bBNnGDkOQ0WLJhVq9OMbzpB
	zmGJqHn3XjZ2SPXF4xhC7ZhAMxDsFs35P4lPLDH/ycLTcLtUmVZJzvPvzh2r56iTiU28f/rMnH
	n1xQ92Cf+62VgECI6CwTotMeM0EfGdCQCiWjeqrzH9qy8+VN3Q2xIlUZj7ibO59YO1A5zVxp
	KcQRamwyIy/IYTPr2c2wLfsTZPBt6mD4=
	-----END RSA PRIVATE KEY-----

本例是作者生成的一个RSA 密钥，以PEM 格式加密存放，采用了openssl 默认的对称
加密算法。其中，“-----BEGIN RSA PRIVATE KEY-----”表明了本文件是一个RSA 私钥；
DES-EDE3-CB 为对称加密算法，9CFD51EC6654FCC3 为对称算法初始化向量iv。


############### PEM 函数

	PEM 函数定义在crypto/pem.h 中。函数比较简单，主要的函数有：
	1) PEM_write_XXXX/PEM_write_bio_XXXX
	将XXXX 代表的信息类型写入到文件/bio 中。
	2) PEM_read_XXXX/PEM_read_bio_XXXX
	从文件/bio 中读取PEM 的XXXX 代表类型的信息。
	XXXX 可用代表的有：SSL_SESSION、X509、X509_REQ、X509_AUX、
	X509_CRL、RSAPrivateKey、RSAPublicKey、DSAPrivateKey、PrivateKey、PKCS7、
	DHparams、NETSCAPE_CERT_SEQUENCE、PKCS8PrivateKey、DSAPrivateKey、
	DSA_PUBKEY、DSAparams、ECPKParameters、ECPrivateKey、EC_PUBKEY 等。
	3) PEM_ASN1_read/PEM_ASN1_read_bio
	比较底层的PEM 读取函数，2）中的函数都调用了这两个函数。
	4) PEM_ASN1_write/PEM_ASN1_write_bio
	比较底层的PEM 读取函数，1)中的函数都调用了这两个函数。
	5） PEM_read_bio
	读取PEM 文件的各个部分，包括文件类型、头信息以及消息体(base64 解码后
	的结果）。
	6） PEM_get_EVP_CIPHER_INFO
	根据头信息获取对称算法，并加载初始化向量iv。
	7) PEM_do_header
	根据对称算法，解密数据。
	8) PEM_bytes_read_bio
	获取PEM 数据，得到的结果为一个DER 编码的明文数据，该函数先后调用
	了5)、 6）和7）函数。



