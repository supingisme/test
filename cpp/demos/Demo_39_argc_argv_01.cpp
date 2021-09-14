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

using namespace std;

void usage(){

    cout<<"usage"<<endl;
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.17 */ 
{
    string version("");
    bool debug = false;

    for (int i=1;i<argc;i++)
    {
        char *pchar = argv[i];

        switch(pchar[0]){

            case '-': {
                switch(pchar[1]){

                    case'd':debug = true;
                            break;
                    case'v':version = string("gcc-4.8.5");
                            break;
                    case'h':usage();
                            break;
                    default:break;
                }
            }
            default: cout<<""<<endl;
        }
    }
    if(debug)
        cout<<version<<endl;

    return 0;
}

