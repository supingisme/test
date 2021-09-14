::
/**
作用域分解运算符::的前面一般是类名称，
后面一般是该类的成员名称
*/
:
/**
1.表示结构体、类中位域的定义
    它可以被声明用来存放特定数目的位
2.用在构造函数后表示：初始化列表
    class A{
    public:
        A():_size(10){}
    private:
        int _size;
    };
3.表示类成员的访问权限 private:
4.类名后面的冒号是用来定义类的继承
*/

const
mutable
/**
为了允许修改一个类的数据成员即使它是一个const 对象的数据成员我们也可以把
该数据成员声明为mutable 易变的mutable 数据成员永远不会是const 成员即使它是
一个const 对象的数据成员mutable 成员总可以被更新即使是在一个const 成员函数中
*/
signed
unsigned

char
short
int
long
float
double

bool



asm
do
if
else
return
typedef 
/**
typedef vector<int> vector_int;
*/
auto 
/**
用不用auto修饰都拥有自动生命周期，所以C++11已经删除了这一用法
auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型，类似的关键字还有decltype。
  
 (1)int a = 10;
    auto au_a = a;//自动类型推断，au_a为int类型
 (2)for (std::vector<std::string>::iterator i = vs.begin(); i != vs.end(); i++)
    for (auto i = vs.begin(); i != vs.end(); i++)
*/
decltype
/**

*/

inline
/**
若一个函数被指定为inline 函数则它将在程
序中每个调用点上被内联地展开
在c/c++中，为了解决一些频繁调用的小函数大量消耗栈空间（栈内存）的问题，
特别的引入了inline修饰符，表示为内联函数。
栈空间就是指放置程序的局部数据（也就是函数内数据）的内存空间。
在系统下，栈空间是有限的，
假如频繁大量的使用就会造成因栈空间不足而导致程序出错的问题，
如，函数的死循环递归调用的最终结果就是导致栈内存空间枯竭。
PS:就是把函数放到调用的位置。
*/

typeid





NULL
nullptr
/**
class Test{
public:
    void TestWork(int  index){cout << "TestWork 1" << std::endl;}
    void TestWork(int *index){cout << "TestWork 2" << std::endl;}
};
int main()
{
    Test test;
    test.TestWork(NULL);
    test.TestWork(nullptr);
}
输出结果:
TestWork 1
TestWork 2

*/

break

sizeof

case
enum 
/**
枚举,例：enum A{a=2,b,c};
*/

static
/**
当一个局部变量的值必须在多个函数调用之间保持有效时我们不能使用普
通的自动对象自动对象的值在函数结束时被丢弃
初始化只在f()首次被调用时执行一次;
未经初始化的静态局部对象会被程序自动初始化为0;
*/

explicit
using
/**
(1) using namespace cplusplus_primer;
(2) namesapce UPC{int a = 100;};
    using UPC::a;
*/
namespace
/**
(1)命名空间
    namespace name1{int a=1,b=2,c=3,d=4;}
    namespace name2{int a=5,b=6,c=7,d=8;}
    using namespace name1;
    using namespace name2;
    cout<<name1::a<<endl;
    cout<<name2::a<<endl;
(2)未命名namespace
    //函数swap()只在此文件中可见
    namespace {void swap(){};}
    所以函数swap()可以在程序整个执行期间被调
    用但是未命名名字空间成员名只在特定的文件中可见
(3)名字空间别名：
    namespace China_University_of_Petrolume{int a = 999;}
    namespace upc = China_University_of_Petrolume;
(4)使用using直接使用namespace成员
    using China_University_of_Petrolume::a;
    cout<<a<<endl;
*/
std
/**
标准名字空间

*/

