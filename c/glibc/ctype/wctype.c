/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>

/*
wctype_t wctype (const char *property);

$ grep wctype_t  wctype.h 
typedef unsigned long int wctype_t;


"alnum" "alpha" "cntrl" "digit"
"graph" "lower" "print" "punct"
"space" "upper" "xdigit"

*/

int
is_in_class1 (int c, const char *class)
{
    if (strcmp (class, "alnum") == 0)
        return isalnum (c);
    if (strcmp (class, "alpha") == 0)
        return isalpha (c);
    if (strcmp (class, "cntrl") == 0)
        return iscntrl (c);

    return 0;
}

int
is_in_class2 (int c, const char *class)
{
    wctype_t desc = wctype (class);
    //return desc ? iswctype ((wint_t) c, desc) : 0;
    return desc ? iswctype (btowc (c), desc) : 0;
}

int main()
{
    wchar_t str[] = L"C/C++ Python Swift Java Golang\n";
    wchar_t c;
    printf("sizeof c = %d\n", sizeof(c));
    wctype_t check  = wctype("upper");
    wctrans_t trans = wctrans("tolower");
    
    int i=0;
    
    while(str[i])
    {
        c = str[i];
        
        if(iswctype(c, check)) 
        {
            c = towctrans(c, trans);
        }
        
        putwchar(c);
        
        i++;
    }
    
    i=0;
    while(str[i])
    {
        c = str[i];
        
        if(is_in_class2 (c, "lower")) 
        {
            c = toupper(c);
        }
        
        putwchar(c);
        
        i++;
    }
	printf("c = %d\n", sizeof(c));    
    
    return 0;
}
