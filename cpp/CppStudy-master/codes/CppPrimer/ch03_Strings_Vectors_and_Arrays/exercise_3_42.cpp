/*
 * 练习3.42：编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。
 */

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5};
/*
constexpr是C++11中新增的关键字，其语义是“常量表达式”，也就是在编译期可求值的表达式。
  最基础的常量表达式就是字面值或全局变量/函数的地址或sizeof等关键字返回的结果，
  而其它常量表达式都是由基础表达式通过各种确定的运算得到的。
  constexpr值可用于enum、switch、数组长度等场合。
*/
	constexpr size_t LEN = 5;/* 编译期求值   <rt 2019.12.18>*/
	int a[LEN] = {0};

	size_t cnt = 0;
	for (auto i : vec) {
		a[cnt++] = i;
		if (cnt >= LEN)
			break;
	}

	for (size_t i = 0; i < LEN; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
