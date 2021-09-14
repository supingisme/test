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
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define debug() printf("%s:%d\n", __func__, __LINE__)

enum ARG_FLAG{
    NO_ARG = no_argument, /*0*/
    HAVE_ARG = required_argument, /*1*/
};

enum Opt_type_e{
    VERSION,
    HELP,
    
};

int main(int argc, char *argv[])
{
    int c;
    static int verbose_flag = -1;
    
    struct option options[] =
    {
        {"verbose", NO_ARG,     &verbose_flag,  1},
        {"brief",   NO_ARG,     &verbose_flag,  0},
        {"version", HAVE_ARG,   0,              'v'},
        {"help",    NO_ARG,     0,              'h'},
        {0,0,0,0},
    };
    
    while (1)
    {
        /* getopt_long stores the option index here. */
        int option_index = 0;
        debug();
        c = getopt_long (argc, argv, "v:h", options, &option_index);
        debug();
        if(c < 0)
        {
            break;
        }
        printf("c = %c:%d, %d\n", c, c, option_index);
        
        switch (c)
        {
            case 0:
                debug();
                /* If this option set a ﬂag, do nothing else now. */
                if (options[option_index].flag != 0)
                    break;
                printf ("0 option %s", options[option_index].name);
                debug();
                if (optarg)
                    printf (" with arg %s", optarg);
                
                printf ("\n");debug();
                break;
            case 'v':
                printf ("option -v with value ‘%s'\n", optarg);
                break;
            case 'h':
                printf ("option -h --help\n");
                break;
            case '?':
                /* getopt_long already printed an error message. */
                printf ("option ??????????\n");
                break;
            default:
                abort ();
        }
    }
    
    if (verbose_flag == 1)
    {
        puts ("verbose flag is set");
    }
    else if(verbose_flag == 0)
    {
        puts ("verbose flag is not set");
    }
    
    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }

    return 0;
}


