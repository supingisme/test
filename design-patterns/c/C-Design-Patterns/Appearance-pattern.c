/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//外观模式
//外观模式是比较简单的模式。它的目的也是为了简单。什么意思呢？举个例子吧。以
//前，我们逛街的时候吃要到小吃一条街，购物要到购物一条街，看书、看电影要到文化一条
//街。那么有没有这样的地方，既可以吃喝玩乐，同时相互又靠得比较近呢。其实，这就是悠
//闲广场，遍布全国的万达广场就是干了这么一件事。
//首先，我们原来是怎么做的。

typedef struct _ShopStreet
{
	void (*buy)();
}ShopStreet;
void buy()
{
	printf("buy here!\n");
}
typedef struct _BookStreet
{
	void (*read)();
}BookStreet;
void read()
{
	printf("read here");
}

//下面，我们就要在一个plaza 里面完成所有的项目，怎么办呢？

typedef struct _Plaza
{
	FoodStreet* pFoodStreet;
	ShopStreet* pShopStreet;
	BookStreet* pBookStreet;
	void (*play)(struct _Plaza* pPlaza);
}Plaza;
void play(struct _Plaza* pPlaza)
{
	assert(NULL != pPlaza);
	pPlaza->pFoodStreet->eat();
	pPlaza->pShopStreet->buy();
	pPlaza->pBookStreet->read();
}
