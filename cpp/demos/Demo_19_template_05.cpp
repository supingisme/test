#include<iostream>
#include<string>

using namespace std;

template <class T1, class T2, class T3>
T1 sum( T2 op1, T3 op2 ) { cout<<"1"<<endl; }


int main(int argc, char *argv[])
{
    
    double dobj1, dobj2;
    float fobj1, fobj2;
    char cobj1, cobj2;
    //sum( dobj1, dobj2 );
    sum<double,double,double>( fobj1, fobj2 );
    sum<int>( cobj1, cobj2 );
    //sum<double, ,double>( fobj2, dobj2 );
    return 1;
}
