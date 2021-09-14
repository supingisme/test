/*
 * 练习5.24：修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？
 */

/*
 * 程序异常结束，并输出一段文字：
 * terminate called after throwing an instance of 'std::runtime_error'
 *   what():  second number can not equal 0
 */

#include <iostream>
#include <stdexcept>/*   <rt 2019.12.18>*/

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a = 0, b = 0;

	cout << "Enter two number(a/b): ";
	cin >> a >> b;
    
    /*   <rt 2019.12.18>*/

	if (b == 0)
		throw std::runtime_error("second number can not equal 0");/*   <rt 2019.12.18>*/

	cout << static_cast<double>(a) / b << endl;

	return 0;
}
