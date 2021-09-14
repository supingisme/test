#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

union TokenValue {
    char _cval;
    int _ival;
    char *_sval;
    double _dval;
};

union A{
  
public:
    int i = 1;
    float f;
private:
    double d ;
};

//我们可以为union 定义成员函数包括构造函数和析构函数
union TokenValue2 {
public:
    TokenValue2(int ix) : _ival(ix) { }
    TokenValue2(char ch) : _cval(ch) { }
    // ...
    int ival() { return _ival; }
    char cval() { return _cval; }
private:
    int _ival;
    char _cval;
    // ...
};

int main(int argc, char *argv[])
{
    cout<<sizeof(TokenValue)<<endl;
    
    TokenValue t;
    
    t._ival = 10;
    int i = 99;
    t._sval = (char*)&i;
    cout<<t._ival<<endl;
    cout<<t._dval<<endl;
    
    A a;
    cout<<a.i<<endl;
    cout<<a.f<<endl;
    
    TokenValue2 tp(10);
    cout<<tp.ival()<<endl;
    
    return 1;
}
