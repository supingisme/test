#include<iostream>
#include<string>
#include<iterator>
#include<stack>

//#include<gtk/gtk.h>
//#include"Demo.h"
using namespace std;

class SS{};

int main(int argc, char*argv[])
/* Rong Tao 2018.03.15 */ 
{
    stack<int> stk ;

    stk.push(1);//放入新的栈顶元素
    stk.push(2);
    stk.push(3);
    cout<<stk.empty()<<endl;//如果栈为空则返回true 否则返回false
    cout<<stk.size()<<endl;//返回栈中元素的个数
    stk.pop();//删除但不返回栈顶元素
    cout<<stk.size()<<endl;
    cout<<stk.top()<<endl;//返回但不删除栈顶元素

    stack<SS> s;
    


    return 0;
}

