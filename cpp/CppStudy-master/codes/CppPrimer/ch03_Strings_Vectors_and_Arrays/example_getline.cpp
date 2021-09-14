// example: 使用getline读取一整行（p78）
// ./example_getline < example_getline.cpp

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string line;
    
	while (getline(cin, line))/*    <rt 2019.12.17>*/
		cout << line << endl;

	return 0;
}
