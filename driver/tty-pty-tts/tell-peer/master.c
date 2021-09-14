#include <stdio.h>
#include <signal.h>
#include <getopt.h>

#include "ptsTalk.h"


struct pts_process process1,process2,process3;

int slaves_connect_callback(struct pts_id* pts, pts_stat stat)
{
    printf("A slave pts handle.\n");

    switch(stat)
    {
        case PTS_ON:
            pts_bind_process(pts, &process1);
            break;
        
        case PTS_OFF:
            pts_reset_process(&process1);
            break;
    }   
    return 0;
}

int main(int argc, char *argv[])
{
    struct pts_id master;
    pts_master("123", &master, &slaves_connect_callback);

    int i =0 ;

    pts_vexe(&master, &process1, "./test %d", i++);
//    pts_vexe(&master, &process2, "./test %d", i++);
//    pts_vexe(&process3, "./test %d", i++);
    
    while(1)
    {
        printf("while1...\n");
        sleep(2);
    }
    return 0;
}
