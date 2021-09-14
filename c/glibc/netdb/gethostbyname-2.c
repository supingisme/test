/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:17 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:43:21 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/*	struct hostent * gethostbyname (const char *name) [Function]
 *	The gethostbyname function returns information about the host named name. If the
 *	lookup fails, it returns a null pointer.
 *
 *	y are BSD features, defned unconditionally if y
 *	‘netdb.h’.
 *	struct hostent [Data Type]
 *	This data type is used to represent an entry in the hosts database. It has the following
 *	members:
 *	char *h_name
 *	This is the “ofcial” name of the host.
 *	char **h_aliases
 *	These are alternative names for the host, represented as a null-terminated
 *	vector of strings.
 *	int h_addrtype
 *	This is the host address type; in practice, its value is always either AF_
 *	INET or AF_INET6, with the latter being used for IPv6 hosts. In principle
 *	other kinds of addresses could be represented in the database as well as
 *	Internet addresses; if this were done, you might fnd a value in this feld
 *	other than AF_INET or AF_INET6. See Section 16.3 [Socket Addresses],
 *	page 391.
 *	int h_length
 *	This is the length, in bytes, of each address.
 *	char **h_addr_list
 *	This is the vector of addresses for the host. (Recall that the host might
 *	be connected to multiple networks and have diﬀerent addresses on each
 *	one.) The vector is terminated by a null pointer.
 *	char *h_addr
 *	This is a synonym for h_addr_list[0]; in other words, it is the frst host
 *	address.
 *
 */
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>

void errorHandler(const char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc, char* argv[]){
    if(argc =!2){
        printf("Usage: %s <addr> \n", argv[0]);
        exit(1);
    }

    struct ostent* host = gethostbyname(argv[1]);
    if(!host){
        errorHandler("gethostbyname() error!");
    }

    printf("Official name:%s \n", host->h_name);

    for(int i=0;host->h_aliases[i];i++){
        printf("Aliases %d: %s \n", i+1, host->h_aliases[i]);
    }

    if(host->h_addrtype == AF_INET){
        printf("Address type: AF_INET \n");
    }
    else{
        printf("Address type: AF_INET6 \n");
    }

    for(int i=0;host->h_addr_list[i];i++){
        printf("IP address %d: %s \n", i+1, inet_ntoa(*(in_addr*)host->h_addr_list[i]));
    }

    return 0;
}
