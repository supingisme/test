#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){

    int *p1 = new int(1024);

    delete p1;

    int *p2 = new int[4];
    int *p3 = p2;
    for(int i=0;i<4;i++)
        p2[i] = i;

    cout<<*p2<<"\n";
    cout<<*(p2+1);
    cout<<*p3++<<endl;
    delete [] p2;
    delete [] p3;
}
