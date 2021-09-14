#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int a1[5] = {8,9,1,2,3};
    int a2[3] = {6,7,8};
    
    list<int> l1(a1, a1+5);
    list<int> l2(a2,a2+3);
    
    l1.sort();
    l2.sort();
    
    for(int i : l1)cout<<i;cout<<endl;
    for(int i : l2)cout<<i;cout<<endl;
    
    l1.merge(l2);//l2变为空的list,
    
    if(l2.empty())
        for(int i : l1)
            cout<<i;
    
    return 1;
}
