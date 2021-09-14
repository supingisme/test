#ifndef __ENTIRY_H
#define __ENTIRY_H 1

#include <stdbool.h>

#include "list.h"
#include "xml.h"

typedef enum  {
    EXE_READY,
    EXE_RUNNING,
    EXE_EXIT,
    EXE_ERROR,
}exe_status_t;


typedef enum {
    OPT_KILL,
    OPT_REBOOT,
}exe_operate_t;


struct execution {
    unsigned long int exeid;
    exe_status_t status;    //开启定时器轮询该进程的状态

    int linux_pid;  //linux内核中的进程ID
    
    char *path;
    char *name;
    char *args;
    
    struct list_head list;
};

/*  */
//struct execution_operation {
//    exe_operate_t operation;
//    unsigned long int exeid;
//};


extern struct list_head execution_ready_list;

void load_execution_ready_list_from_xml(xmlXPathContextPtr cfgctx);



#endif //__ENTIRY_H

