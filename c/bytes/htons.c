/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    
    uint8_t     a;
    uint16_t    b;
    uint32_t    c;
    uint8_t     d[16];
    
}__attribute__((packed))type;

int main(int argc, char *argv[])
{
    type t1 = {
        .a = 8,
        .b = 8,
        .c = 8,
    };
    
    uint8_t     a = 1;
    uint16_t    b = 2;
    uint32_t    c = 4;
    
    t1.a = a;
    t1.b = htons(b);
    t1.c = htonl(c);
    
    printf("%d, %d, %d\n", t1.a, ntohs(t1.b), ntohl(t1.c));
    
    type t2 = t1;
    
    printf("%d, %d, %d\n", t2.a, ntohs(t2.b), ntohl(t2.c));
    
    void *p = &t2;
    uint32_t *tmp = (uint32_t *)(p + 3);
    
    printf("%p, %p, %d, uint64_t:%d\n", p, (&t2), ntohl(*tmp), sizeof(uint64_t));
    
    printf("%d\n", htonl(1));
    printf("%d\n", ntohl(16777216));
    
    uint64_t i = 16777216*64, j;
    printf("%d\n", i);
    j = htonl(i);
    printf("%d\n", j);
    i = ntohl(j);
    printf("%d\n", i);
    
    printf("sizeof(ipv4) = %d\n", sizeof("127.255.255.251"));
    
    return 0;
}