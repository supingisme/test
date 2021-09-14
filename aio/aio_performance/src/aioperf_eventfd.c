#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/eventfd.h>
#include "aioperf_manager.h"
#include "aioperf_eventfd.h"

int
aioperf_eventfd_create(int *evfd)
{
    if ((*evfd = eventfd(0, EFD_NONBLOCK)) < 0) {
        printf("eventfd error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}

int
aioperf_eventfd_read(int evfd, unsigned long *val)
{
    if (read(evfd, val, 8) <= 0) {
        printf("read eventfd error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}

int
aioperf_eventfd_write(int evfd)
{
    unsigned long val = 8;

    if (write(evfd, &val, 8) <= 0) {
        printf("write eventfd error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}

void
aioperf_eventfd_release(int evfd)
{
    if (close(evfd) < 0) {
        printf("eventfd close error\n");
    }
}

void
aioperf_eventfd_handler(aioperf_worker_t *worker)
{        
    unsigned long   val = 0;
    
    aioperf_eventfd_read(worker->evfd, &val);
    worker->worker_release_start = 1;
    return;
}

