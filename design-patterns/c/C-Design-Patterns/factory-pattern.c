/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
//工厂模式
//工厂模式是比较简单，也是比较好用的一种方式。根本上说，工厂模式的目的就根据不
//同的要求输出不同的产品。比如说吧，有一个生产鞋子的工厂，它能生产皮鞋，也能生产胶
//鞋。如果用代码设计，应该怎么做呢？

typedef struct _Shoe
{
	int type;
	void (*print_shoe)(struct _Shoe*);
}Shoe;

//就像上面说的，现在有胶鞋，那也有皮鞋，我们该怎么做呢？
void print_leather_shoe(struct _Shoe* pShoe)
{
	assert(NULL != pShoe);
	printf("This is a leather show!\n");
}
void print_rubber_shoe(struct _Shoe* pShoe)
{
	assert(NULL != pShoe);
	printf("This is a rubber shoe!\n");
}
//所以，对于一个工厂来说，创建什么样的鞋子，就看我们输入的参数是什么？至于结果，
//那都是一样的。
#define LEATHER_TYPE 0x01
#define RUBBER_TYPE 0x02
Shoe* manufacture_new_shoe(int type)
{
	assert(LEATHER_TYPE == type || RUBBER_TYPE == type);
	Shoe* pShoe = (Shoe*)malloc(sizeof(Shoe));
	assert(NULL != pShoe);
	memset(pShoe, 0, sizeof(Shoe));
	if(LEATHER_TYPE == type)
	{
		pShoe->type == LEATHER_TYPE;
		pShoe->print_shoe = print_leather_shoe;
	}
	else
	{
		pShoe->type == RUBBER_TYPE;
		pShoe->print_shoe = print_rubber_shoe;
	}
	return pShoe;
}


int main()
{
	Shoe*shoe= manufacture_new_shoe(LEATHER_TYPE);

	shoe->print_shoe(shoe);

	return 0;
}
