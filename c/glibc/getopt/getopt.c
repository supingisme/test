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
/*

int opterr [Variable]
    If the value of this variable is nonzero, then getopt prints an error message to the
    standard error stream if it encounters an unknown option character or an option with
    a missing required argument. This is the default behavior. If you set this variable
    to zero, getopt does not print any messages, but it still returns the character ? to
    indicate an error.
    
int optopt [Variable]
    When getopt encounters an unknown option character or an option with a missing
    required argument, it stores that option character in this variable. You can use this
    for providing your own diagnostic messages.
    
int optind [Variable]
    This variable is set by getopt to the index of the next element of the argv array to
    be processed. Once getopt has found all of the option arguments, you can use this
    variable to determine where the remaining non-option arguments begin. The initial
    value of this variable is 1.
    
char * optarg [Variable]
    This variable is set by getopt to point at the value of the option argument, for those
    options that accept arguments.
    
int getopt (int argc, char **argv, const char *options) [Function]
    The getopt function gets the next option argument from the argument list specifed
    by the argv and argc arguments. Normally these values come directly from the
    arguments received by main.
    The options argument is a string that specifes the option characters that are valid
    for this program. An option character in this string can be followed by a colon (‘:’)
    to indicate that it takes a required argument. If an option character is followed by
    two colons (‘::’), its argument is optional; this is a GNU extension.
    getopt has three ways to deal with options that follow non-options argv elements.
    The special argument ‘--’ forces in all cases the end of option scanning.
        • The default is to permute the contents of argv while scanning it so that eventually
        all the non-options are at the end. This allows options to be given in any order,
        even with programs that were not written to expect this.
        • If the options argument string begins with a hyphen (‘-’), this is treated specially.
        It permits arguments that are not options to be returned as if they were associated
        with option character ‘\1’.
        • POSIX demands the following behavior: The frst non-option stops option
        processing. This mode is selected by either setting the environment variable
        POSIXLY_CORRECT or beginning the options argument string with a plus sign
        (‘+’).

*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;
    opterr = 0;
    
    while ((c = getopt (argc, argv, "abc:")) != -1)  
    switch (c)
    {
        case 'a':
            aflag = 1;
            break;
        case 'b':
            bflag = 1;
            break;
        case 'c':
            cvalue = optarg;
            break;
        case '?':
            if (optopt == 'c')
                fprintf (stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint (optopt))
                fprintf (stderr, "Unknown option '-%c'.\n", optopt);
            else
                fprintf (stderr, "Unknown option character '\\x%x'.\n", optopt);
            return 1;
        default:
            abort ();
    }
    printf ("aflag = %d, bflag = %d, cvalue = %s\n",aflag, bflag, cvalue);
    
    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    
    
    
    
    
    
    
    
    return 0;
}

/*
% testopt
aflag = 0, bflag = 0, cvalue = (null)
% testopt -a -b
aflag = 1, bflag = 1, cvalue = (null)
% testopt -ab
aflag = 1, bflag = 1, cvalue = (null)
% testopt -c foo
aflag = 0, bflag = 0, cvalue = foo
% testopt -cfoo
aflag = 0, bflag = 0, cvalue = foo
% testopt arg1
aflag = 0, bflag = 0, cvalue = (null)
Non-option argument arg1
% testopt -a arg1
aflag = 1, bflag = 0, cvalue = (null)
Non-option argument arg1
% testopt -c foo arg1
aflag = 0, bflag = 0, cvalue = foo
Non-option argument arg1
% testopt -a -- -b
aflag = 1, bflag = 0, cvalue = (null)
Non-option argument -b
% testopt -a -
aflag = 1, bflag = 0, cvalue = (null)
Non-option argument -
*/
