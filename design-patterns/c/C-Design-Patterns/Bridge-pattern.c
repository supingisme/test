/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//桥接模式
//在以往的软件开发过程中，我们总是强调模块之间要低耦合，模块本身要高内聚。那么，
//可以通过哪些设计模式来实现呢？桥接模式就是不错的一个选择。我们知道，在现实的软件
//开发过程当中，用户的要求是多种多样的。比如说，有这么一个饺子店吧。假设饺子店原来
//只卖肉馅的饺子，可是后来一些吃素的顾客说能不能做一些素的饺子。听到这些要求的老板
//自然不敢怠慢，所以也开始卖素饺子。之后，又有顾客提出，现在的肉馅饺子只有猪肉的，
//能不能做点牛肉、羊肉馅的饺子？一些只吃素的顾客也有意见了，他们建议能不能增加一些
//素馅饺子的品种，什么白菜馅的、韭菜馅的，都可以做一点。由此看来，顾客的要求是一层
//一层递增的。关键是我们如何把顾客的要求和我们的实现的接口进行有效地分离呢？
//上面只是对饺子进行归类。第一类是对肉馅饺子的归类，第二类是对素馅饺子的归类，
//这些地方都没有什么特别之处。那么，关键是我们怎么把它和顾客的要求联系在一起呢？
//
//		模块之间要低耦合，模块本身要高内聚
//
typedef struct _DumplingReuqest
{
	int type;
	void* pDumpling;
}DumplingRequest;

//这里定义了一个饺子买卖的接口。它的特别支持就在于两个地方，第一是我们定义了饺
//子的类型type，这个type 是可以随便扩充的；第二就是这里的pDumpling 是一个void*指针，
//只有把它和具体的dumpling 绑定才会衍生出具体的含义。

void buy_dumpling(DumplingReuqest* pDumplingRequest)
{
	assert(NULL != pDumplingRequest);
	if(MEAT_TYPE == pDumplingRequest->type)
		return (MeatDumpling*)(pDumplingRequest->pDumpling)->make();
	else
		return (NormalDumpling*)(pDumplingRequest->pDumpling)->make();
}
