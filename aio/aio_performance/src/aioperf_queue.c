#include <stdio.h>
#include <stdlib.h>
#include "aioperf_manager.h"


void 
aioperf_queue_put(aioperf_queue_t *que, aioperf_io_task_t *io_task)
{
    if (que->size == 0) {
        que->head = io_task;
        que->end = io_task;
    } else {
        que->end->task_next = io_task;
        que->end = io_task;
    }
    que->size++;
}


aioperf_io_task_t *
aioperf_queue_get(aioperf_queue_t *que)
{
    aioperf_io_task_t *task;
    
    if (que->size == 0) {
        return NULL;
    } else {
        task = que->head;
        if (task) {
            if (!(que->head = task->task_next)) {
                que->end = NULL;
            }
        }
        que->size--;
        return task;
    }
}

int
aioperf_queue_init(aioperf_queue_t *que)
{
    que->end = NULL;
    que->head = NULL;
    que->size = 0;

    if (pthread_mutex_init(&que->lock, NULL) != 0) {
        printf("mutex init error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}

int
aioperf_queue_release(aioperf_queue_t *que)
{
    que->end = NULL;
    que->head = NULL;
    que->size = 0;

    if (pthread_mutex_destroy(&que->lock) != 0) {
        printf("mutex destroy error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
    
}

