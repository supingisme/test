/* Test sysconf, rongtao 2021年 02月 09日 星期二 14:42:29 CST */
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("_SC_LOGIN_NAME_MAX = %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
    return 0;
}
