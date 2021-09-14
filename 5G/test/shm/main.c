#include <stdio.h>
#include "params.h"



void demo1_()
{
    enum {
        ulbandwidth,
        dlbandwidth,
        ENBname,
    };
        
    UINT(ulbandwidth);
    UINT(dlbandwidth);
    VARIABLE_STR(64, ENBname) = "123";
    
    VARIABLE_V(dlbandwidth) = 123;
} 

int main()
{
    demo1_();
    

    return 0;    
}

