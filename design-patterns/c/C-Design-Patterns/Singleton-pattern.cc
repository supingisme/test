/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//单例模式
//有过面试经验的朋友，或者对设计模式有点熟悉的朋友，都会对单件模式不陌生。
//对很多面试官而言，单件模式更是他们面试的保留项目。其实，我倒认为，单件模式算
//不上什么设计模式。最多也就是个技巧。
//单件模式要是用C++写，一般这么写。
#include <string.h>
#include <assert.h>
class object
{
	public:
		static class object* pObject;
		static object* create_new_object()
		{
			if(NULL != pObject)
				return pObject;
			pObject = new object();
			assert(NULL != pObject);
			return pObject;
		}
	private:
		object() {}
		~object() {}
};
class object* object::pObject = NULL;

int main(int argc, char* argv[])
{
	object* pGlobal = object::create_new_object();
	return 1;
}
//单件模式的技巧就在于类的构造函数是一个私有的函数。但是类的构造函数又是必
//须创建的？怎么办呢？那就只有动用static 函数了。我们看到static 里面调用了构造函数，
//就是这么简单。
