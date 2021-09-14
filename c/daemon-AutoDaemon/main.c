#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <libgen.h>
#include <string.h>
#include <malloc.h>

#include "list.h"
#include "log.h"
#include "xml.h"
#include "execute.h"
#include "timer.h"




void usage(char *command) {
    printf("Usage: %s {[option] <value>}*n\n", basename(command?command:"daemon"));
    printf("Automated daemon tool.\n");
    printf("\n");
    printf("%4s, %10s \t %s\n", "-v", "--version", "Version");
    printf("%4s, %10s \t %s\n", "-h", "--help", "usage of command");
    printf("%4s, %10s \t %s\n", "-l", "--log-level", "set log level [0-3]");
    printf("%4s, %10s \t %s\n", "-c", "--config-file", "config XML file");
    printf("%4s, %10s \t %s\n", "-C", "--gen-cfg-file", "generate default config XML file");
    printf("\n");

    exit(0);
}

void version(char *command) {

    printf("%s 0.0.1\n", basename(command?command:"daemon"));

    exit(0);
}

void parse_config_xml(char *filename) {
    int ret = access(filename, F_OK|R_OK);
    if(ret != 0) {
        error("config file doesn't exist. -c %s\n", filename);
        usage("XXX");
    }

    
    xmlDocPtr cfgdoc = xml_doc((xmlChar*)filename); 
    xmlXPathContextPtr cfgctx = xml_context(cfgdoc);

    load_execution_ready_list_from_xml(cfgctx);
    
    close_xml(cfgdoc);    
}

void gen_default_config_xml(char *filename) {
    int ret = access(filename, F_OK);
    if(ret == 0) {
        error("file name already exist. -C %s\n", filename);
        usage("XXX");
    }
    FILE *fp = fopen(filename, "w");

    int line = 0;
    while(default_config_xml_file[line]) {
        fprintf(fp, "%s\n", default_config_xml_file[line]);
        line++;
    }

    fclose(fp);
}

void parse_args(int argc, char *argv[]) {
    
    int c;
    
    static struct option options[] = {
        {"version", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {"log-level", required_argument, 0, 'l'},
        {"config-file", required_argument, 0, 'c'},
        {"gen-config-file", required_argument, 0, 'C'},
        {0, 0, 0, 0}
    };
        
    while (1) {
        /* getopt_long stores the option index here. */
        int option_index = 0;
        
        c = getopt_long (argc, argv, "vhl:c:C:", options, &option_index);
        
        /* Detect the end of the options. */
        if (c == -1) {
            break;
        }
        switch (c) {
            case 'v':
                version(argv[0]);
                break;
            case 'h':
                usage(argv[0]);
                break;
            case 'l':
                set_log_level(atoi(optarg));
                break;
            case 'c':
                parse_config_xml(optarg);
                break;
            case 'C':
                gen_default_config_xml(optarg);
                break;
            case '?':
                /* getopt_long already printed an error message. */
                break;
            default:
                abort ();
                exit(0);
        }
    }    /* Print any remaining command line arguments (not options). */
}

void check_params() {
    
    if(list_empty(&execution_ready_list)) {
        error("must has exe label in config XML file. generate XML with -C filename.\n");
        exit(0);
    }
    struct execution *exe;
    list_for_each_entry(exe, &execution_ready_list, list) {
        info("%s/%s %s\n", exe->path, exe->name, exe->args);
    }
}





int main(int argc, char *argv[]) 
{
    parse_args(argc, argv);

    check_params();

    timer_initial();

//    test_timer();

    while(1) {
        sleep(1);
    }

    return 0;
}
