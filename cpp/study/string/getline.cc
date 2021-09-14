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

