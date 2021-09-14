/*
 * 练习3.24：请使用迭代器重做3.3.3节（第94页）的最后一个练习。
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec;
	int a = 0;
	while (cin >> a)
		ivec.push_back(a);
/*
1.iterator,const_iterator作用：遍历容器内的元素，并访问这些元素的值。iterator可以改元素值,但const_iterator不可改。跟C的指针有点像。
2.const_iterator 对象可以用于const vector 或非 const vector,它自身的值可以改(可以指向其他元素),但不能改写其指向的元素值。
3.cbegin()和cend()是C++11新增的，它们返回一个const的迭代器，不能用于修改元素。
————————————————
版权声明：本文为CSDN博主「快乐晓笑98」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u010987458/article/details/70949112
*/
	if (ivec.begin() == ivec.end())
		return 0;

	for (auto it = ivec.cbegin() + 1; it != ivec.cend(); ++it)
		cout << *it + *(it - 1) << endl;

	return 0;
}
