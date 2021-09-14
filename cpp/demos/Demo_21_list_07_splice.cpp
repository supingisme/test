#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    /*
    搬运全部
    void list::splice( iterator pos, list rhs );
    搬运一个
    void list::splice( iterator pos, list rhs, iterator ix );
    搬运指定个数
    void list::splice( iterator pos, list rhs,iterator first, iterator last );
    */
    int a[5] = {3,2,1,5,4};
    
    list<int> l1(a,a+5);
    list<int> l2(l1);
    
    cout<<"l1: ";for(int i : l1)cout<<i;cout<<"\n";
    cout<<"l2: ";for(int i : l2)cout<<i;cout<<"\n";
    
    //把l1的第一个搬运到l2的最后
    l2.splice(l2.end(), l1, l1.begin());
    
    cout<<"l1: ";for(int i : l1)cout<<i;cout<<"\n";
    cout<<"l2: ";for(int i : l2)cout<<i;cout<<"\n";
    
    //把l1的全部搬运到l2的最后
    l2.splice(l2.end(), l1, l1.begin(), l1.end());
    
    cout<<"l1: ";for(int i : l1)cout<<i;cout<<"\n";
    cout<<"l2: ";for(int i : l2)cout<<i;cout<<"\n";
    
    //把l2的全部搬运到l1的最后
    l1.splice(l1.end(), l2);
    
    cout<<"l1: ";for(int i : l1)cout<<i;cout<<"\n";
    cout<<"l2: ";for(int i : l2)cout<<i;cout<<"\n";
    
    return 1;
}
