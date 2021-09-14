/**
 *  回文字符串 判断
 *
 *  作者：荣涛
 *  时间：2021年8月18日
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static struct test {
    char *str;
    bool test;

} tests_str[] = {
    {"abcdcba", true},
    {"abcddcba", true},
    {"aaaaaaa", true},
    {"aaaaaaaa", true},
    {"aaabbaaa", true},
    {"aaabaaa", true},
    {"abcdcbaabcdcbaabcdcba", true},
    {"abcddcbaabcddcbaabcddcba", true},
    {"aaaaaaaaaaaaaa", true},
    {"aaaaaaaaaaaaaaaa", true},
    {"aaabbaaaaaabbaaaaaabbaaa", true},
    {"aaabaaaaaabaaaaaabaaa", true},
};


bool check_huiwen(char *str)
{
    if(!str) return false;
    int len = strlen(str);
    if(len <= 0) return false;

//    printf("len = %d\n", len);

    int i;
    for(i=0; i<(len)/2; i++) {
        if(str[i] != str[len-1-i]) 
            return false;
    }
    return true;
}

int main()
{
    int i;

    for(i=0;i<sizeof(tests_str)/sizeof(tests_str[0]); i++) {
        bool ret = check_huiwen(tests_str[i].str);

        printf("%-20s is %5s, %5s\n", tests_str[i].str, ret?"true":"false", ret==tests_str[i].test?"ok":"not ok");
    }
    


}




