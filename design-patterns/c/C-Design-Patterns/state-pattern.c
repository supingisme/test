/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//状态模式
//状态模式是协议交互中使用得比较多的模式。比如说，在不同的协议中，都会存在启
//动、保持、中止等基本状态。那么怎么灵活地转变这些状态就是我们需要考虑的事情。假设
//现在有一个state，
//说明一下，这里定义了两个变量，分别process 函数和change_state 函数。其中proces
//函数就是普通的数据操作，

void normal_process()
{
	printf("normal process!\n");
}

//ange_state 函数本质上就是确定下一个状态是什么。
//所以，在context 中，应该有一个state 变量，还应该有一个state 变换函数。

typedef struct _Context
{
	State* pState;
	void (*change)(struct _Context* pContext);
}Context;
void context_change(struct _Context* pContext)
{
	State* pPre;
	assert(NULL != pContext);
	pPre = pContext->pState;
	pContext->pState = pPre->changeState();
	free(pPre);
	return;
}

//类似于状态机吧
