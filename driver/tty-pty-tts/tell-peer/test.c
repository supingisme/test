#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>


void sig_handler(int signum)
{
    printf("TEST: get SIGINT signal.\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, sig_handler);
    long int count = 0;
    
    char buf[256];
    char subfix[32] = {0};
    
    if(argc > 1)
    {
        strncpy(subfix, argv[1], sizeof(subfix));
    }
    while(1)
    {
        count++;
        fprintf(stderr, "TEST[%s]:%ld \n", subfix, count);
        fflush(stderr);
        
        fprintf(stdout, "TEST[%s]:%ld \n", subfix, count);
        fflush(stdout);
        
        usleep(1000000);
//
//        fscanf(stdin, "%s", buf);
//        
//        fprintf(stdout, "TEST[%s]: fprintf stdout buf: %s\n", subfix, buf);
//        fflush(stdout);
//        fprintf(stderr, "TEST[%s]: fprintf stderr buf: %s\n", subfix, buf);
//        fflush(stderr);
        
    }
}
