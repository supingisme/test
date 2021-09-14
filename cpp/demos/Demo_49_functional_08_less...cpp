#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <functional>/*预定义函数对象*/

using namespace std;

int main(int argc, char *argv[])
{
    int i1 = 3, i2 = 4;
    
    equal_to<int> ET;
    not_equal_to<int> NET;
    greater<int> G;
    greater_equal<int> GE;
    less<int> L;
    less_equal<int> LE;
    
    cout<<ET(i1, i2)<<endl;
    cout<<NET(i1,i2)<<endl;
    cout<<G(i1, i2)<<endl;
    cout<<GE(i1, i2)<<endl;
    cout<<L(i1, i2)<<endl;
    cout<<LE(i1,i2)<<endl;
    
    return 1;
}
