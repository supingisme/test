#include<iostream>
#include<string>
#include<vector>
#include<exception>

using namespace std;

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
