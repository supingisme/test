#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>
#include <iterator>
#include <functional>/*预定义函数对象*/
#include <bitset>

using namespace std;


int main(int argc, char *argv[])
{
    int a[6] = {1,2,3,2,1,5};
    
    list<int> v1(a,a+5), v2;
    
    unique_copy(v1.begin(), v1.end(), back_inserter(v2));
    //vector不支持push_front()
    unique_copy(v1.begin(), v1.end(), front_inserter(v2));
    unique_copy(v1.begin(), v1.end(), inserter(v2, v2.begin()));
    
    for(list<int>::value_type ite : v2)
        cout<<ite<<endl;
    
    
    return 1;
}
