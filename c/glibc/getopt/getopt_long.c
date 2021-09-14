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

int getopt_long (int argc, char *const *argv, const char *shortopts, [Function]
const struct option *longopts, int *indexptr);

    Decode options from the vector argv (whose length is argc). The argument shortopts
    describes the short options to accept, just as it does in getopt. The argument longopts
    describes the long options to accept (see above).
    When getopt_long encounters a short option, it does the same thing that getopt
    would do: it returns the character code for the option, and stores the options argument
    (if it has one) in optarg.
    When getopt_long encounters a long option, it takes actions based on the flag and
    val felds of the defnition of that option.
    If flag is a null pointer, then getopt_long returns the contents of val to indicate
    which option it found. You should arrange distinct values in the val feld for options
    with diﬀerent meanings, so you can decode these values after getopt_long returns.
    If the long option is equivalent to a short option, you can use the short option's
    character code in val.
    If flag is not a null pointer, that means this option should just set a ﬂag in the
    program. The ﬂag is a variable of type int that you defne. Put the address of the
    ﬂag in the flag feld. Put in the val feld the value you would like this option to
    store in the ﬂag. In this case, getopt_long returns 0.
    For any long option, getopt_long tells you the index in the array longopts of the
    options defnition, by storing it into *indexptr. You can get the name of the option
    with longopts[*indexptr].name. So you can distinguish among long options either
    by the values in their val felds or by their indices. You can also distinguish in this
    way among long options that set ﬂags.
    When a long option has an argument, getopt_long puts the argument value in the
    variable optarg before returning. When the option has no argument, the value in
    optarg is a null pointer. This is how you can tell whether an optional argument was
    supplied.
    When getopt_long has no more options to handle, it returns -1, and leaves in the
    variable optind the index in argv of the next remaining argument.
    
    
    
        Since long option names were used before the getopt_long options was invented there
    are program interfaces which require programs to recognize options like ‘-option value'
    instead of ‘--option value'. To enable these programs to use the GNU getopt functionality
    there is one more function available.

int getopt_long_only (int argc, char *const *argv, const char *shortopts, const struct option *longopts, int *indexptr);

    The getopt_long_only function is equivalent to the getopt_long function but it
    allows to specify the user of the application to pass long options with only ‘-' instead
    of ‘--'. The ‘--' prefx is still recognized but instead of looking through the short
    options if a ‘-' is seen it is frst tried whether this parameter names a long option. If
    not, it is parsed as a short option.
    Assuming getopt_long_only is used starting an application with
    app -foo
    the getopt_long_only will frst look for a long option named ‘foo'. If this is not
    found, the short options ‘f', ‘o', and again ‘o' are recognized.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>




int main(int argc, char *argv[])
{
    int c;
    /* Flag set by ‘--verbose'. */
    static int verbose_flag;
    static struct option options[] =
    {
        /* These options set a ﬂag. */
        {"verbose", no_argument, &verbose_flag, 1},
        {"brief", no_argument, &verbose_flag, 0},
        /* These options don't set a ﬂag.
        We distinguish them by their indices. */
        {"add", no_argument, 0, 'a'},
        {"append", no_argument, 0, 'b'},
        {"create", required_argument, 0, 'c'},
        {"delete", required_argument, 0, 'd'},
        {"file", required_argument, 0, 'f'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };
    
    while (1)
    {
        /* getopt_long stores the option index here. */
        int option_index = 0;
        
        c = getopt_long (argc, argv, "a:b:c:d:f:h", options, &option_index);
        
        /* Detect the end of the options. */
        if (c == -1)
            break;
        switch (c)
        {
            case 0:
                /* If this option set a ﬂag, do nothing else now. */
                if (options[option_index].flag != 0)
                    break;
                printf ("0 option %s", options[option_index].name);
                
                if (optarg)
                    printf (" with arg %s", optarg);
                
                printf ("\n");
                break;
            case 'a':
                puts ("option -a\n");
                break;
            case 'b':
                puts ("option -b\n");
                break;
            case 'c':
                printf ("option -c with value ‘%s'\n", optarg);
                break;
            case 'd':
                printf ("option -d with value ‘%s'\n", optarg);
                break;
            case 'f':
                printf ("option -f with value ‘%s'\n", optarg);
                break;
            case 'h':
                printf ("option -h --help\n");
                break;
            case '?':
                /* getopt_long already printed an error message. */
                break;
            default:
                abort ();
        }
    }
    
    /* Instead of reporting ‘--verbose'
        and ‘--brief' as they are encountered,
        we report the fnal status resulting from them. */
    if (verbose_flag)
        puts ("verbose flag is set");
    
    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }
    
    exit (0);

    return 0;
}

/*

*/
