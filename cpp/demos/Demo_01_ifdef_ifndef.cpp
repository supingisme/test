#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define rong 3.14
#define b true

void fun(int a){cout<<"a = "<<a<<"\n";}

enum e
{
    E1,
    E2,
    E3,
    E4,
    E5
}E;


#ifndef BOOK_H
#define BOOK_H
/*BOOK_H*/

#endif

#ifdef __cplusplus
    //cout<<"C++"<<endl;
    extern "C"
#endif
int min(int,int);

int main(){

    int a = 1;


#ifdef rong
    std::cout<<"rong:"<<rong<<"\n"<<"b:"<<b<<"\n";
#endif

    if(true){

        cout<<"true,true"<<endl;
    }

    while(a<10){
    
        cout<<a++<<"\n";
    }

    fun(a);

    E = E4;

    cout<<E<<"\n";

    enum weekday{sun,mon,tus,wen,the,fri,sat}day;

/*
-bash-4.1$ c++ -o a Demo.cpp -DDEBUG
-bash-4.1$ ./a
*/
#ifdef DEBUG
    cout<<"debug"<<endl;
#endif    

#ifndef _cplusplus
    cout<<"c++c++"<<endl;
#endif
    //cout<<min(1,2);
    cout<<__FILE__<<"\n"<<__LINE__<<"\n";
    cout<<__FILE__<<"\n"<<__LINE__<<"\n";
    cout<<__TIME__<<"\n";
/*
-bash-4.1$ c++ -o a Demo.cpp -DDEBUG
Demo.cpp: In function ‘int main()’:
Demo.cpp:72: 错误：‘__DATA__’在此作用域中尚未声明
*/
    //cout<<__DATA__<<"\n";

    return 0;
}




