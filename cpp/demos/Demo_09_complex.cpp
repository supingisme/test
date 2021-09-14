/* Rong Tao 2018.1.16 */
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>

using namespace std;

typedef complex<int> c_int;
typedef vector<int> v_int;

int main(int argc, char*argv[])
{
    complex<int> a(1,2);
    complex<int> b(1,2);

    complex<int> c = a*b;

    cout<<c<<endl;

    complex<int> e(c);
    cout<<e<<endl;

    c_int f(3);  
    cout<<f<<endl;

    complex<float> g (1,2);

    g = a*b;
    g += a;
    cout<<g<<endl;
    cout<<real(g)<<endl;
    cout<<imag(g)<<endl;

    /* volatile  不进行优化处理*/
    volatile int h;

    return 0;
}
