############# 23.1 Engine 概述

	Openssl 硬件引擎(Engine）能够使用户比较容易地将自己的硬件加入到openssl 中去，
	替换其提供的软件算法。一个Engine 提供了密码计算中各种计算方法的集合，它用于控制
	openssl 的各种密码计算。

############# 23.2 Engine 支持的原理

	Openssl 中的许多数据结构不仅包含数据本身，还包含各种操作，并且这些操作是可替
	换的。Openssl 中这些结构集合一般叫做XXX_METHOD ， 有DSO_METHOD 、
	DSA_METHOD、EC_METHOD、ECDH_METHOD、ECDSA_METHOD、DH_METHOD、
	RAND_METHOD、RSA_METHOD、EVP_CIPHER 和EVP_MD 等。以RSA 结构为例
	(crypto/rsa/rsa.h)，RSA 结构不仅包含了大数n、e、d 和p 等等数据项目，还包含一个
	RSA_METHOD 回调函数集合。该方法给出了RSA 各种运算函数。
	对于各种数据类型，要进行计算必须至少有一个可用的方法(XXX_METHOD)。因此，
	openssl 对各种类型都提供了默认的计算方法( 软算法) 。如果用户实现了自己的
	XXX_METHOD，那么就能替换openssl 提供的方法，各种计算由用户自己控制。硬件Engine
	就是这种原理。根据需要，一个硬件Engine 可实现自己的RAND_METHOD、RSA_METHOD、
	EVP_CIPHER、DSA_METHOD、DH_METHOD、ECDH_METHOD 和EVP_MD 等，来替
	换对应软算法的METHOD。


######## Engine 函数

主要函数如下：
1) ENGINE_add
将Engine 加入全局到链表中。
2) ENGINE_by_id
根据 id 来获取Engine。
3） ENGINE_cleanup
清除所有 Engine 数据。
4） const EVP_CIPHER *ENGINE_get_cipher(ENGINE *e, int nid)
根据指定的硬件Engine 以及对称算法的nid，获取Engine 实现的对应的
EVP_CIPHER，用于对称计算。
5） ENGINE_get_cipher_engine
根据对称算法 nid 来获取Engine。
6） ENGINE_get_ciphers/ENGINE_set_ciphers
获取/设置指定Engine 的对称算法选取函数地址，该函数用于从Engine 中选择
一种对称算法。
7) ENGINE_get_ctrl_function
获取 Engine 的控制函数地址。
8） const DH_METHOD *ENGINE_get_DH(const ENGINE *e)
获取Engine 的DH_METHOD。
9） const EVP_MD *ENGINE_get_digest(ENGINE *e, int nid)
根据Engine 和摘要算法nid 来获取Engine 中实现的摘要方法EVP_MD。
10) ENGINE *ENGINE_get_digest_engine(int nid)
根据摘要算法nid 来获取Engine。
11）ENGINE_get_digests/ENGINE_set_digests
获取/设置指定Engine 的摘要算法选取函数地址，该函数用于从Engine 中选择
一种摘要算法。
12) const DSA_METHOD *ENGINE_get_DSA(const ENGINE *e)
获取Engine 的DSA 方法。
13) int ENGINE_register_XXX(ENGINE *e)
注册函数，将某一个Engine 添加到对应方法的哈希表中。
14) void ENGINE_unregister_XXX(ENGINE *e)
将某一个Engine 从对应的哈希表中删除。
15) void ENGINE_register_all_XXX(void)
将所有的Engine 注册到对应方法的哈希表中。
16）ENGINE_set_default_XXXX
设置某Engine 为对应XXXX 方法的默认Engine。
17) ENGINE_get_default_XXXX
获取XXXX 方法的默认Engine。
18）ENGINE_load_XXXX
加载某种Engine。
19) ENGINE_get_RAND/ENGINE_set_RAND
获取/设置Engine 的随机数方法。
20) ENGINE_get_RSA/ENGINE_set_RSA
获取/设置Engine 的RSA 方法。
21) ENGINE_get_first/ENGINE_get_next/ENGINE_get_prev/ENGINE_get_last
Engine 链表操作函数。
22）ENGINE_set_name/ENGINE_get_name
设置/获取Engine 名字。
23）ENGINE_set_id/ENGINE_get_id
设置/获取Engine 的id。
24) int ENGINE_set_default(ENGINE *e, unsigned int flags)
根据flags 将e 设置为各种方法的默认Engine。
25) ENGINE_set_XXX_function
设置Engine 中XXX 对应的函数。
26) ENGINE_get_XXX_function
获取Engine 中XXX 对应的函数。
27) ENGINE_ctrl
Engine 控制函数。
28) ENGINE_get_ex_data/ENGINE_set_ex_data
获取/设置Engine 的扩展数据。
29）ENGINE_init/ENGINE_finish
Engine 初始化/结束。
ENGINE_up_ref
给Engine 增加一个引用。
ENGINE_new/ENGINE_free
生成/释放一个Engine 数据结构。
ENGINE_register_complete
将给定的Engine，对于每个方法都注册一遍。
ENGINE_register_all_complete
将所有的Engine，对于每个方法都注册一遍。