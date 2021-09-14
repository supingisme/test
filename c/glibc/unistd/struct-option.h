/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/**
struct option [Data Type]
    This structure describes a single long option name for the sake of getopt_long. The
    argument longopts must be an array of these structures, one for each long option.
    Terminate the array with an element containing all zeros.
    The struct option structure has these felds:
    const char *name
        This feld is the name of the option. It is a string.
    int has_arg
        This feld says whether the option takes an argument. It is an integer,
        and there are three legitimate values: no_argument, required_argument
        and optional_argument.
    int *flag
    int val These felds control how to report or act on the option when it occurs.
        If flag is a null pointer, then the val is a value which identifes this
        option. Often these values are chosen to uniquely identify particular long
        options.
        If flag is not a null pointer, it should be the address of an int variable
        which is the ﬂag for this option. The value in val is the value to store in
        the ﬂag to indicate that the option was seen.

*/
#include <getopt.h>

struct option{
    const char *name;
    int has_arg;
    int *flag;
    int val;
};