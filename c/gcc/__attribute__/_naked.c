#include <stdio.h>

#define _naked			    __attribute__((__naked__))

/* 'naked'属性阻止编译器生成任何函数入口或退出代码    <rongtao 2019.10.09 comment> */
/*   <rongtao 2019.11.14 17:18-18:00>*/

_naked int  func()
{
    return printf("rongtao\n");
}

int main()
{
    func();
    
}
