// 使用范围for语句和ispunct函数来统计string对象中标点符号的个数

#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s("Hello World!!!!");
	
	decltype(s.size()) punct_cnt = 0;
	// 统计s中的标点符号
	for (auto c : s)
		if (ispunct(c))/*  手否为标点符号  <rt 2019.12.18>*/
			++punct_cnt;
	
	cout << punct_cnt
	     << " punctuation characters in " << s << endl;

	return 0;
}
