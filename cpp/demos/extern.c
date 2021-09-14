#include<stdio.h>

#ifndef _CPP_C_
#define _CPP_C_
extern "C" int print(const char *str){

    printf(str);
}
#endif

extern int aa = 90;
