/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:12 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:14:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:23 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEFINED_FUNC_NUM    256
typedef struct DEFINE_FUNC {
#define MAX_FUNCNAME_STR_LEN    256
    int flag;
    char name[MAX_FUNCNAME_STR_LEN];
    int (*func)(int, void*);
}DEFINE_FUNC_t;

DEFINE_FUNC_t DEFIENED_FUNC_LIST[MAX_DEFINED_FUNC_NUM] = {{0, "", NULL}};

#define ADD_FUNC(func) add_func_to_list(#func, func)

void add_func_to_list(char *name, int (*p)(int, void*))
{
    int i;
    for(i=0;i<MAX_DEFINED_FUNC_NUM;i++)
    {
        if(i == MAX_DEFINED_FUNC_NUM)
        {
            return;
        }
        if(DEFIENED_FUNC_LIST[i].flag == 0)
        {
            DEFIENED_FUNC_LIST[i].flag = 1;
            DEFIENED_FUNC_LIST[i].func = p;
            strcpy(DEFIENED_FUNC_LIST[i].name, name);
        }
    }
    return;
}

void call_func_in_list()

int f1(int id, void *msg){return 1;}
int f2(int id, void *msg){return 2;}
int f3(int id, void *msg){return 3;}
int f4(int id, void *msg){return 4;}


int main()
{
    ADD_FUNC(f1);
    
    
    
}