export
/**
(C++11 前) 用于标注一个模板定义被导出，这允许在其它翻译单元中声明，但不定义同一模板。	
(C++11 起) 不使用，并保留该关键词。
 (模块 TS) 标记当前模块导出一个声明、一组声明或另一个模块。

*/
new 
/**
动态分配内存空间：类似于malloc！？

  例2：
    int *pi = new int[1024];
    int (*pi1)[1024] = new int[3][1024];
    //错误：数组必须为一个由花括号包围的初始值设定所初始化
    //int pi2[2][3] = new int[2][3];
    //错误：不能在初始化时将‘int (*)[3]’转换为‘int**
    //int **pi0 = new int[2][3];
    //错误：数组必须为一个由花括号包围的初始值设定所初始化
    //int *pi9[3] = new int[2][3];
  例2：
    class A{};
    //预分配内存但没有A对象
    char *p = new char[sizeof(A) * 10];
    //主程序中：在开辟的内存中创建对象
    A *a = new(p)A;
    delete[] p;
*/
delete
/**
下面三个常见程序错误都与动态内存分配有关
1 应用delete 表达式失败使内存无法返回空闲
    存储区这被称作内存泄漏memory leak
2 对同一内存区应用了两次delete 表达式
    这通常发生在两个指针指向同一个动态分配
    对象的时候这是一个很难踉踪的问题若多个
    指针指向同一个对象当通过某一个指针释
    放了该对象时就会发生这样的情况此时该对象
    的内存被返回给空闲存储区然后又被分
    配给某个别的对象接着指向旧对象的第二个指针
    被释放新对象也就跟着消失了
3 在对象被释放后读写该对象这常常会发生
    因为delete 表达式应用的指针没有被设置为0
    
void f() {
    int i;
    string str = "dwarves";
    int *pi = &i;
    short *ps = 0;
    double *pd = new double(33);
    //delete str; // 糟糕: "dwarves" 不是动态对象
    //delete pi; // 糟糕: pi 指向i, 一个局部对象
    delete ps; // 安全
    delete pd; // 安全
}
*/
auto_ptr
/**
#include <memory> //auto_ptr
它可以在你不用的时候自动帮你释放内存。
例1：
    auto_ptr< int > pi( new int( 1024 ) );
    如果pi 是个局部对象则pi 所指的对象在定义pi 的模块结束时被释放
    如果pi 是全局对象则pi 所指的对象在程序结束时被释放
例2：
    auto_ptr< string > pstr_auto( new string( "Brontosaurusauto" ) );
    auto_ptr< string > pstr_auto2( pstr_auto );  
    当一个auto_ptr 对象被用另一个auto_ptr 对象初始化或赋值时左边被赋值或初始化的
    对象就拥有了空闲存储区内底层对象的所有权而右边的auto_ptr 对象则撤消所有责任
    
*/
struct
virtual

class
/**
public: 别的程序可见
private：别的程序不可见
protected：继承类像public，别的程序不可见
*/
public
/**
别的程序可见
*/
private
/**
仅自己可见
*/
protected
/**
类中：对子类像public，对其他程序像private
*/
friend
/**
友元friend 机制允许一个类授权其他的函数访问它的非公有成员
*/

this

union
/**
一种节省空间的类.
一个联合中的数据成员在内存中的存储是互相重叠的
每个数据成员都在相同的内存地址开始

1.union 的成员可以被声明为公有私有或保护的
2.union 不能有静态数据成员或是引用成员如果一个类类型定义了构造函数析构函数
    或拷贝赋值操作符则它不能成为union 的成员类型
3.我们可以为union 定义成员函数包括构造函数和析构函数



*/

bit-field//位域
/**
    struct BitField
   {
      unsigned int a:4;  //占用4个二进制位;
      unsigned int  :0;  //空位域,自动置0;
      unsigned int b:4;  //占用4个二进制位,从下一个存储单元开始存放;
      unsigned int c:4;  //占用4个二进制位;
      unsigned int d:5;  //占用5个二进制位,剩余的4个bit不够存储4个bit的数据,从下一个存储单元开始存放;
      unsigned int  :0;  //空位域,自动置0;
      unsigned int e:4;  //占用4个二进制位,从这个存储单元开始存放;
   };
*/

