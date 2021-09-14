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

using namespace std;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.12 */
{
    string filename;
    cout<<"filename:";
    filename="";
    if(filename.empty())
    {
        cerr<<"filename empty"<<endl;
        //return -1;
    }
    else{
    
        cout<<"not"<<endl;
    }

    string text("rong");


    if(false)
        if(true)
            cout<<"T1"<<endl;
        else
            cout<<"T2"<<endl;


    char ch;
    ch = 'a';//cin>>ch;
    switch(ch){

        case 'a':
            cout<<"a"<<endl;break;
        case 'b':default:cout<<"nothing"<<endl;
    }
loop1:
    for(int i=0;i<10;i++)
    {
        if(i==2)continue;
        cout<<i<<endl;
    }
    bool b = true;
    while(b == true){
        cout<<"true"<<endl;
        b = !b;
    }
    do{
        cout<<"do while"<<endl;
        b = !b;
        if(b = true){
            break;
        }else {
            goto loop1;
        }
    }while(b==true);

    return 0;
}

