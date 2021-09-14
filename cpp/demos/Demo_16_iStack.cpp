#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstddef> /*size_t*/
#include<bitset>

using namespace std;
 
class iStack{

public:
    iStack(int capacity):_stack(capacity),_top(0){}
    bool pop(int &value);
    bool push(int value);
    bool full();
    bool empty();
    void display();
    int size();

private:
    int _top;
    vector<int> _stack;
};

inline int iStack::size(){return _top;};
inline bool iStack::push(int a){_top++;};

template<typename elemType>
class jstack
{
private:
    int _size = 0;
public:
    vector<elemType> V;
    void push(elemType _v){_size++;};
    elemType pop(){_size--; return (elemType)1;};
};


int main(int argc, char*argv[])
/* Rong Tao 2018.02.05 */
{
    iStack stack = iStack(5);
    cout<<stack.size()<<endl;
    stack.push(2);
    cout<<stack.size()<<endl;

    jstack<int> js;
    js.push(1);
    js.pop();
    
    return 0;
}

