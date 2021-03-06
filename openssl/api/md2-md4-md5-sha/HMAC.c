//HMAC
//HMAC 用于保护消息的完整性，它采用摘要算法对消息、填充以及秘密密钥进行混合
//运算。在消息传输时，用户不仅传送消息本身，还传送HMAC 值。接收方接收数据后也进
//行HMAC 运算，再比对MAC 值是否一致。由于秘密密钥只有发送方和接收方才有，其他
//人不可能伪造假的HMAC 值，从而能够知道消息是否被篡改。
//ssl 协议中用HMAC 来保护发送消息，并且ssl 客户端和服务端的HMAC 密钥是不同的，
//即对于双方都有一个读MAC 保护密钥和写MAC 保护密钥。
//
//HMAC 的实现在crypto/hmac/hmac.c 中，如下：
unsigned char *HMAC(const EVP_MD *evp_md, const void *key, int key_len,
					const unsigned char *d, size_t n, unsigned char *md,
					unsigned int *md_len)
{
	HMAC_CTX c;
	static unsigned char m[EVP_MAX_MD_SIZE];
	if (md == NULL) md=m;
	HMAC_CTX_init(&c);
	HMAC_Init(&c,key,key_len,evp_md);
	HMAC_Update(&c,d,n);
	HMAC_Final(&c,md,md_len);
	HMAC_CTX_cleanup(&c);
	return(md);
}
//evp_md 指明HMAC 使用的摘要算法；
//key 为秘密密钥指针地址；
//key_len 为秘密密钥的长度；
//d 为需要做HMAC 运算的数据指针地址；
//n 为d 的长度；
//md 用于存放HMAC 值；
//md_len 为HMAC 值的长度。

