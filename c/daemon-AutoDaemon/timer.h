#ifndef __TIMER_H
#define __TIMER_H 1


#include <sys/time.h>
#include <stdbool.h>

#include "list.h"



struct timer_node {
    unsigned long int timerid;

    struct timeval timeout;

    struct timeval interval;
    bool isloop;
    void *arg;
    void (*callback)(void *arg);
    
    struct list_head list;
};



void timer_initial();

unsigned long int timer_new(bool is_loop, void (*callback)(void *arg), void *arg, long sec, long usec);

int timer_del(unsigned long int timerid);

void test_timer();


#endif //__TIMER_H
