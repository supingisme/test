/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:50 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:51 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:34 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdint.h>
#include <unistd.h>

#include "getpars.h"

#define UINT32  uint32_t
#define INT32   int32_t
#define INT8    int8_t
#define UINT8   uint8_t


typedef struct {
    UINT32 id;
    INT8 name[20];
    INT8 rslt;
}__attribute__((packed)) msg1;

typedef struct {
    UINT32 id;
    INT8 name[20];
    INT8 rslt;
}__attribute__((packed)) msg2;


typedef enum {
    MSG1,
    MSG2,
}Msg;


int msg_send()
{
    /* get parameters describing 1st dimension sampling */
    uint32_t n1 = 10; getparuint("n1",&n1);

    float d1 = 1.0;  getparfloat("d1",&d1);

    char *str = malloc(256);
    memset(str, 0, 256);
    getparstring("str", &str);


    printf("n1 = %d, d1 = %f, str = %s\n", n1, d1, str);
}


int mkarg(Msg code, const char *n, ...)
{
    if(code == -1) return -1;
    
    int argc = atoi(n);

    if(argc == 0) return (-1);
    
    char *argv[PAR_NAMES_MAX];

    va_list args;
    va_start(args, n);

    int i;
    char *str;
    for(i=0;i<argc;i++)
    {
        str = va_arg(args, char*);
        
        argv[i] = malloc(strlen(str)+1);
        memset(argv[i], 0, strlen(str)+1);
        strcpy(argv[i], str);    
        
        str = NULL;
    }

    va_end(args);

    /* initialize getpar */
    initargs(argc,argv);
    
    msg_send();

    for(i=0;i<argc;i++)
    {
        if(argv[i] != NULL)
            free(argv[i]);
    }

    return 0;
}

#define _string(t) #t

int main(int argc, char *argv[])
{
    pid_t pid1 = fork();

do{
    if(pid1 == 0)
    {
        mkarg(MSG1, "4", __FILE__,"n1=0x1", "d1=0x1", "str=\033[32mson1\033[0m");
    }
    else
    {
        mkarg(MSG1, "4", __FILE__,"n1=0x3", "d1=0x3", "str=\033[31mfather\033[0m");
    }

    usleep(300000);
}while(1);
    return 0;
}
