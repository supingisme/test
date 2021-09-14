#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdint.h>
#include <unistd.h>

#include "getpars.h"


#define debug() printf("%s:%d\n", __func__, __LINE__)

enum ARG_FLAG{
    NO_ARG = no_argument, /*0*/
    HAVE_ARG = required_argument, /*1*/
};


static const char* usage[] = {
"Usage: ",
"   -v [--version] Check the version of command",
"   -h [--help] Check the usage of command",
"   -u [--usage] Check the usage of command",
"   -c [--cellid] Set the cell id",
NULL,
};

static const char* version[] = {
"Version-1.0.0  Copyright@Sylincom",
NULL,
};

#define VERSION         "version"
#define VERSION_OPT     'v'
#define HELP            "help"
#define HELP_OPT        'h'
#define USAGE           "usage"
#define USAGE_OPT       'u'
#define POSSIBLE_OPT    '?'
#define CELLID          "cellid"
#define CELLID_OPT      'c'

#ifdef __cplusplus 
extern "C" {
#endif

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        pagedoc(usage);
        exit(0);
    }

    int c;
    static int verbose_flag = -1;

    int cell_id;

    struct option options[] =
    {
        {"verbose", NO_ARG, &verbose_flag,  1},
        {"brief",   NO_ARG, &verbose_flag,  0},
        {VERSION,   NO_ARG, 0,    VERSION_OPT},
        {HELP,      NO_ARG, 0,              HELP_OPT},
        {USAGE,     NO_ARG, 0,              USAGE_OPT},
        {CELLID,     HAVE_ARG, 0,              CELLID_OPT},
        {0,0,0,0},
    };

    while (1)
    {
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "vhuc:", options, &option_index);

        if(c < 0)
        {
            break;
        }
        //printf("c = %c:%d, %d\n", c, c, option_index);
        
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
            case VERSION_OPT:
                pagedoc(version);
                break;
            case HELP_OPT:
            case USAGE_OPT:
                pagedoc(usage);
                break;
            case CELLID_OPT:
                cell_id = atoi(optarg);
                printf("cell_id = %d\n", cell_id);
                break;
            case POSSIBLE_OPT:
                /* getopt_long already printed an error message. */
                //printf ("option ??????????\n");
                break;
            default:
                //abort ();
                break;
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





#ifdef __cplusplus 
}
#endif


