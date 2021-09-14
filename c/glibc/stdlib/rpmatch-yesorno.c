/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <libintl.h>


#define false   -1
#define true    0

/*
$ gcc rpmatch.c -w
$ ./a.out 
Do you really want to do this? y
true
$ ./a.out 
Do you really want to do this? n
false
$ 
*/

int main()
{
    char *line = malloc(256);
    size_t len;
    
    /* Use a safe default. */
    _Bool doit = false;
    fputs (gettext ("Do you really want to do this?[Y/N]: "), stdout);
    fflush (stdout);
    /* Prepare the getline call. */
    line = NULL;
    len = 0;
    while (getline (&line, &len, stdin) >= 0)
    {
        /* Check the response. */
        int res = rpmatch (line);
        if (res >= 0)
        {
            /* We got a defnitive answer. */
            if (res > 0)
                doit = true;
            break;
        }
    }
    /* Free what getline allocated. */
    free (line);
    
    printf("%s\n", doit==true?"Yes, you select YES":"No, You select NO");
    
    return 0;
}
