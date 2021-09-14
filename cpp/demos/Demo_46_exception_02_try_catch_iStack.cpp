#include<iostream>
#include<string>
#include<vector>

using namespace std;

/**
1 要求一个pop()操作但栈却是空的
2 要求一个push()操作但栈却是满的
*/
class popOnEmpty { 
public:
    string info = string("Pop on empty!");
 };
class pushOnFull { 
public:
    string info = string("Push on full!");
    pushOnFull( int i ) : _value( i ) { }
    int value() { return _value; }
private:
    int _value;
};

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
        throw pushOnFull(value);
    _stack[ _top++ ] = value;
}

bool iStack::empty()
{
    return _top == 0 ? true:false;
}
bool iStack::full()
{
    return _stack.size() == _top? true : false;
} 
void iStack::display()
{
    for(auto i = _stack.begin(); i != _stack.end(); i++)
        cout<<*i<<endl;
}

int main(int argc, char *argv[])
{
    iStack stack(20);

    /*一个try 块引入一个局部域在try
      块内声明的变量不能在try 块外被引用*/
    try {
        for ( int ix = 1; ix < 501; ++ix )
        {
            if ( ix % 3 == 0 )
                stack.push( ix );
            if ( ix % 4 == 0 )
                stack.display();
            if ( ix % 10 == 0 ) {
                int dummy;
                stack.pop( dummy );
                stack.display();
            }
        }
    }
    /*
    如果这些catch 子句不包含返回语句那么程序的执行将继续到哪儿呢在catch 子句完
    成它的工作之后程序的执行将在catch 子句列表的最后子句之后继续进行
    */
    catch ( pushOnFull &e) { cout<<e.info<<e.value()<<endl; }
    //这里的e用throw异常的拷贝进行初始化
    //为了防止不必要地拷贝大型类对象class 类型的参数应该被声明为引用
    catch ( popOnEmpty &e) { cout<<e.info<<endl; }
    
    return 1;
}
