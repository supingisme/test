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
    string sval1("rong");
    string sval2("tao");
    
    plus<string> stringAdd;
    
    // 调用 string::operator+()
    string sres = stringAdd( sval1, sval2 );
    cout<<sres<<endl;
    
    int i1=3, i2 = 4;
    minus<int> M;
    cout<<M(i1,i2)<<endl;
    
    
    return 1;
}
