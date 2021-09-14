#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class A{
public:
    void print(){cout<<"rong"<<endl;}
    /*C++98中：除了静态static 
    数据成员外数据成员不能在类体中被显式地初始化
    例如该代码用：$ g++ demo.cpp -std=c++98
    编译不通过*/
    int a = 2;
    
} AA, AAA;

class Screen {
    //友元friend 机制允许一个类授权其他的函数访问它的非公有成员
    friend istream& operator>>( istream&, Screen& );
    friend ostream& operator<<( ostream&, const Screen& );
    friend void init(string _s);
public:
    void home();
    void move( int, int );
    char get();
    char get( int, int );
    bool checkRange( int, int );
    // ...
private:
    // 静态成员
    static const int _height = 24;
    static const int _width = 80;
    string _screen;
    string::size_type _cursor;
protected:
    int father;
};
/*
istream& operator>>( istream& is, Screen& s )
{
    is >> s._height;
    is >> s._width;
    is >> s._screen;
    return is;
}*/
ostream& operator<< ( ostream& os, const Screen& s )
{
    // ok: 指向 height, _width, 和 _screen
    os << "<" << s._height << "," << s._width << ">";
    os << s._screen;
    return os;
}
void init(string _s){ cout<<_s<<endl;}

int main(int argc, char *argv[])
{
    Screen screen;
    init(string("friend init()"));
    
    cout<<screen;
    
    return 1;
}
