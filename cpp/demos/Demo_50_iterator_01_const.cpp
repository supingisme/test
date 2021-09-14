#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <functional>/*预定义函数对象*/
#include <bitset>

using namespace std;

// 无法通过编译
template < typename type >
int count( const vector< type > &vec, type value )
{
    int count = 0;
    typename vector<type>::const_iterator iter = vec.begin();
    while ( iter != vec.end() ) 
    {
        if ( *iter == value )
        ++count; ++iter; 
    }
    return count;
}

int main(int argc, char *argv[])
{
    int a[5] = {2,3,2,1,2};
    vector<int> vi;
    vi.insert(vi.begin(), a, a+5);
    
    const vector<int>::const_iterator ite = vi.begin();
    //ite++;//错误
    vector<int>::iterator i = vi.begin();
    i++;//没错，因为不是const
    cout<<*i<<endl;
    
    cout<< *ite <<endl;
    
    cout<< count<int>(vi, 2);
    
    return 1;
}
