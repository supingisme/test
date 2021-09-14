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

using namespace std;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.13 */ 
{
  
    vector<string> vstr;

    string str;
    while(cin>>str){

        if(str == "quit")break;
        else vstr.push_back(str);
    }

    vector<string>::iterator iter;
    for(iter = vstr.begin();iter != vstr.end();iter++)
        cout<<*iter<<endl;


    return 0;
}

