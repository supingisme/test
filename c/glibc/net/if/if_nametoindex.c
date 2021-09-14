/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:16 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:10 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*
16.4 Interface Naming
Each network interface has a name. This usually consists of a few letters that relate to the
type of interface, which may be followed by a number if there is more than one interface
of that type. Examples might be lo (the loopback interface) and eth0 (the frst Ethernet
interface).
Although such names are convenient for humans, it would be clumsy to have to use them
whenever a program needs to refer to an interface. In such situations an interface is referred
to by its index, which is an arbitrarily-assigned small positive integer.
The following functions, constants and data types are declared in the header fle
‘net/if.h’.
size_t IFNAMSIZ [Constant]
This constant defnes the maximum buﬀer size needed to hold an interface name,
including its terminating zero byte.
unsigned int if_nametoindex (const char *ifname) [Function]
This function yields the interface index corresponding to a particular name. If no
interface exists with the name given, it returns 0.

char * if_indextoname (unsigned int ifndex, char *ifname) [Function]
This function maps an interface index to its corresponding name. The returned name
is placed in the buﬀer pointed to by ifname, which must be at least IFNAMSIZ bytes in
length. If the index was invalid, the function’s return value is a null pointer, otherwise
it is ifname.
struct if_nameindex [Data Type]
This data type is used to hold the information about a single interface. It has the
following members:
unsigned int if_index;
This is the interface index.
char *if_name
This is the null-terminated index name.
struct if_nameindex * if_nameindex (void) [Function]
This function returns an array of if_nameindex structures, one for every interface
that is present. The end of the list is indicated by a structure with an interface of 0
and a null name pointer. If an error occurs, this function returns a null pointer.
The returned structure must be freed with if_freenameindex after use.

void if_freenameindex (struct if nameindex *ptr) [Function]
This function frees the structure returned by an earlier call to if_nameindex.
*/
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>

/*
$ ./a.out virbr0
interface virbr0: 3


*/

int main(int argc, char *argv[])
{   
    if(argc != 2)
    {
        printf("error: Usage: %s [interface name]\n", argv[0]);
        exit(1);
    }
    
    unsigned int if_index = if_nametoindex(argv[1]);
    if(if_index == 0)
    {
        perror("if_nametoindex");
        exit(1);
    }
    
    printf("interface %s: %d\n", argv[1], if_index);
    
    exit(1);
    
    
    
    return 0;
}
