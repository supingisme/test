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
#include<ctype.h>//atoi()
#include <memory> //auto_ptr


#include"extern.h"

using namespace std;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.19 */ 
{   
    //auto_ptr <int> pi(0);
    /*
    如果pi 是个局部对象则pi 所指的对象在定义pi 的模块结束时被释放
    如果pi 是全局对象则pi 所指的对象在程序结束时被释放
    */
    auto_ptr< int > pi( new int( 1024 ) );

    if ( *pi != 1024 )
        // 喔, 出错了
        cout<<(*pi)<<endl;
    else *pi *= 2;   

    auto_ptr< string > pstr_auto( new string( "Brontosaurusauto" ) );

    string *pstr_type = new string( "Brontosaurusstring" );
    if ( !pstr_type ->empty() )
        cout<<(*pstr_type)<<endl;

    auto_ptr< string > pstr_auto2( pstr_auto );
    string *pstr_type2( pstr_type );


    /*
    当一个auto_ptr 对象被用另一个auto_ptr 对象初始化或赋值时左边被赋值或初始化的
    对象就拥有了空闲存储区内底层对象的所有权而右边的auto_ptr 对象则撤消所有责任
    */
    //string *pstr_type3( pstr_auto );//error
    cout<<"1:"<<(*pstr_type)<<endl;
    //cout<<"2:"<<(*pstr_auto)<<endl;//段错误 (core dumped)
    cout<<"3:"<<(*pstr_type2)<<endl;
    cout<<"4:"<<(*pstr_auto2)<<endl;

    pstr_auto.reset(new string("rongtao"));
    pstr_auto->assign( "Long-neck" );
    cout<<(*pstr_auto)<<endl;


    //类似的行为也发生在赋值操作符上已知下列两个auto_ptr 对象
    auto_ptr< int > p1( new int( 1024 ) );
    auto_ptr< int > p2( new int( 2048 ) );
    //赋值操作符可以将一个auto_ptr 对象拷贝到另一个中如下所示
    p1 = p2;
    cout<<(*p1)<<endl; 
    //cout<<(*p2)<<endl;//段错误 (core dumped)
    p2.reset(new int(4096));
    //p2 = new int(9999);//// 不支持
    cout<<(*p2)<<endl;
    cout<<*(p2.get())<<endl;
    cout<<p2.get()<<endl;



    return 0;
}

