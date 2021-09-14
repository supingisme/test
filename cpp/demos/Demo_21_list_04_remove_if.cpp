#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Even{
public:
    bool operator()(int val){return !(val%2);}//偶数返回true
};

int main(int argc, char *argv[])
{
    int a1[11] = {8,9,1,2,3,4,8,7,8,7,8};
    
    list<int> l1(a1, a1+11);
    
    l1.sort();
    
    for(int i : l1)cout<<i;cout<<endl;
    
    l1.remove(8);//把所有8都删掉了
    l1.remove_if(Even());//删掉所有符合条件的
    
    for(int i : l1)cout<<i;cout<<endl;

    
    return 1;
}
