#include<iostream>
#include<string>
#include<vector>

using namespace std;

class A{};
enum{a,b,c};

/**
1 要求一个pop()操作但栈却是空的
2 要求一个push()操作但栈却是满的
*/
class popOnEmpty { /* ... */ };
class pushOnFull { /* ... */ };

class iStack {
public:
    iStack( int capacity )
            : _stack( capacity ), _top( 0 ) { }
    void pop( int &top_value );
    void push( int value );
    bool full();
    bool empty();
    void display();
    int size();
private:
    int _top;
    vector< int > _stack;
};

void iStack::pop( int &top_value )
{
    if ( empty() )
        throw popOnEmpty();
    top_value = _stack[ --_top ];
    cout << "iStack::pop(): " << top_value << endl;
}
void iStack::push( int value )
{
    cout << "iStack::push( " << value << " ) \n";
    if ( full() )
        throw pushOnFull();
    _stack[ _top++ ] = value;
}

bool iStack::empty()
{
    return _top != 0 ? true:false;
}
bool iStack::full()
{
    return _stack.size() == _top? true : false;
} 

int main(int argc, char *argv[])
{
    iStack myStack(20);
    
    throw A();//抛出类型异常
    throw a;  //抛出枚举类型的异常
    
    return 1;
}
