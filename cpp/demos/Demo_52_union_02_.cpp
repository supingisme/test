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

enum TokenKind { ID, Constant /* 及其他语法单元 */ };

class Token {
public:
    TokenKind tok;
    TokenValue val;
};

int lex() {
    Token curToken;
    char *curString;
    int curIval;
    
    switch(0){
        case ID: // 标识符
            curToken.tok = ID;
            curToken.val._sval = curString;
            cout<<"string"<<endl;
            break;
        case Constant: // 整数常量
            curToken.tok = Constant;
            curToken.val._ival = curIval;
            cout<<"consant"<<endl;
            break;
        // ... etc.
    }
}

int main(int argc, char *argv[])
{
    lex();
    
    //没有提供名字的union
    union {
        char _cval;
        int _ival;
        char *_sval;
        double _dval;
    } val;
    
    val._cval = 98;
    cout<<val._cval<<endl;
    
    //完全匿名的union
    //匿名union 的数据成员可以在定义匿名union 的域中被直接访
    union {
        char u_cval;
        int u_ival;
        int u_ival2;
        char *u_sval;
        double u_dval;
    };
    u_ival = 99;
    cout<<u_ival2<<endl;
    
    
    return 1;
}
