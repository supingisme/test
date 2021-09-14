#define ONCE(flag) \
    static int __just_exe_once##flag = 0;\
    if(__just_exe_once##flag++ == 0)

#include <stdio.h>

void func()
{   
    ONCE(1){
        printf("adsfadfadsf\n");
        }
    ONCE(2){
        printf("adadsfa2222222222sfadfadsf\n");
        }
}
int main()
{
    func();
    func();
}
