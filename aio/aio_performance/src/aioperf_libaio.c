#include <stdio.h>
#include <stdlib.h>
#include <libaio.h>
#include "aioperf_manager.h"
#include "aioperf_eventfd.h"
#include "aioperf_libaio.h"
#include "aioperf_queue.h"


int
aioperf_libaio_init(aioperf_manager_t *mgr)
{
    io_context_t    *ctx = NULL;

    if (!(ctx = (io_context_t *)aioperf_memory_pool_alloc(mgr->pool, 
        sizeof(io_context_t)))) {
        printf("alloc error\n");
        return AIOPERF_ERROR;
    }

    mgr->data = ctx;

    aioperf_memory_set(ctx, 0, sizeof(io_context_t));

    if (io_setup(AIOPERF_LIBAIO_QUEUE_SIZE, ctx) < 0) {
        printf("io_setup error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}

void
aioperf_libaio_release(aioperf_manager_t *mgr)
{
    io_destroy(*(io_context_t *)mgr->data);
}


int
aioperf_libaio_read(aioperf_io_task_t *io_task)
{
    struct iocb             *libaio_req = NULL;
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;
    unsigned int             count = 0;

    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;
        
    if (!(libaio_req = (struct iocb *)aioperf_memory_pool_alloc(repository->pool, 
        sizeof(struct iocb)))) {
        printf("alloc error\n");
        return AIOPERF_ERROR;
    }

    if (!(io_task->buf = (char *)aioperf_memory_memalign(512, 
        conf_info->buf_size))) {
        printf("memory memalign error\n");
    }
    

    io_task->data = libaio_req;

    if (left_size > conf_info->buf_size) {
        count = conf_info->buf_size;
    } else {
        count = left_size;
    }

    io_prep_pread(libaio_req, io_task->fd, io_task->buf, count, 
        io_task->offset);
    libaio_req->data = io_task;

    io_set_eventfd(libaio_req, io_task->repository->signal_fd);
    
    if (io_submit(*(io_context_t *)repository->mgr->data, 1, &libaio_req) < 0) {
        printf("io_submit error\n");
    }

    return AIOPERF_OK;
}

int
aioperf_libaio_write(aioperf_io_task_t *io_task)
{
    struct iocb             *libaio_req = NULL;
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    unsigned long            left_size = 0;
    unsigned int             count = 0;

    repository = io_task->repository;
    conf_info = repository->conf_info;
    left_size = io_task->file_size - io_task->offset;
        
    if (!(libaio_req = (struct iocb *)aioperf_memory_pool_alloc(repository->pool, 
        sizeof(struct iocb)))) {
        printf("alloc error\n");
        return AIOPERF_ERROR;
    }

    aioperf_memory_set(libaio_req, 0, sizeof(struct iocb));

    io_task->data = libaio_req;
    

    if (left_size > conf_info->buf_size) {
        count = conf_info->buf_size;
    } else {
        count = left_size;
    }

    io_prep_pwrite(libaio_req, io_task->fd, repository->buf, count, 
        io_task->offset);
    libaio_req->data = io_task;
    
    io_set_eventfd(libaio_req, io_task->repository->signal_fd);
    
    
    if (io_submit(*(io_context_t *)repository->mgr->data, 1, &libaio_req) < 0) {
        printf("io_submit error\n");
    }

    return AIOPERF_OK;
}

void
aioperf_libaio_efd_handler(aioperf_repository_t *repository)
{
    aioperf_io_task_t   *io_task = NULL;
    struct io_event      event[1000];
    unsigned long        val = 0;
    int                  event_num = 0;
    struct timespec      ts;
    int                  i = 0;

    ts.tv_sec = 0;
    ts.tv_nsec = 0;
    
    if (aioperf_eventfd_read(repository->signal_fd, &val) != AIOPERF_OK) {
        printf("recv signal error\n");
        return;
    }
    
    while (val) {
        event_num = io_getevents(*(io_context_t *)repository->mgr->data, 1, 
            1000, event, &ts);
        if (event_num == 0) {
            return;
        }
        
        if (event_num > 0) {
            val -= event_num;
            for(i = 0; i < event_num; i++) {
                io_task = (aioperf_io_task_t *)(char *)event[i].data;
                aioperf_memory_free(io_task->buf);
                
                pthread_mutex_lock(&io_task->repository->que.lock);
                aioperf_queue_put(&io_task->repository->que, io_task);
                pthread_mutex_unlock(&io_task->repository->que.lock);

                aioperf_eventfd_write(io_task->repository->signal_fd2);
            }
        }
    }
}


void
aioperf_libaio_efd2_handler(aioperf_repository_t *repository)
{
    aioperf_queue_t    *que = NULL;
    unsigned long       val = 0;

    if (aioperf_eventfd_read(repository->signal_fd2, &val) != AIOPERF_OK) {
        printf("recv signal2 error\n");
        return;
    }
    
    que = &repository->que;

    while (que->size) {
        pthread_mutex_lock(&que->lock);
        if (aioperf_queue_get(que)) {;
            repository->io_finish_num++;
        }
        pthread_mutex_unlock(&que->lock);

    }

}