extern
/**
1.变量的生明和定义中：为了支持分离式编译
   分离编译时用extern声明并非定义。
  例：extern int i;     //声明并非定义
      int i;            //声明并定义
      extern int i = 1; //声明并定义
      int i = 1;        //和上一句完全一样

2.在多个文件中共享const对象
  例：//file1.cpp定义并初始化和一个常量，该常量能被其他文件访问
      extern const int bufferSize = function();
      //file1.h头文件
      extern const int bufferSize; //与file1.cpp中定义的是同一个
      
3.模板的控制实例化
    当两个或者多个独立编译的源文件中使用了相同的模板
    并且提供了相同的模板参数时，
    每个文件中都会有该模板的一个实例。
    在大系统中，在多个文件中实例化相同的模板的额外开销
    可能非常严重，在C++11新标准中，
    我们可以通过显式实例化来避免这种开销。
    一个显式实例化具有如下形式：
        extern template declaration; //实例化声明
        template declaration;        //实例化定义

4.extern "C"
    允许C++程序中调用C的函数
    #ifndef _CPP_C_
    #define _CPP_C_
    extern "C" int print(const char *str){

        printf(str);//C语言写的，C++可以用
    }
    #endif

extern一般是使用在多文件之间需要共享某些代码时。
*/
operator
/**
调用操作符
例：
    class LessThan {
    public:
        bool operator()( const string & s1, const string & s2 )
        { return s1.size() < s2.size(); }
    };
  调用：
    LessThan lt;
    string st1( "shakespeare" );
    string st2( "marlowe" );
    cout<< lt( st1, st2 );// 调用 lt.operator()( st1, st2 );
    cout<< lt.operator()( st1, st2 );//这两句完全一样
*/
switch

void

false

template 
/**
模板,例：template <typename A, typename B>
在函数模板参数表中关键字typename 和class 的意义相同可以互换使用
(1)函数模板也可以被声明为inline 或extern(注意inline的位置)
    template<class type> 
    inline void foo(type a);
(2)这样没错
    template <class T1, typename T2, class T3>
    T1 foo( T2 t2, T3 t3){
        T1 t1 = t2 + t3;
        return t1;
    }
(3)这样也没错
    typedef char Ctype;
    template <class Ctype>
    Ctype fpp( Ctype a, Ctype b ){
        return a + b;
    }
(4)模板实参推演
    template<class type, int size>
    void foo(type (&a)[size]);
    int i[3] = {1,2,3);
    float f[4] = {1.2, 2.3, 4.5, 6.7};
    foo(i);//type -> int, size -> 3
    foo(f);//type -> float, size -> 4
*/
typename
/**
用在模板定义里，标明其后的模板参数是类型参数。

(1)在函数模板参数表中关键字typename 和class 的意义相同可以互换使用.
    template<class type> 等同于 template<typename type>
    
(2)告诉编译器一个表达式是类型表达式的机制是在表达式前加上关键字typename:
    template <class Parm, class U>
    Parm minus( Parm* array, U value ){
        Parm::name * p; // 这是一个指针声明还是乘法乘法?乘法！
    }
    template <class Parm, class U>
    Parm minus( Parm* array, U value ){
        typename Parm::name * p; // ok: 指针声明
    }
    关键字typename 也可以被用在模板参数表中以指示一个模板参数是一个类型
*/

try
catch
throw
/**
C++11弃用了动态异常规范；

例(1):
    void foo(){throw(string("exception"));}
    void (*p)() throw(string) = foo;
    int main(int argc, char *argv[]){
        try{
            p();
        }catch(string str){
            cout<<str<<endl;
        }
        return 1;
    }
*/

volatile 
/**
 C/C++ 中的 volatile 关键字和 const 对应，用来修饰变量
 volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素更改，比如：操作系统、硬件或者其它线程等。遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问。声明时语法：int volatile vInt; 当要求使用 volatile 声明的变量的值的时候，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据。而且读取的数据立刻被保存。
*/

const_cast 
/**
转换掉表达式的常量性以及volatile
*/
static_cast 
/**
转换掉表达式的const性和static性
*/
reinterpret_cast
/**

*/
dynamic_cast
/**

*/

wchar_t
continue
for


while
default

register 
/**
这个关键字请求编译器尽可能的将变量存在CPU内部寄存器中，
而不是通过内存寻址访问，以提高效率;
在函数中频繁被使用的自动变量可以用register 
声明如果可能的话编译器会把该对
象装载到机器的寄存器中如果不能够的话
则对象仍位于内存中出现在循环语句中的数
组索引和指针是寄存器对象的很好例子
*/
true

