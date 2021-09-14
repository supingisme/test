/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//迭代器模式
//使用过C++的朋友大概对迭代器模式都不会太陌生。这主要是因为我们在编写代码的时
//候离不开迭代器，队列有迭代器，向量也有迭代器。那么，为什么要迭代器呢？这主要是为
//了提炼一种通用的数据访问方法。
//比如说，现在有一个数据的容器，
//我们看到，容器有get_first，迭代器也有get_first，这中间有什么区别？

int vector_get_first(struct _Container* pContainer)
{
	assert(NULL != pContainer);
	return pContainer->pData[0];
}
int vector_get_last(struct _Container* pContainer)
{
	assert(NULL != pContainer);
	return pContainer->pData[pContainer->size -1];
}
int vector_interator_get_first(struct _Interator* pInterator)
{
	Container* pContainer;
	assert(NULL != pInterator && NULL != pInterator->pVector);
	pContainer = (struct _Container*) (pInterator->pVector);
	return pContainer ->get_first(pContainer);
}
int vector_interator_get_last(struct _Interator* pInterator)
{
	Container* pContainer;
	assert(NULL != pInterator && NULL != pInterator->pVector);
	pContainer = (struct _Container*) (pInterator->pVector);
	return pContainer ->get_last(pContainer);
}
//看到上面的代码之后，我们发现迭代器的操作实际上也是对容器的操作而已。
