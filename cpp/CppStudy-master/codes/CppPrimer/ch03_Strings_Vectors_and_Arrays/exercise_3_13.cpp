/*
 * 练习3.13：下列的vector对象各包含多少个元素？这些元素的值分别是多少？
 *
 * (a) vector<int> v1;				(b) vector<int> v2(10);
 * (c) vector<int> v3(10, 42);		(d) vector<int> v4{10};
 * (e) vector<int> v5{10, 42};		(f) vector<string> v6{10};
 * (g) vector<string> v7{10, "hi"};
 */

/*
 * (a) 0个元素。
 * (b) 10个元素，都是0。
 * (c) 10个元素，都是42。
 * (d) 1个元素，10。
 * (e) 2个元素，10,42。
 * (f) 10个元素，都是空string。
 * (g) 10个元素，都是字符串hi。
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;
/*
//_Alloc 表示内存分配器，此参数几乎不需要我们关心
template <class _Ty, class _Alloc = allocator<_Ty>>
class vector{
    ...
protected:
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};

*/
int main()
{
	vector<string> v7{10, "hi"};
	cout << v7.size() << " element(s):";
	for (auto &s : v7)
		cout << " " << s;
	cout << endl;

	return 0;
}