goto

/**
通常对于操作数的位模式执行一个比较低层次的重新解释
*/

vector 
/**
vector是一个十分有用的容器
能够存放任意类型的动态数组
能够增加和压缩数据
empty() //vi.empty()
size() //vi.size()
insert()//
push_back() //vi.push_back(20)
iterator //vector<int>::iterator it
begin() //vi.begin()
end() //vi.end()
sort()
sort(vec.begin(),vec.end())//升序排序
sort(vec.begin(),vec.end(),Comp)//降序排序
vector<>::iterator ite//迭代器
ite = find(vstr.begin(), vstr.end(), "rong");
vstr.erase(iter);//删除
string ss[3] = {"ss1","ss2","ss3"};
vstr.insert(vstr.begin(), ss, ss+3);
vstr1.swap(vstr2); //交换两个vector
*/

list
/**
List是stl实现的双向链表，不支持iterator的算术运算
与向量(vectors)相比, 它允许快速的插入和删除，
但是随机访问却比较慢。
使用时需要添加头文件#include <list>
List定义和初始化：
list<int>lst1;//创建空list
list<int>lst2(5);//创建含有5个元素的list
list<int>lst3(3,2);//创建含有3个元素的list
list<int>lst4(lst2);//使用lst2初始化lst4
list<int>lst5(lst2.begin(),lst2.end());//同lst4
常用的操作：
Lst1.assign() 给list赋值 
Lst1.back() 返回最后一个元素 
Lst1.begin() 返回指向第一个元素的迭代器 
Lst1.clear() 删除所有元素 
Lst1.empty() 如果list是空的则返回true 
Lst1.end() 返回末尾的迭代器 
Lst1.erase() 删除一个元素 
Lst1.front() 返回第一个元素 
Lst1.get_allocator() 返回list的配置器 
Lst1.insert() 插入一个元素到list中 
Lst1.max_size() 返回list能容纳的最大元素数量 
Lst1.merge() 合并两个list 
Lst1.pop_back() 删除最后一个元素 
Lst1.pop_front() 删除第一个元素 
Lst1.push_back() 在list的末尾添加一个元素 
Lst1.push_front() 在list的头部添加一个元素 
Lst1.rbegin() 返回指向第一个元素的逆向迭代器 
Lst1.remove() 从list删除元素 
Lst1.remove_if() 按指定条件删除元素 
Lst1.rend() 指向list末尾的逆向迭代器 
Lst1.resize() 改变list的大小 
Lst1.reverse() 把list的元素倒转 
Lst1.size() 返回list中的元素个数 
Lst1.sort() 给list排序 
Lst1.splice() 合并两个list 
Lst1.swap() 交换两个list 
Lst1.unique() 删除list中重复的元素


*/

complex 
/**
complex<int> a(1,2) //1+2i
*/

pair 
/**
pair<string, int> name
first// p.first
second //p.second
*/

map
/**
map由pair（键值对）组成
https://blog.csdn.net/yas12345678/article/details/52601624
Map是c++的一个标准容器，
提供了很好一对一的关系，
在一些程序中建立一个map可以起到事半功倍的效果，
总结了一些map基本简单实用的操作！
1. map最基本的构造函数；
   map<string , int >mapstring;         map<int ,string >mapint;
   map<sring, char>mapstring;         map< char ,string>mapchar;
   map<char ,int>mapchar;            map<int ,char >mapint；
2. map添加数据；
   map<int ,string> maplive;  
   1.maplive.insert(pair<int,string>(102,"aclive"));
   2.maplive.insert(map<int,string>::value_type(321,"hai"));
   3, maplive[112]="April";//map中最简单最常用的插入添加！
3，map中元素的查找：
   find()函数返回一个迭代器指向键值为key的元素，如果没找到就返回指向map尾部的迭代器。        
   map<int ,string >::iterator l_it;; 
   l_it=maplive.find(112);
   if(l_it==maplive.end())
                cout<<"we do not find 112"<<endl;
   else cout<<"wo find 112"<<endl;
4,map中元素的删除：
   如果删除112；
   map<int ,string >::iterator l_it;;
   l_it=maplive.find(112);
   if(l_it==maplive.end())
        cout<<"we do not find 112"<<endl;
   else  maplive.erase(l_it);  //delete 112;
5,map中 swap的用法：
  Map中的swap不是一个容器中的元素交换，而是两个容器交换；
6.map的sort问题：
  Map中的元素是自动按key升序排序,所以不能对map用sort函数
7.map的基本操作函数：
      C++ Maps是一种关联式容器，包含“关键字/值”对
      begin()          返回指向map头部的迭代器
      clear()         删除所有元素
      count()          返回指定元素出现的次数
      empty()          如果map为空则返回true
      end()            返回指向map末尾的迭代器
      equal_range()    返回特殊条目的迭代器对
      erase()          删除一个元素
      find()           查找一个元素
      get_allocator()  返回map的配置器
      insert()         插入元素
      key_comp()       返回比较元素key的函数
      lower_bound()    返回键值>=给定元素的第一个位置
      max_size()       返回可以容纳的最大元素个数
      rbegin()         返回一个指向map尾部的逆向迭代器
      rend()           返回一个指向map头部的逆向迭代器
      size()           返回map中元素的个数
      swap()           交换两个map
      upper_bound()    返回键值>给定元素的第一个位置
      value_comp()     返回比较元素value的函数
*/

