#include <stdio.h>
#include <stdlib.h>
#include <eio.h>
#include "aioperf_manager.h"
#include "aioperf_eventfd.h"
#include "aioperf_eio.h"
#include "aioperf_queue.h"

int     aioperf_eio_eventfd = 0;

int
aioperf_eio_init(aioperf_manager_t *mgr)
{
    if (eio_init(aioperf_eio_want_poll, aioperf_eio_done_poll)) {
        printf("eio_init error\n");
        return AIOPERF_ERROR;
    }
    
    eio_set_min_parallel (mgr->io_thread_num);
    //eio_set_max_parallel (mgr->io_thread_num);
    eio_set_max_idle     (mgr->io_thread_num);
    eio_set_idle_timeout (10);

    return AIOPERF_OK;
}


void
aioperf_eio_release()
{
}

int
aioperf_eio_read(aioperf_io_task_t *io_task)
{
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;

    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;

    if (left_size > conf_info->buf_size) {
        if (!eio_read(io_task->fd, repository->buf, conf_info->buf_size, 
            io_task->offset, 0, aioperf_eio_callback, io_task)) {
            printf("eio_read error\n");
            return AIOPERF_ERROR;
        }
    } else {
        if (!eio_read(io_task->fd, repository->buf, left_size, 
            io_task->offset, 0, aioperf_eio_callback, io_task)) {
            printf("eio_read error\n");
            return AIOPERF_ERROR;
        }
    }

    return AIOPERF_OK;
}


int
aioperf_eio_write(aioperf_io_task_t *io_task)
{
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;


    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;

    if (left_size > conf_info->buf_size) {
        if (!eio_write(io_task->fd, repository->buf, conf_info->buf_size, 
            io_task->offset, 0, aioperf_eio_callback, io_task)) {
            printf("eio_write error\n");
            return AIOPERF_ERROR;
        }
    } else {
        if (!eio_write(io_task->fd, repository->buf, left_size, 
            io_task->offset, 0, aioperf_eio_callback, io_task)) {
            printf("eio_write error\n");
            return AIOPERF_ERROR;
        }
    }
    return AIOPERF_OK;
}

int
aioperf_eio_callback(eio_req *req)
{
    aioperf_io_task_t *io_task = NULL;

    io_task = (aioperf_io_task_t *)req->data;

    pthread_mutex_lock(&io_task->repository->que.lock);
    aioperf_queue_put(&io_task->repository->que, io_task);
    pthread_mutex_unlock(&io_task->repository->que.lock);

    aioperf_eventfd_write(io_task->repository->signal_fd);
    return AIOPERF_OK;
}

void
aioperf_eio_want_poll(void)
{
    if (aioperf_eventfd_write(aioperf_eio_eventfd) < 0) {
        printf("eio evfd write error\n");
    }
}

void
aioperf_eio_done_poll(void)
{
    unsigned long   val = 0;
    
    if (aioperf_eventfd_read(aioperf_eio_eventfd, &val) != AIOPERF_OK) {
        printf("eio evfd read error\n");
    }
}

int
aioperf_eio_poll(void)
{   
    return eio_poll();
}

int
aioperf_eio_handler(aioperf_repository_t *repository)
{
    aioperf_queue_t    *que = NULL;
    unsigned long       val = 0;

    if (aioperf_eventfd_read(repository->signal_fd, &val) != AIOPERF_OK) {
        printf("recv signal error\n");
        return AIOPERF_ERROR;
    }
    
    que = &repository->que;

    while (que->size) {
        pthread_mutex_lock(&que->lock);
        if (aioperf_queue_get(que)) {;
            repository->io_finish_num++;
        }
        pthread_mutex_unlock(&que->lock);

    }

    return AIOPERF_OK;

}
