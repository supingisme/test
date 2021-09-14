/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */


#include <stdlib.h>
#include <stdio.h>
 
void show_c(char a)
{
    printf("char: %c\n", a);
}
void show_f(float a)
{
    printf("float: %f\n", a);
}

//如何用宏定义实现多态-函数重载
#define _C(a, b) __builtin_types_compatible_p(a, b)
#define _E(exp, e1, e2) __builtin_choose_expr(exp, e1, e2)
#define show(a) \
    _E(_C(typeof(a), char), show_c(a), \
        _E(_C(typeof(a), float), show_f(a), printf("nothing\n")))
    
 
int main()
{
    show('a');
    show((int)'a');
    show((char)'a');
    show((float)'a');
}