multimap
/**
https://blog.csdn.net/chenyujing1234/article/details/8193172
multimap多重映照容器:
 容器的数据结构采用红黑树进行管理 
multimap的所有元素都是pair:
 第一元素为键值(key),不能修改;
 第二元素为实值(value),可被修改
multimap特性以及用法与map完全相同，唯一的差别在于: 
 允许重复键值的元素插入容器(使用了RB-Tree的insert_equal函数)  
 因此: 
  键值key与元素value的映照关系是多对多的关系 
  没有定义[]操作运算
*/

set
/**
set和multiset会根据特定的排序原则将元素排序。
两者不同之处在于，
multiset允许元素重复，
set不允许重复。
*/
multiset
/**
multiset 和multimap 允许要被存储的键出现多次

*/
bitset 
/**
bitset存储二进制数位,
就像一个bool类型的数组一样，
但是有空间优化,例:bitset<10>
hex //16进制
oct //8进制
dec //10进制
test() //bit.test(3) 3位是否为1
any() //任意位是否为1
none() //
count() //值为1的个数
size() //总位数
flip() //翻转所有的位
flip(5) //翻转5 位
set() //将所有位置1
set(3) //将3位置1
reset() //将所有位置0
reset(3) //将3位置0
to_string() //转为string
*/

stack
/**
c++stack(堆栈）是一个容器的改编，
它实现了一个先进后出的数据结构（FILO）.
1.入栈：如s.push(x);
2.出栈:如 s.pop().
    注意：出栈操作只是删除栈顶的元素，
          并不返回该元素。
3.访问栈顶：如s.top();
4.判断栈空：如s.empty().当栈空时返回true。
5.访问栈中的元素个数，如s.size（）;
*/

queue
/**
不进行排序，与priority_queue的区别。
C++队列queue模板类的定义在<queue>头文件中,
queue 模板类需要两个模板参数，
一个是元素类型，一个容器类型，元素类型是必要的，
容器类型是可选的，默认为deque 类型。
back()返回最后一个元素
empty()如果队列空则返回真
front()返回第一个元素
pop()删除第一个元素
push()在末尾加入一个元素
size()返回队列中元素的个数
*/
priority_queue
/**
根据元素的优先级被读取，这个优先级取决于你设置的排序函数，
如果你没设置，缺省的排序法则则是利用operator<形成“降序排列”
top()
push()
pop()
*/
string
/**
string str("abcdefghijk");
int pos = str.find( "bcd" );
if ( pos != string::npos )
    cout << "bcd found!\n";

string::npos
npos的原型应该是std::container_type::size_type，
每一个容器类都会定义这个值，表示一个不存在的位，
用于统一对容器查找结果的判断，
如find函数，若没有找到相应的值，就会返回npos，
大家只要判断find返回的值是不是等于npos，
就能判断出，在该容器是不是存在该值，
平时我们判断的时候，只是看find返回的值是否等于-1，
若为-1则未找到，其实是因为string::pos为-1，故正确，
但是放在其他容器就不一定是这样，
故大家进行判断的时候最好用npos。

string::size_type//相当于unsigned int

查找字符串中第1个出现的匹配
str1.find_first_of(str2)//从头找
str1.find_first_of(str2,2)//从索引2开始找
如果str1中含有str2中的任何字符，则就会查找成功

查找字符串中最后一个出现的匹配
str1.find_last_of(str2)//从尾找
str1.find_first_of(str2,2)//从索引2开始找向前找

字符串分配与连接
string s1( "Mississippi" );
string s2( "Annabelle" );
string s3;
s3.assign( s1, 0, 4 ).append( " " ).append( s2, 0, 4 );
s3 -> Miss Anna

字符串比较
str1.compare(str2)
str1 > str2 return 负数
str1 = str2 return 0
str1 < str2 return 正数

获取某个元素
str.at(2) //获取索引为2的元素

替换字符串
str.replace(4, 3, "abc"); //用abc替换str从索引4开始的三个字符
*/

