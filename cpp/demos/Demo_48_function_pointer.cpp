#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

using namespace std;

/*函数指针*/

template <typename Type>
const Type&
min( const Type *p, int size )
{
    cout<<"1:";
    int minIndex = 0;
    for ( int ix = 1; ix < size; ++ix )
        if ( p[ ix ] < p[ minIndex ] )
            minIndex = ix;
    return p[ minIndex ];
}

template < typename Type, bool (*Comp)(const Type&, const Type&)>
const Type&
min( const Type *p, int size)
{
    cout<<"2:";
    int minIndex = 0;
    for ( int ix = 1; ix < size; ++ix )
        if ( Comp( p[ ix ], p[ minIndex ] ))
            minIndex = ix;
    return p[ minIndex ];
}

template<class type>
bool comp(type a, type b)
{
    return a<b?true:false;
}



/**
函数对象与函数指针相比较有两个方面的优点:
首先如果被重载的调用操作符是inline函数则编译器能够执行内联编译提供可能的性能好处;
其次函数对象可以拥有任意数目的额外数据用这些数据可以缓冲结果也可以缓冲有助于当前操作的数据
*/

int main(int argc, char *argv[])
{
    int a[3] = {3,4,2};
    
    cout<<min<int>(a, 3);
    cout<<min<int, comp>(a, 3);
    
    return 1;
}
