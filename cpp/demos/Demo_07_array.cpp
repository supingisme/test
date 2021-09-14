/* Rong Tao 2018.1.16 */
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>

using namespace std;

template <typename elemType>
void print( elemType *pbegin, elemType *pend )
{
    while ( pbegin != pend ) {
        cout << *pbegin << ' ';
        ++pbegin;
    }
}
template <typename A, typename B>
void foo(const A a, const B b)
{
    cout<<a<<b<<endl;
}

int main(int argc, char*argv[])
{
    int a[ 12 ] = {0, 1,5 , 6, 7, 8 , 9, 2 ,3, 4,  10, 11 };
    float f[3] = {1.2,1.3,1.4};
    int *p = a +9;

    cout<<*(a+3)
        <<*p
        <<endl;

    print<int>(a+2,a+8);
    print<float>(f,f+3);
    cout<<endl;
    sort(a+2,a+8);
    print(a+2,a+8);
    cout<<endl;
    
    foo<int, int>(1,2);
    foo<int, float>(1, 2.34);
    foo<float, float>(1.2,3.4);
    
    return 0;
}
