/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:50 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:50 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:34 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include "getpars.h"


int msg_packaging(int argc, char *argv[])
{
    
    /* initialize getpar */
    initargs(argc,argv);
    
    int n1;
    float d1;

    /* get parameters describing 1st dimension sampling */
    if (!getparint("n1",&n1))
    {
        fprintf(stderr, "Must specify number of samples in 1st dimension!\n");
        exit(1);
    }

    d1 = 1.0;  getparfloat("d1",&d1);

    char *str = malloc(256);
    memset(str, 0, 256);
    if(!getparstring("str", &str))
    {
        fprintf(stderr, "Must define file\n");
        exit(1);
    }


    printf("n1 = %d, d1 = %f, str = %s\n", n1, d1, str);
}



int main(int argc, char *argv[])
{
    int npars = 6;
    char *args[] = {
        __func__,
        "par=par.txt",
        "n1=3111",
        "f1=13.1",
        "d1=3.14",
        "str=Hello World",
        NULL,
    };


    int i=0;
    while(args[i] != NULL)
    {
        i++;
    };
    printf("%d\n", i);
    
    msg_packaging(i, args);

    return 0;
}
