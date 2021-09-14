#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template<class type>
class foo{
public:
    /*去掉第二个元素能被第一个元素整除的相邻元素*/
    bool operator()(type v1, type v2){return !(v2%v1);}
};

int main(int argc, char *argv[])
{
    int a[10] = {3,2,2,4,4,2,1,3,5,4};
    
    list<int> l1(a,a+10);
    
    for(int i : l1)cout<<i;cout<<"\n";
    
    l1.unique();
    
    for(int i : l1)cout<<i;cout<<"\n";
    
    l1.unique(foo<int>());
    
    for(int i : l1)cout<<i;cout<<"\n";
    
    return 1;
}
