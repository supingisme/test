#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <functional>/*预定义函数对象*/
#include <bitset>

using namespace std;

// 函数对象类的简单形式
class less_equal_ten {
public:
    bool operator() ( int val ) { return val <= 10; }
};
// 对上面的类的一种扩展
class less_equal_value {
public:
    less_equal_value( int val ) : _val( val ) {}
    bool operator() ( int val ) { return val <= _val; }
private:
    int _val;
};

// 进一步对上面的类进行扩展优化
template<class type>
class less_equal_value_2{
public:
    less_equal_value_2(type val): _val(val){}
    bool operator()(type val){return val <= _val;}
private:
    type _val;
};

int main(int argc, char *argv[])
{   
    int a[3] = {1,2,13};
    vector<int> vec;
    vec.insert(vec.end(), a, a+3);
    
    cout<< count_if( vec.begin(), vec.end(), less_equal_ten() );
    cout<< count_if( vec.begin(), vec.end(), less_equal_value(20) );
    cout<< count_if( vec.begin(), vec.end(), less_equal_value_2<int>(20) );
    
    return 1;
}
