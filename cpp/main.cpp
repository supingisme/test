/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:47 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:49 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */
#include <iostream>

using namespace std;

namespace rt
{
using namespace std;

int a = 12;
int b = 13;
template <class type>
	void func1(type val, type out)
	{
		cout<<val+out<<endl;
	}
}

template <typename type>
type func1(type val)
{
	return val*123;
}

using namespace std;
using namespace rt;

int main()
{
	using namespace rt;

	cout<<"Hello World!\n";

	cout<<func1<int>(123)<<endl;

	func1<int>(1212, 12);

	return 0;
}
