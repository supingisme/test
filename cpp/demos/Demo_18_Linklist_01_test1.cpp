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
using namespace std;


class Linklist_item{

public:
    Linklist_item(int value, Linklist_item *item_to_link_to = 0);
    int value(){return _value;}
    Linklist_item *next(){return _next;}
    void  next(Linklist_item *link){ _next = link;}
private:
    int _value;
    Linklist_item *_next;
};
class Linklist{

public:
    Linklist():_at_front(0),
               _at_end(0),
               _size(0){}
    Linklist(int s):_at_front(0),
                    _at_end(0),
                    _size(s){}
    inline int size(){return _size;}

private:
    Linklist_item *_at_front;
    Linklist_item *_at_end;
    int _size;

};

class A
{
public:
    A():_size(10){}
private:
    int _size;
};


int main(int argc, char*argv[])
/* Rong Tao 2018.03.12 */
{

    Linklist l(2);
    //abort();
    assert(1);
    cout<<l.size()<<endl;

    return 0;
}

