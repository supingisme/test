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
public:
    
    Screen( int hi = 8, int wid = 40, char bk = '#'):
        _height( hi ), // 用 hi 初始化 _height
        _width( wid ), // 用 wid 初始化 _width
        _cursor ( 0 ), // 初始化 _cursor 为 0
        _screen( hi * wid, bk ) // _Screen 的大小为 hi*wid
        // 所有位置用 bk 的字符值初始化
        { // 所有的工作都由成员初始化列表完成
          // 14.5 节将讨论成员初始化列表
        }
    inline void home(){ this->_cursor = 0; }
    inline void move( int, int )const;
    inline void move( Screen* , int, int)const ;
    //通过把成员函数声明为const 以表明它们不修改类对象
    //把一个修改类数据成员的函数声明为const 是非法的
    char get()const{ return _screen[_cursor]; }
    //const 成员函数可以被相同参数表的非const 成员函数重载
    //在这种情况下类对象的常量性决定了调用哪个函数
    char get( int, int );
    char get( int, int )const;
    /*  const Screen cs;
        Screen s;
        char ch = cs.get(0,0); // 调用 const 成员
        ch = s.get(0,0); // 调用非 const 成员
        */
    bool checkRange( int, int )const;
    int height() { return _height; }
    int width() { return _width; }
    void copy( const Screen & );
    void set( char );
    void set( const string & );
    bool isEqual( char ch ) const;
    int ok() const { return _cursor; }
    void error( int ival ) { _cursor = ival; }
    Screen& display();
    //如果一个类对象的值可能被修改的方式是编译器无法控制或检测的
    //则把它声明为volatile
    //编译器对访问该变量的代码就不再进行优化
    char poll() volatile;
    Screen& clear( char bkground );
    Screen& reSize( int h, int w, char bkground );
    Screen& assign( const Screen &source );
    // ...
private:
    int _height = 24;
    int _width = 80;
    string _screen;
    /*
    mutable 数据成员永远不会是const 成员
    即使它是一个const 对象的数据成员
    mutable 成员总可以被更新,即使是在一个const 成员函数中
    */
    mutable string::size_type _cursor;
    inline int remainingSpace();
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
inline void Screen::move( int r, int c )const 
{ // 将 _cursor 称到绝对位置
    if ( checkRange( r, c ) ) // 位置合法吗?
    {
        int row = (r-1) * _width; // 行位置
        //// ok: const 成员函数可以修改 mutable 成员
        this->_cursor = row + c - 1;
    }
}
inline void Screen::move( Screen* _this, int r, int c )const 
{
    if ( checkRange( r, c ) )
    {
        int row = (r-1) * _this->_width;
        _this->_cursor = row + c - 1;
    }
}
char Screen::get( int r, int c )
{
    move( r, c ); // _cursor 位置
    return get(); // 另一个 get() 成员函数
}
bool Screen::checkRange( int row, int col )const 
{ // validate coordinates
    if ( row < 1 || row > _height ||
         col < 1 || col > _width ) {
        cerr << "Screen coordinates ( "
             << row << ", " << col
             << " ) out of bounds.\n";
        return false;
    }
    return true;
}
void Screen::copy( const Screen &sobj )
{
    // 如果这个 Screen 对象与 sobj 是同一个对象
    // 则无需拷贝
    // 我们将在 13.4 节介绍 this 指针
    if ( this != &sobj )
    {
        this->_height = sobj._height;
        _width = sobj._width;
        _cursor = 0;
        // 创建一个新字符串
        // 它的内容与 sobj._screen 相同
        _screen = sobj._screen;
    }
}
void Screen::set( const string &s )
{ // 在当前 _cursor 位置写字符串
    int space = remainingSpace();
    int len = s.size();
    if ( space < len ) {
        cerr << "Screen: warning: truncation: "
             << "space: " << space
             << "string length: " << len << endl;
        len = space;
    }
    _screen.replace( _cursor, len, s );
    _cursor += len - 1;
}
void Screen::set( char ch )
{
    if ( ch == '\0' )
        cerr << "Screen: warning: "
             << "null character (ignored).\n";
    else _screen[_cursor] = ch;
}
inline int Screen::remainingSpace()
{ // 当前位置不再是剩余的
    int sz = _width * _height;
    return( sz - _cursor );
}
char Screen::poll() volatile { /*...*/ }

