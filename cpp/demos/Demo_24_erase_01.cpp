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

    string str[5]= {"ss1","ss2","ss3","ss4","ss5"};

    int i=0;
    while(i<5){

        vstr.insert(vstr.begin(),str[i]);
        i++;
    }

    vector<string>::iterator iter;
    vstr.erase(vstr.begin());

    iter = find(vstr.begin(),vstr.end(), "ss2");
    vstr.erase(iter);

    cout<<endl;
    for(iter = vstr.begin();iter != vstr.end();iter++)
        cout<<*iter<<endl;


    return 0;
}