iterator
/**
vector<string>::iterator ite = vstr.begin()
ite = find(vstr.begin(), vstr.end(), "rong");
*/

back_inserter
/**
back_inserter 被称为iterator适配器它使得元素被插入到作为实参的vector 的尾部
copy( (*iter).begin(), (*iter).end(), back_inserter( texts ));
*/

/**
 *  函数
 */
/**
1.省略参数只能省略后面几个；
2.函数可以返回一个引用；
3.可变参数列表{
    int add(int num,...)  
    //求和函数
    {
        va_list args;
        int sum=0;
        va_start(args,num);
        for(int i=0;i<num;i++)
            sum += va_arg(args,int);      
        va_end(args);
        return sum;
    }
    //调用
    add(3,1,2,3,4,5);//求前三位的和1+2+3
}
4.函数指针
  例1：
    //函数原型
    int fun(string str, int *a){cout<<str<<(*a)<<endl;} 
    //函数指针
    int (*p) (string,int*);
    //指向函数名和调用
    p = fun;
    (*p)(string("rong"),&a);
    p(string("tao"),&a);//这样也可以
  例2：
    typedef void (*PTR)();
    void print1(){cout<<"print1\n";}
    void print2(){cout<<"print2\n";}
    //指向
    PTR ptr[2] = { print1, print2}; 
    //调用
    (ptr)[0]();
    (ptr)[1]();

*/

/**
 *  泛型算法
 */
/**
查找算法：
    adjacent_find(), 
    binary_search(), 
    count(), 
    count_if(), 
    equal_range(),
    find(), 
    find_end(), 
    find_first_of(), 
    find_if(), 
    lower_bound(),
    upper_bound(), 
    search(), 
    search_n()
    
排序和通用整序算法：
    inplace_merge(), 
    merge(),//合并
    nth_element(), 
    partial_sort(),
    partial_sort_copy(), 
    partition(), 
    random_shuffle(), 
    reverse(),
    reverse_copy(), 
    rotate(), 
    rotate_copy(), 
    sort(), 
    stable_sort(),
    stable_partition()

删除和替换算法：
    copy(), 
    copy_backwards(), 
    iter_swap(), 
    remove(), 
    remove_copy(),
    remove_if(), 
    remove_copy_if(), 
    replace(), 
    replace_copy(),
    replace_if(), 
    replace_copy_if(), 
    swap(), 
    swap_range(), 
    unique(),
    unique_copy()
    
排列组合算法：
    next_permutation(), 
    prev_permutation()

算术算法：
    accumulate(), 
    partial_sum(), 
    inner_product(), 
    adjacent_difference()

生成和异变算法：
    fill(), 
    fill_n(),
    for_each(), 
    generate(), 
    generate_n(), 
    transform().

关系算法：
    equal(), 
    includes(), 
    lexicographical_compare(), 
    max(), 
    max_element(),
    min(), 
    min_element(), 
    mismatch()

集合算法：
    set_union(), 
    set_intersection(), 
    set_difference(),
    set_symmetric_difference()

堆算法
    make_heap(), 
    pop_heap(), 
    push_heap(), 
    sort_heap()





*/

