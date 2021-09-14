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
    int a=1, b=2;
    
    plus<int> i;
    
    int c = i(a,b);
    
    cout<<c<<endl;

    return 1;
}