Screen& Screen::display()
{
    // 打印屏幕的内容
    for ( int ix = 1; ix <= width(); ++ix )
    {
        for ( int iy = 1; iy <= height(); ++iy )
            cout << get( ix, iy );
        cout << "\n";
    }
    return *this;
}
// clear() 的声明在类体内
// 它指定了缺省实参 bkground = '#'
Screen& Screen::clear( char bkground='#' )
{ // 重置 cursor 以及清屏幕
    _cursor = 0;
    _screen.assign( // 赋给字符串
        _screen.size(), // size() 个字符
        bkground // 值都是 bkground
    );
    // 返回被调用的对象
    return *this;
}
bool Screen::isEqual( char ch ) const
{
    return ch == _screen[_cursor];
}
// reSize() 的声明在类体内
// 它指定了缺省实参 bkground = '#'
Screen& Screen::reSize( int h, int w, char bkground = '#' )
{ // 把屏幕的大小设置到高度 h 和 宽度 w
    // 记住屏幕的内容
    string local(_screen);
    // 替换 _screen 所引用的字符串
    _screen.assign( // 赋给字符串
                    h * w, // h * w 个字符
                    bkground // 值都是 bkground
                    );
    typedef string::size_type idx_type;
    idx_type local_pos = 0;
    // 把原来屏幕的内容拷贝到新的屏幕上
    for ( idx_type ix = 0; ix < _height; ++ix )
    { // 每一行
        idx_type offset = w * ix; // 行位置
        for ( idx_type iy = 0; iy < _width; ++iy )
            // 每一列, 赋以原来的值
            _screen[ offset + iy ] = local[ local_pos++ ];
    }
    _height = h;
    _width = w;
    // _cursor 保持不变
    return *this;
}
Screen& Screen::assign( const Screen &source )
{
    if ( this != &source )
    {
        this->~Screen();
        new (this) Screen( source );
    }
    return *this;
}
class StackScreen {
    int topStack;
    // ok: 指向一个 Screen 对象
    Screen *stack;
    void (*handler)();
};
class LinkScreen {
    Screen window;
    LinkScreen *next;
    LinkScreen *prev;
};

bool isEqual( Screen& s1, Screen *s2 )
{ // 如果不相等返回 false, 相等则返回 true
    if ( s1.height() != s2->height() ||
         s1.width() != s2->width() )
        return false;
    for ( int ix = 0; ix < s1.height(); ++ix )
        for ( int jy = 0; jy < s2->width(); ++jy )
            if ( s1.get( ix, jy ) != s2->get( ix, jy ) )
                return false;
    return true; // 还在这里? 那就是相等.
}
int main(int argc, char *argv[])
{
    Screen sobj(3,3); // 13.3.4 节定义的构造函数
    string init("abcdefghi");
    cout << "Screen Object ("
         << sobj.height() << ", "
         << sobj.width() << " )\n\n";
    
    // 设置屏幕的内容
    string::size_type initpos = 0;
    for ( int ix = 1; ix <= sobj.width(); ++ix )
    for ( int iy = 1; iy <= sobj.height(); ++iy )
    {
        sobj.move( ix, iy );
        sobj.move( &sobj, ix, iy );
        sobj.set( init[ initpos++ ] );
    }
    sobj.clear().move(2,2);
    sobj.set('*');
    sobj.display();
    

    const Screen cs( 5, 5 );
    // 读位置(3, 4)的内容
    // 喔! 不能工作, 因为cs是const的，move不是const的
    cs.move( 3, 4 );
    char ch = cs.get();//get是const的,所以可以
    
    return 1;
}
