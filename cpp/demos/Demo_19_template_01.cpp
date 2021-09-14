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

template<class elemType>
class list_item{

public:
    list_item(elemType value, list_item *item = 0)
        :_value(value){
            if(!item)
                _next = 0;
            else{
                _next = item->_next;
                item->_next = this;
            }
        }
    elemType value(){return _value;}
    list_item *next(){return _next;}
    void next(list_item *link){_next = link;}
    void value(elemType new_value){_value = new_value;}
    void display(){cout<<_value<<endl;}

private:
    elemType _value;
    list_item *_next;
};

int main(int argc, char*argv[])
/* Rong Tao 2018.03.12 */
{
    list_item<int> *ptr = new list_item<int>(10);
    ptr->display();
    (*ptr).display();
    //ptr.display();//error

    return 0;
}

