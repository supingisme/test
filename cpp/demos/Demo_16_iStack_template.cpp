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
#include<assert.h>
#include<cstdlib>//abort()
#include<list>
#include<map>
#include<deque>
#include<set>
#include<iterator>
#include<exception>
#include<stack>
#include<queue>

using namespace std;

class iStack {
public:
    iStack( int capacity )
        : _stack( capacity ), _top( 0 ) {}
    bool pop( int &value );
    bool push( int value );
    bool full();
    bool empty();
    void display();
    int size();
private:
    int _top;
    vector< int > _stack;
};

template <class elemType>
class Stack {
public:
    Stack( int capacity=0 );
    bool push( elemType value );
    bool full();
    bool empty();
    void display();
    int size();
private:
    vector< elemType > _stack;
};

/*
bool iStack::empty(  )
{
    if ( !_top )
        return false;
    else
        return true;
}

bool iStack::full(  )
{
    if ( capacity == _top )
        return true;
    else
        return false;
}

bool iStack::pop( int &top_value )
{
    if ( empty() )
        return false;
    top_value = _stack.back(); _stack.pop_back();
    return true;
}

bool iStack::push( int value )
{
    if ( full() )
        return false;
    _stack.push_back( value );
    return true;
}
*/


int main(int argc, char*argv[])
/* Rong Tao 2018.03.15 */ 
{
    iStack iS(2);
    //Stack<int> S(2);

    return 0;
}

