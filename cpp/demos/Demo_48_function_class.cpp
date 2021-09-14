#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

using namespace std;


/*函数对象*/
class LessThan {
public:
    bool operator()( const string & s1,
    const string & s2 )
    { return s1.size() < s2.size(); }
};

/**
函数对象与函数指针相比较有两个方面的优点:
首先如果被重载的调用操作符是inline函数则编译器能够执行内联编译提供可能的性能好处;
其次函数对象可以拥有任意数目的额外数据用这些数据可以缓冲结果也可以缓冲有助于当前操作的数据
*/

int main(int argc, char *argv[])
{
    int a[3] = {3,4,2};
    

    
    return 1;
}
