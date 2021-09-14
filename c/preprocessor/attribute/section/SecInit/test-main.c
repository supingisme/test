/**
 *  File:   test-main.c
 *  Author: Rong Tao
 *  Time:   2020/01/22
 */
#define __SECTION_LOG
#include "rongtao-init.h"

int section_func1()
{
    SECTION_LOG("log info\n");
};
SECTION_FN_ADD(section_func1);

int section_func2()
{
    SECTION_LOG("log info\n");
};
SECTION_FN_ADD(section_func2);

/**
 *  Function:   main
 *  Author:     Rong Tao
 *  Time:       2020/01/22
 */
int main()
{
    DO_SECTION_CALLS();

    return 0;
}
