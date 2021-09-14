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
    float f1 = 3.14;
    float f2 = 3.5;
    
    multiplies<float> M;
    
    cout<<M(f1,f2)<<endl;
    
    
    return 1;
}
