#include<iostream>
#include<string>

using namespace std;

enum Tokens { INLINE = 128, VIRTUAL = 129 };
Tokens curTok = INLINE;
enum Stat { Fail, Pass };

extern void ff( Tokens a ){cout<<"f1"<<endl;};
extern void ff( Stat a ){cout<<"f2"<<endl;};
extern void ff( int a ){cout<<"f3"<<endl;};

int main(int argc, char *argv[])
{
    Tokens t;
    cout<<INLINE<<endl;
    
    ff(INLINE);
    ff(3);
    ff(Fail);
    
    return 1;
}
