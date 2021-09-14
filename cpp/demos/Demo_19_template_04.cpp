#include<iostream>
#include<string>

using namespace std;

template <class T1, class T2, class T3>
T1 sum( T2 op1, T3 op2 ) { cout<<"1"<<endl; }
void manipulate( int (*pf)( int,char ) ){cout<<"2"<<endl;};
void manipulate( double (*pf)( float,float ) )
{
    cout<<"3"<<endl;
    pf(1.0,1.0);
}

int main(int argc, char *argv[])
{
    // 错误: 哪一个sum 的实例?
    // int sum( int, char ) 还是
    // double sum( float, float ) ?
    //manipulate( &sum );
    // 取实例: double sum( float, float )
    // 调用: void manipulate( double (*pf)( float, float ) );
    manipulate( &sum< double, float, float > );
    
    
    return 1;
}
