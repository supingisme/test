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
    int a[5] = {2,2,2,3,4};
    
    vector<int> vi(a, a+5);
    
    for(auto i : vi) cout<<i<<endl;
    
    vector<int>::reverse_iterator rite = vi.rbegin();
    cout<< *rite <<endl;
    
    vector<int>::const_reverse_iterator crite = vi.rbegin();
    cout<< *crite <<endl;
    
    cout<< *(++rite) <<endl;//反向的++相当于正向迭代器的--
    
    cout<< *vi.begin() <<endl;//第一个元素
    cout<< *vi.rbegin() <<endl;//最后一个元素
    
    return 1;
}
