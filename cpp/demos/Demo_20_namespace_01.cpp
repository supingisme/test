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

namespace rong{

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
}
//using namespace rong;

namespace name1{int a=1,b=2,c=3,d=4;}
namespace name2{int a=5,b=6,c=7,d=8;}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.12 */
{
    using namespace rong;

    list_item<int> *l = new list_item<int>(3);

    using namespace name1;
    using namespace name2;
    
    cout<<name1::a<<endl;
    cout<<name2::a<<endl;
    
    return 0;
}

