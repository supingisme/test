// example: 向vector对象中添加元素（p90）
// 从标准输入中读取单词，将其作为vector对象的元素存储

#include <string>
#include <iostream>
#include <vector>

using std::cin;
using std::string;
using std::vector;
/*

template<class _Ty,
    class _Ax>
    class vector
        : public _Vector_val<_Ty, _Ax>
    {   // varying size array of values
public:
    / ******** /
protected:
    pointer _Myfirst;   // pointer to beginning of array
    pointer _Mylast;    // pointer to current end of sequence
    pointer _Myend; // pointer to end of array
    };

*//*  string  <rt 2019.12.17>*/

int main()
{
	string word;/*  string  <rt 2019.12.17>*/
	vector<string> text;
	while (cin >> word) {
		text.push_back(word);	// 把word添加到text后面/*  string  <rt 2019.12.17>*/
	}

	return 0;
}
