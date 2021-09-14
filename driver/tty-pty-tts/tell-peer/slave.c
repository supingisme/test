#include <stdio.h>
#include <getopt.h>

#include "ptsTalk.h"

static struct slave_args_s {
    char unsocketpath[256];
}slave_args;

void slave_help(int argc, char *argv[])
{
    printf("\n");
    printf("\033[1mNAME\033[m\n");
    printf(" %s\n", argv[0]);
    printf("\033[1mUSAGE\033[m\n");
    printf("   -h [--help] help, usage\n");
    printf("   -s [--unix-sockpath] <path>\n");
    printf("      this path same as pts_master(name, master, fn)\n");
    printf("                                   ^^^^ \n");
    exit(1);
}

void get_args(int argc, char *argv[])
{
    if(argc <= 1)
    {
        slave_help(argc, argv);
    }
    char c;
    struct option options[] =
    {
        {"unix-sockpath",   required_argument,  0,  's'},
        {"help",            no_argument,        0,  'h'},
        {0,0,0,0},
    };
        
    while (1)
    {
        /* getopt_long stores the option index here. */
        int option_index = 0;
        c = getopt_long(argc, argv, "s:h", options, &option_index);
        if(c < 0)
        {
            break;
        }
        
        switch (c)
        {
            case 's':
                strcpy(slave_args.unsocketpath, optarg);
                break;
            case 'h':
            case '?':
            default:
                slave_help(argc, argv);
                break;
        }
    }
    
    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        slave_help(argc, argv);
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }
}

int main(int argc, char *argv[])
{   
    get_args(argc, argv);
    
    struct pts_id master;
    
    pts_slave(slave_args.unsocketpath, &master);

    pts_print(&master, ">> I'm a slave PTS connect to you.\n");
    
    while(1)
    {
        sleep(2);
    }
    return 0;
}
