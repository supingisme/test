#include<iostream>
#include<string>

using namespace std;

template <class type>
type sum(type a, type b)
{
    return a + b;
}

template <class Type, int size>
Type min( const Type (&r_array)[size] )
{
    /* 找到数组中元素最小值的参数化函数 */
    Type min_val = r_array[0];
    for ( int i = 1; i < size; ++i )
        if ( r_array[i] < min_val )
            min_val = r_array[i];
    cout<<size<<endl;
    return min_val;
}

template <class T1, typename T2, class T3>
T1 foo( T2 t2, T3 t3){
    T1 t1 = t2 + t3;
    return t1;
}

typedef char Ctype;
template <class Ctype>
Ctype fpp( Ctype a, Ctype b ){
    return a + b;
}

int main(int argc, char *argv[])
{
    cout<<sum<int>(1, 2)<<endl;
    
    int a[3] = {4,5,6};
    cout<<min<int>(a)<<endl;
    
    cout<<foo<int,int,int>(2,3)<<endl;
    
    cout<<fpp<char>('a',1)<<endl;
    
    return 1;
}
