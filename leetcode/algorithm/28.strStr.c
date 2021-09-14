//28. 实现 strStr()
//实现 strStr() 函数。
//
//给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
//
//示例 1:
//
//输入: haystack = "hello", needle = "ll"
//输出: 2
//示例 2:
//
//输入: haystack = "aaaaa", needle = "bba"
//输出: -1
//说明:
//
//当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
//对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

#include <stdio.h>

#if 1
int strStr(char * haystack, char * needle){
    if(!haystack || *haystack == '\0') {
        if(*needle == '\0') return 0;
        else return -1;
    }
    
    if(!needle || *needle == '\0') return 0;

    char *need = needle;

    int pos = 0, cmp_cnt = 0;

    while(*haystack != '\0') {

        if(*haystack == *need) {
            while(*haystack == *need && *need != '\0'&& *haystack != '\0'){
//                printf("%c == %c\n", *haystack, *need );
                haystack++;
                need++;
                cmp_cnt++;
            }
            
            if(*need == '\0') {
                return pos;
            } else {
                need = needle;
                haystack -= (cmp_cnt-1);
                cmp_cnt=0;
                pos++;
//                printf("reset needle -> %s\n", need);
            }
        } else {
//            printf("%c != %c\n", *haystack, *need );
            haystack++;
            pos++;
        }

    }

    return -1;
}
#elif 0
int strStr(char *haystack, char *needle)
{
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if (len2 < 1) {
        return 0;
    }
    int i = 0;
    int temp1, temp2;
    for (i = 0; i < len1; i++) {
        if (len1 - i < len2) {
            return -1;
        }
        temp1 = i;
        temp2 = 0;
        while (haystack[temp1++] == needle[temp2++]) {
            if (temp2 == len2) {
                return i;
            }
        }
    }
    return -1;
}

#elif 0

int strStr(char *haystack, char *needle)
{
    if(needle[0] == '\0') return 0;

    char *pneedle = needle;
    int pos = 0, cnt = 0;
    while(*haystack != '\0') {
        while(*haystack == *pneedle && *pneedle != '\0' && *haystack != '\0') {
            cnt++;
        }
        if(*pneedle == '\0') {
            return pos;
        } else {
            pneedle = needle;
            haystack -= (cnt-1);
            cnt=0;
            pos++;
        }
//        haystack++;
//        pos++;
    
    }
    return -1;
}


#endif


int main(int argc, char *argv[]) {

    printf("%d\n", strStr(argv[1], argv[2]));

}

