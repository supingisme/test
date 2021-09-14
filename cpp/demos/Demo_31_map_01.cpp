#include<iostream>
#include<map>

using namespace std;

typedef map<string, int> mapStringInt;
typedef map<string, int>::value_type valType;

/* show the map */
void display(mapStringInt tmp)
{
    cout<<"display:\n";
    mapStringInt::iterator begin = tmp.begin(),
                           end = tmp.end(), it;

    for(it = begin; it != end; it++)
        cout<<tmp.size()
            <<(*it).first
            <<": "
            <<(*it).second
            <<endl;
}
/* find str location */
int find(mapStringInt &tmp, string str)
{
    mapStringInt::iterator it = tmp.find(str);
    cout<<"find: "
        <<(*it).first
        <<": "
        <<(*it).second
        <<endl;

    return (*it).second; 
}
/* insert key value */
void insert(mapStringInt &tmp, string str, int i)
{
    tmp.insert(mapStringInt::value_type(string(str),i));
}

/* delete key value */
void erase(map<string, int> &tmp, string str)
{
    tmp.erase(str);
}



int main(int argc, char*argv[])
/* Rong Tao 2018.03.14 */ 
{
    map<string, int> score, s2;

    score[string("a")] = 1;
    score[string("b")] = 2;

    score.insert( map<string, int>::value_type(string("c"),3) );
    score.insert( valType(string("d"),4) );

    s2.insert(score.begin(), score.end());
    mapStringInt s3(s2);

    s3.insert( map<string,int>::value_type(string("e"),5));

    cout<<s3["e"]<<endl;
    cout<<s3.count("e")<<endl;
    
    display(s3);
    find(s3,"c"); 
    
    insert(s3,string("f"), 6);

    display(s3);
    erase(s3,"b");
    cout<<"\n";
    display(s3);
    cout<<"\n";
    display(s2);
    cout<<"\n";
    s3.swap(s2);
    cout<<"\n";
    display(s3);
    cout<<"\n";
    display(s2);
    
    
    return 0;
}

