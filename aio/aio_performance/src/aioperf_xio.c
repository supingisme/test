#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "aioperf_manager.h"
#include "aioperf_eventfd.h"
#include "aioperf_xio.h"
#include "aioperf_queue.h"


int
aioperf_xio_mgr_init(aioperf_manager_t *mgr)
{
    xio_manager_t       *xio_mgr = NULL;
    xio_err_t            xio_err;
    xio_property_t       xio_property;

    memset(&xio_property, 0, sizeof(xio_property_t));
    memset(&xio_err, 0, sizeof(xio_err));

    xio_property.max_task_num = AIOPERF_QUEUE_SIZE;
    xio_property.max_thread_num = mgr->io_thread_num;
    xio_property.min_thread_num = 2;
    xio_property.run_thread_num = 4;
    xio_property.idle_time = 5;

    if (!(xio_mgr = xio_init(&xio_property, &xio_err))) {
        printf("xio_init error\n");
        return AIOPERF_ERROR;
    }

    mgr->data = xio_mgr;

    if (xio_reg_exec_func(xio_mgr, XIO_IO_PREAD, aioperf_xio_io_read, &xio_err) 
        != XIO_OK) {
        printf("xio_register read func error\n");
        return AIOPERF_ERROR;
    }

    if (xio_reg_exec_func(xio_mgr, XIO_IO_PWRITE, aioperf_xio_io_write, &xio_err) 
        != XIO_OK) {
        printf("xio_register write func error\n");
        return AIOPERF_ERROR;
    }
    
    return AIOPERF_OK;
}

void 
aioperf_xio_mgr_release(aioperf_manager_t *mgr)
{
    xio_manager_t   *xio_mgr = NULL;
    xio_err_t        err;
    
    if (!mgr->data) {
        printf("xio_mgr NULL\n");
        return;
    }

    xio_mgr = (xio_manager_t *)mgr->data;

    memset(&err, 0, sizeof(err));
    xio_release(xio_mgr, &err);
}


int
aioperf_xio_read(aioperf_io_task_t *io_task)
{
    xio_task_t       xio_task;
    xio_manager_t   *xio_mgr = NULL;

    xio_mgr = (xio_manager_t *)io_task->repository->mgr->data;

    xio_task.call_back = aioperf_xio_io_callback;
    xio_task.io_type = XIO_IO_PREAD;
    xio_task.user_data = io_task;
    xio_task.xio_mgr = xio_mgr;
    xio_task_submit(&xio_task);
    
    return AIOPERF_OK;
}

int
aioperf_xio_write(aioperf_io_task_t *io_task)
{
    xio_task_t      xio_task;
    xio_manager_t   *xio_mgr = NULL;

    xio_mgr = (xio_manager_t *)io_task->repository->mgr->data;

    xio_task.call_back = aioperf_xio_io_callback;
    xio_task.io_type = XIO_IO_PWRITE;
    xio_task.user_data = io_task;
    xio_task.xio_mgr = xio_mgr;
    xio_task_submit(&xio_task);
    
    return AIOPERF_OK;
}


int
aioperf_xio_handler(aioperf_repository_t *repository)
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
    return AIOPERF_OK;   
}


int
aioperf_xio_io_read(void *task)
{
    aioperf_io_task_t       *io_task = NULL;
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;
    size_t                   ret = 0;

    io_task = (aioperf_io_task_t *)task;
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
    
    return AIOPERF_OK;
}

int
aioperf_xio_io_write(void *task)
{
    aioperf_io_task_t       *io_task = NULL;
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;
    size_t                   ret = 0;

    io_task = (aioperf_io_task_t *)task;
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
    return AIOPERF_OK;
}


int
aioperf_xio_io_callback(void *task)
{
    aioperf_io_task_t *io_task = NULL;

    io_task = (aioperf_io_task_t *)task;

    pthread_mutex_lock(&io_task->repository->que.lock);
    aioperf_queue_put(&io_task->repository->que, io_task);
    pthread_mutex_unlock(&io_task->repository->que.lock);

    aioperf_eventfd_write(io_task->repository->signal_fd);
    return AIOPERF_OK;
}

