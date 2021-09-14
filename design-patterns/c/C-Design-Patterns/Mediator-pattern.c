/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//中介者模式
//中介者模式，听上去有一点陌生。但是，只要我给朋友们打个比方就明白了。早先自
//由恋爱没有现在那么普遍的时候，男女之间的相识还是需要通过媒婆之间才能相互认识。男
//孩对女方有什么要求，可以通过媒婆向女方提出来；当然，女方有什么要求也可以通过媒婆
//向男方提出来。所以，中介者模式在我看来，就是媒婆模式。

typedef struct _Mediator
{
	People* man;
	People* woman;
}Mediator;

//上面的数据结构是给媒婆的，那么当然还有一个数据结构是给男方、女方的。

typedef struct _People
{
	Mediator* pMediator;
	void (*request)(struct _People* pPeople);
	void (*process)(struct _Peoplle* pPeople);
}People;

//所以，这里我们看到的如果是男方的要求，那么这个要求应该女方去处理啊，怎么处理
//呢？

void man_request(struct _People* pPeople)
{
	assert(NULL != pPeople);
	pPeople->pMediator->woman->process(pPeople->pMediator->woman);
}

//上面做的是男方向女方提出的要求，所以女方也可以向男方提要求了。毕竟男女平等嘛。

void woman_request(struct _People* pPeople)
{
	assert(NULL != pPeople);
	pPeople->pMediator->man->process(pPeople->pMediator->man);
}


