/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//访问者模式
//不知不觉当中，我们就到了最后一种设计模式，即访问者模式。访问者模式，听上去复
//杂一些。但是，这种模式用简单的一句话说，就是不同的人对不同的事物有不同的感觉。比
//如说吧，豆腐可以做成麻辣豆腐，也可以做成臭豆腐。可是，不同的地方的人未必都喜欢这
//两种豆腐。四川的朋友可能更喜欢辣豆腐，江浙的人就可能对臭豆腐更喜欢一些。那么，这
//种情况应该怎么用设计模式表达呢？

struct _Tofu;
struct _Visitor;
typedef struct _Tofu
{
	int type;
	void (*eat) (struct _Visitor* pVisitor, struct _Tofu* pTofu);
}Tofu;
typedef struct _Visitor
{
	int region;
	void (*process)(struct _Tofu* pTofu, struct _Visitor* pVisitor);
}Visitor;


