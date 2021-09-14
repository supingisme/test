// 练习9.15：编写程序，判定两个vector<int>是否相等。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = {1, 2, 3};

    /*        <rt 2019.12.25>*/
    
	if (v1 == v2)
		cout << "equal" << endl;/*   结果相等     <rt 2019.12.25>*/
	else
		cout << "not equal" << endl;

	return 0;
}
