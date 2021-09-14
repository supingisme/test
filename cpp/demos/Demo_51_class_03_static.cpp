#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class Account {
public:
    Account( double amount, const string &owner )
            :_amount(amount),_owner(owner){};
            
    string owner() { return _owner; }

    double getInterestRate(){return _interestRate;}
    
    static const int ID = 1;
    
    int I;
    
    //静态数据成员可以被作为类成员函数的缺省实参而非static 成员不能
    // 错误：对非静态数据成员‘Account::I’的无效使用
    //void show(int id = ID, int i = I ){cout<<id<<I<<endl;}
    void show(int id = ID, int i = ID ){cout<<id<<I<<endl;}
    
private:
    //有序型的const 静态数据成员可以在类体中用一常量值初始化
    const static int _year = 1991;
    const static int _month;
    static double _interestRate;
    double _amount;
    string _owner;
    
    //而非static 数据成员只能被声明为该类的对象的指针或引用
    static Account A;
    Account &B();
    Account *C();
    Account D();
};

//静态类成员不能放在main函数中定义！？且只能提供一个定义？
double Account::_interestRate = 0.0589;
const int Account::_month = 8;


int main(int argc, char *argv[])
{
    Account a(1.2, "a"), b(1.3, "b");
    
    cout<<a.getInterestRate()<<endl;
    if(Account::ID <= 1.0)
        cout<<b.getInterestRate()<<endl;
    
    return 1;
}
