#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <aio.h>
#include "aioperf_manager.h"
#include "aioperf_eventfd.h"
#include "aioperf_aio.h"
#include "aioperf_queue.h"

int
aioperf_aio_init(aioperf_manager_t *mgr)
{
    struct aioinit  *aio_mgr = NULL;

    if (!(aio_mgr = (struct aioinit *)aioperf_memory_pool_alloc(mgr->pool, 
        sizeof(struct aioinit)))) {
        printf("alloc error\n");
        return AIOPERF_ERROR;
    }


    aioperf_memory_set(aio_mgr, 0, sizeof(struct aioinit));
    
    aio_mgr->aio_threads = mgr->io_thread_num;
    aio_mgr->aio_num = AIOPERF_QUEUE_SIZE;
    aio_mgr->aio_idle_time = 5;
    
    mgr->data = aio_mgr;

    aio_init(aio_mgr);

    return AIOPERF_OK;
}


void
aioperf_aio_release(aioperf_manager_t *mgr)
{
    mgr->data = NULL;
}


int
aioperf_aio_write(aioperf_io_task_t *io_task)
{
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;


    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;

    if (left_size > conf_info->buf_size) {
        io_task->aio_req.aio_nbytes = conf_info->buf_size;
    } else {
        io_task->aio_req.aio_nbytes = left_size;
    }

    io_task->aio_req.aio_fildes = io_task->fd;
    io_task->aio_req.aio_buf = io_task->repository->buf;
    io_task->aio_req.aio_offset = io_task->offset;
    
    io_task->aio_req.aio_sigevent.sigev_notify = SIGEV_THREAD;
    io_task->aio_req.aio_sigevent.sigev_notify_function = aioperf_aio_callback;
    io_task->aio_req.aio_sigevent.sigev_notify_attributes = NULL;
    io_task->aio_req.aio_sigevent.sigev_value.sival_ptr = io_task;
    
    if (aio_write(&io_task->aio_req) < 0) {
        printf("aio write error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}

int
aioperf_aio_read(aioperf_io_task_t *io_task)
{
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;


    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;

    if (left_size > conf_info->buf_size) {
        io_task->aio_req.aio_nbytes = conf_info->buf_size;
    } else {
        io_task->aio_req.aio_nbytes = left_size;
    }

    io_task->aio_req.aio_fildes = io_task->fd;
    io_task->aio_req.aio_buf = io_task->repository->buf;
    io_task->aio_req.aio_offset = io_task->offset;
    
    io_task->aio_req.aio_sigevent.sigev_notify = SIGEV_THREAD;
    io_task->aio_req.aio_sigevent.sigev_notify_function = aioperf_aio_callback;
    io_task->aio_req.aio_sigevent.sigev_notify_attributes = NULL;
    io_task->aio_req.aio_sigevent.sigev_value.sival_ptr = io_task;
    
    if (aio_read(&io_task->aio_req) < 0) {
        printf("aio write error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}


void
aioperf_aio_callback(sigval_t sig)
{
    aioperf_io_task_t   *io_task = NULL;
    struct aiocb        *aio_req = NULL;
    int                  ret = 0;

    io_task = sig.sival_ptr;
    aio_req = &io_task->aio_req;
    
    ret = aio_error(aio_req);
    if (ret != 0) {
        printf("aio io error\n");
    }

    pthread_mutex_lock(&io_task->repository->que.lock);
    aioperf_queue_put(&io_task->repository->que, io_task);
    pthread_mutex_unlock(&io_task->repository->que.lock);

    aioperf_eventfd_write(io_task->repository->signal_fd);
}


int
aioperf_aio_handler(aioperf_repository_t *repository)
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

