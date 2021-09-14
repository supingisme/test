#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <functional>/*预定义函数对象*/
#include <bitset>

using namespace std;

int main(int argc, char *argv[])
{
    int i = 1;
    int j = 1023;
    
    logical_and<int> LA;
    logical_or<int> LO;
    logical_not<int> LN;
    
    int k1 = LA(i,j);
    int k2 = LO(i,j);
    int k3 = LN(i);
    
    cout<<bitset<12>(i)<<endl;
    cout<<bitset<12>(j)<<endl;
    cout<<bitset<12>(k1)<<endl;
    cout<<bitset<12>(k2)<<endl;
    cout<<bitset<12>(k3)<<endl;
    
    
    return 1;
}
