/*
 * 练习3.28：下列数组中元素的值是什么？
 */

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

#define PRINT_ARRAY(arr, len) \
do {\
	cout << #arr << ":"; \
	for (int i = 0; i < len; ++i) \
		cout << " " << arr[i]; \
	cout << endl; \
} while(0) \
        /*    <rt 2019.12.18>*/

//------------------------------------

string sa[10];	// 都是空字符串
int ia[10]; 	// 都是0
int main()
{
	string sa2[10];	// 都是空字符串
	int ia2[10];	// 都是未定义的值

//------------------------------------

	PRINT_ARRAY(sa, 10);
	PRINT_ARRAY(ia, 10);
	PRINT_ARRAY(sa2, 10);
	PRINT_ARRAY(ia2, 10);
    /*
     $ ./exercise_3_28
     sa:          
     ia: 0 0 0 0 0 0 0 0 0 0
     sa2:          
     ia2: 4198136 0 -850207287 32627 6300096 0 -1796498560 32767 -1 -1
    */

	return 0;
}
