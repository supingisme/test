#include <iostream>

const char *name = "rongtao";

int main()
{
	const char *pstr = name;
	std::cout <<name<<std::endl;

	std::cout <<pstr<<std::endl;

	//强制类型转换
	std::cout << static_cast<void*>(const_cast<char*>(pstr)) <<std::endl;
}
