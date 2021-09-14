/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//代理模式
//代理模式是一种比较有意思的设计模式。它的基本思路也不复杂。举个例子来说，以前
//在学校上网的时候，并不是每一台pc 都有上网的权限的。比如说，现在有pc1、pc2、pc3，
//但是只有pc1 有上网权限，但是pc2、pc3 也想上网，此时应该怎么办呢？
//此时，我们需要做的就是在pc1 上开启代理软件，同时把pc2、pc3 的IE 代理指向pc1
//即可。这个时候，如果pc2 或者pc3 想上网，那么报文会先指向pc1，然后pc1 把Internet
//传回的报文再发给pc2 或者pc3。这样一个代理的过程就完成了整个的上网过程。
//在说明完整的过程之后，我们可以考虑一下软件应该怎么编写呢？

void ftp_request()
{
	printf("request from ftp!\n");
}
void http_request()
{
	printf("request from http!\n");
}
void smtp_request()
{
	printf("request from smtp!\n");
}
//这个时候，代理的操作应该怎么写呢？怎么处理来自各个协议的请求呢？

typedef struct _Proxy
{
	PC_Client* pClient;
}Proxy;
void process(Proxy* pProxy)
{
	assert(NULL != pProxy);
	pProxy->pClient->request();
}


