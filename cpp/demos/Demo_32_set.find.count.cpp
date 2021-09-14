#include<iostream>
#include<string>
#include<set>
#include<iterator>

using namespace std;

void display(set<string> tmp)
{
    set<string>::iterator i ;
    for (i=tmp.begin();i!=tmp.end();i++)
        cout<<(*i)<<"\n";
}

int find(set<string> tmp, string str)
{
    set<string>::iterator i = tmp.find(str);
    cout<<(*i)<<"\n";
    return tmp.count(str);
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.15 */ 
{
    set<string> s;
    set<string>::difference_type d;
    s.insert("rong");
    s.insert("tao");
    s.insert("rong2");
    s.insert("rong");
    s.insert("tao3");

    display(s);
    cout<<find(s, string("rong"))<<endl;

    return 0;
}

