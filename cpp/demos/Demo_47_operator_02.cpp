#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

#include <functional>/*预定义函数对象*/

using namespace std;

class Int {
public:
    Int( int ival = 0 ) : _val( ival ){}
    int operator-() { return -_val; }
    int operator%(int ival) { return _val % ival; }
    bool operator<(int ival) { return _val < ival; }
    bool operator!() { return _val == 0; }
private:
    int _val;
};

int main(int argc, char *argv[])
{
    int a = 3;
    
    Int I(a);
    
    /*操作符重载*/
    cout<<I.operator-()<<endl;      cout<<-I<<endl;
    cout<<I.operator%(2)<<endl;     cout<<I%2<<endl;
    cout<<I.operator<(5)<<endl;     cout<<(I<5)<<endl;
    cout<<I.operator!()<<endl;      cout<<!I<<endl;
    
    return 1;
}
