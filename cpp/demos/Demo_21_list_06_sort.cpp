#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template<class type>
class great_than{
public:
    bool operator()(type v1, type v2){return v1>v2?true:false;}
};

int main(int argc, char *argv[])
{
    int a1[11] = {8,9,1,2,3,4,8,7,8,7,8};
    
    list<int> l1(a1, a1+11);
    
    for(int i : l1)cout<<i;cout<<endl;
    
    l1.sort(greater<int>());//排序
    
    for(int i : l1)cout<<i;cout<<endl;
    
    l1.sort(less<int>());

    for(int i : l1)cout<<i;cout<<endl;
    
    l1.sort(great_than<int>());
    
    for(int i : l1)cout<<i;cout<<endl;
    
    return 1;
}
