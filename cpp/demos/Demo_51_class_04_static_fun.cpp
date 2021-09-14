#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
    Person(int id): _id(id){}
    
    int _id;
    
    static void setID(int tmp){ID = tmp;}
    static int getID(){return ID;}
    
private:
    
    static int ID;
};

int Person::ID = 15010136;

int main(int argc, char *argv[])
{
    Person p(13);
    
    p._id = 999;
    
    cout<<p.getID()<<endl;
    
    p.setID(1501013);
    
    cout<<p.getID()<<endl;
    
    Person::setID(150101);
    
    cout<<p.getID()<<endl;
    
    return 1;
}
