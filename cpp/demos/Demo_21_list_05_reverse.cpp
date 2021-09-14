#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int a1[11] = {8,9,1,2,3,4,8,7,8,7,8};
    
    list<int> l1(a1, a1+11);
    
    for(int i : l1)cout<<i;cout<<endl;
    
    l1.reverse();//反向
    
    for(int i : l1)cout<<i;cout<<endl;

    
    return 1;
}
