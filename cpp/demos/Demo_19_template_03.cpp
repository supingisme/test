#include<iostream>
#include<string>

using namespace std;

template <class type, int size>
void f(type (&a)[size]){
    cout<<"f: "<<size<<endl;
}

template <class Type>
Type min3( const Type* array, int size ) { /* ... */ }
template <class Type>
Type min5( Type p1,Type p2 ) { /* ... */ }

int main(int argc, char *argv[])
{
    char  ch[3] = {'a','b','c'};
    f(ch);
    
    double dobj1, dobj2;
    float fobj1, fobj2;
    char cobj1, cobj2;
    int ai[5] = { 511, 16, 8, 63, 34 };
    min5( cobj2, 'c' );
    //min5( dobj1, fobj1 );//错误：对‘min5(double&, float&)’的调用没有匹配的函数
    min3( ai, cobj1 );
    
    return 1;
}
