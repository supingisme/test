// example: 介绍back_inserter(p341)

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec; // 空向量
	auto it = back_inserter(vec); // 通过它赋值会将元素添加到vec中
	*it = 42; // vec中现在有一个元素，值为42
	*it = 43; // vec中现在有一个元素，值为43
	*it = 43; // vec中现在有一个元素，值为43
	*it = 43; // vec中现在有一个元素，值为43
	*it = 43; // vec中现在有一个元素，值为43
    
//# ./example_back_inserter
//    42 43 43 43 43 

	for(auto i : vec)
		cout << i << " "; 
	cout << endl;

	return 0;
}
