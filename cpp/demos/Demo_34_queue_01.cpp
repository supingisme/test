#include<iostream>
#include<string>
#include<iterator>
#include<queue>

using namespace std;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.15 */ 
{
    //priority_queue<int> q;  //根据优先级排序  
    queue<int> q;

    cout<<"empty:"<<q.empty()<<endl;
    cout<<"size:"<<q.size()<<endl;
    cout<<"front:"<<q.front()<<endl;
    //cout<<"back:"<<q.back()<<endl;//error

    q.push(1);
    q.push(2);
    q.push(7);
    q.push(1);
    q.push(3);
    q.push(3);
    q.push(4);

    cout<<"empty:"<<q.empty()<<endl;
    cout<<"size:"<<q.size()<<endl;
    cout<<"front:"<<q.front()<<endl;
    cout<<"back:"<<q.back()<<endl;

    q.pop();

    cout<<"empty:"<<q.empty()<<endl;
    cout<<"size:"<<q.size()<<endl;
    cout<<"front:"<<q.front()<<endl;
    cout<<"back:"<<q.back()<<endl;

    //cout<<"top:"<<q.top()<<endl;//error: top() for priority_queue

    cout<<"empty:"<<q.empty()<<endl;
    cout<<"size:"<<q.size()<<endl;
    cout<<"front:"<<q.front()<<endl;
    cout<<"back:"<<q.back()<<endl;

    return 0;
}

