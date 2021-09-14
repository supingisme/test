/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//观察者模式
//观察者模式可能是我们在软件开发中使用得比较多的一种设计模式。为什么这么说？
//大家可以听我一一到来。我们知道，在windows 的软件中，所有的界都是由窗口构成的。
//对话框是窗口，菜单是窗口，工具栏也是窗口。那么这些窗口，在很多情况下要对一些共有
//的信息进行处理。比如说，窗口的放大，窗口的减小等等。面对这一情况，观察者模式就是
//不错的一个选择。
//首先，我们可以对这些共有的object 进行提炼。
//既然Observer 在创建的时候就把自己绑定在某一个具体的Object 上面，那么Object 发
//生改变的时候，统一更新操作就是一件很容易的事情了。

void notify(struct _Object* pObject)
{
	Obserer* pObserver;
	int index;
	assert(NULL != pObject);
	for(index = 0; index < pObject->number; index++)
	{
		pObserver = pObjecet->pObserverList[index];
		pObserver->update(pObserver);
	}
}
