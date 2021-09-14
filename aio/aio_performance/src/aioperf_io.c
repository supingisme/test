#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "aioperf_manager.h"
#include "aioperf_eventfd.h"
#include "aioperf_io.h"
#include "aioperf_queue.h"


int
aioperf_io_read(aioperf_io_task_t *io_task)
{
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;
    ssize_t                  ret = 0;

    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;

    if (left_size > conf_info->buf_size) {
        if ((ret = pread(io_task->fd, repository->buf, conf_info->buf_size, 
            io_task->offset)) < 0) {
            printf("pread error\n");
        } 
    } else {
        if ((ret = pread(io_task->fd, repository->buf, left_size, 
            io_task->offset)) < 0) {
            printf("pread error\n");
        } 
    }

    pthread_mutex_lock(&io_task->repository->que.lock);
    aioperf_queue_put(&io_task->repository->que, io_task);
    pthread_mutex_unlock(&io_task->repository->que.lock);

    aioperf_eventfd_write(io_task->repository->signal_fd);

    return AIOPERF_OK;
}

int
aioperf_io_write(aioperf_io_task_t *io_task)
{
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;
    int                      ret = 0;
    
    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;

    if (left_size > conf_info->buf_size) {
        if ((ret = pwrite(io_task->fd, repository->buf, conf_info->buf_size, 
            io_task->offset)) != conf_info->buf_size) {
            printf("pwrite error\n");
        }
    } else {
        if ((ret = pwrite(io_task->fd, repository->buf, left_size, 
            io_task->offset)) != left_size) {
            printf("pwrite error\n");
        }
    }

    pthread_mutex_lock(&io_task->repository->que.lock);
    aioperf_queue_put(&io_task->repository->que, io_task);
    pthread_mutex_unlock(&io_task->repository->que.lock);

    aioperf_eventfd_write(io_task->repository->signal_fd);

    return AIOPERF_OK;
}

int
aioperf_io_handler(aioperf_repository_t *repository)
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