#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include "aioperf_manager.h"
#include "aioperf_xio.h"
#include "aioperf_eio.h"
#include "aioperf_aio.h"
#include "aioperf_libaio.h"
#include "aioperf_eventfd.h"
#include "aioperf_io.h"

extern int aio_type;

int
aioperf_general_init(aioperf_manager_t *mgr)
{
    switch (aio_type) {
        case USE_AIO:
            if (aioperf_aio_init(mgr) != AIOPERF_OK) {
                printf("aio init error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_XIO:
            if (aioperf_xio_mgr_init(mgr) != AIOPERF_OK) {
                printf("xio init error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_LIBAIO:
            if (aioperf_libaio_init(mgr) != AIOPERF_OK) {
                printf("libaio init error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_LIBEIO:
            if (aioperf_eio_init(mgr) != AIOPERF_OK) {
                printf("eio init error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_IO:
            break;
        default:
            return AIOPERF_ERROR;
            break;
         

    }

    return AIOPERF_OK;
}

void
aioperf_general_release(aioperf_manager_t *mgr)
{
    switch (aio_type) {
        case USE_AIO:
            aioperf_aio_release(mgr);
            break;
        case USE_XIO:
            aioperf_xio_mgr_release(mgr);    
            break;
        case USE_LIBAIO:
            aioperf_libaio_release(mgr);
            break;
        case USE_LIBEIO:
            aioperf_eio_release();
            break;
        case USE_IO:
            break;
        default:
            break;
         

    }
}


int
aioperf_general_repository_init(aioperf_manager_t *mgr)
{
    switch (aio_type) {
        case USE_AIO:
            break;
        case USE_XIO:
            break;
        case USE_LIBAIO:
            break;
        case USE_LIBEIO:
            break;
        case USE_IO:
            break;
        default:
            return AIOPERF_ERROR;
            break;

    }

    return AIOPERF_OK;
}

void
aioperf_general_repository_release(aioperf_manager_t *mgr)
{
    switch (aio_type) {
        case USE_AIO:
            break;
        case USE_XIO:
            break;
        case USE_LIBAIO:
            break;
        case USE_LIBEIO:
            break;
        case USE_IO:
            break;
        default:
            break;
         

    }
}


int
aioperf_general_read(aioperf_io_task_t *io_task)
{
    switch (aio_type) {
        case USE_AIO:
            if (aioperf_aio_read(io_task) != AIOPERF_OK) {
                printf("aio read error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_XIO:
            if (aioperf_xio_read(io_task) != AIOPERF_OK) {
                printf("xio read error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_LIBAIO:
            if (aioperf_libaio_read(io_task) != AIOPERF_OK) {
                printf("libaio read error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_LIBEIO:
            if (aioperf_eio_read(io_task) != AIOPERF_OK) {
                printf("eio read error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_IO:
            if (aioperf_io_read(io_task) != AIOPERF_OK) {
                printf("io read error\n");
                return AIOPERF_ERROR;
            }
            break;
        default:
            return AIOPERF_ERROR;
            break;
         

    }

    return AIOPERF_OK;
}

int
aioperf_general_write(aioperf_io_task_t *io_task)
{
    switch (aio_type) {
        case USE_AIO:
            if (aioperf_aio_write(io_task) != AIOPERF_OK) {
                printf("aio write error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_XIO:
            if (aioperf_xio_write(io_task) != AIOPERF_OK) {
                printf("xio write error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_LIBAIO:
            if (aioperf_libaio_write(io_task) != AIOPERF_OK) {
                printf("libaio write error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_LIBEIO:
            if (aioperf_eio_write(io_task) != AIOPERF_OK) {
                printf("eio write error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_IO:
            if (aioperf_io_write(io_task) != AIOPERF_OK) {
                printf("io write error\n");
                return AIOPERF_ERROR;
            }
            break;
        default:
            return AIOPERF_ERROR;
            break;
         

    }

    return AIOPERF_OK;
}



int
aioperf_general_mgr_signal_create(aioperf_manager_t *mgr)
{ 
    switch (aio_type) {
        case USE_AIO:
            break;
        case USE_XIO:
            break;
        case USE_LIBAIO:
            break;
        case USE_LIBEIO:
            if (aioperf_eventfd_create(&mgr->signal_fd) != AIOPERF_OK) {
                printf("eio signal create error\n");
                return AIOPERF_ERROR;
            }
            aioperf_eio_eventfd = mgr->signal_fd;
            break;
        case USE_IO:
            break;
        default:
            return AIOPERF_ERROR;
            break;
         
    }
    
    
    return AIOPERF_OK;
}

void
aioperf_general_mgr_signal_release(aioperf_manager_t *mgr)
{
    switch (aio_type) {
        case USE_AIO:
            break;
        case USE_XIO:
            break;
        case USE_LIBAIO:
            break;
        case USE_LIBEIO:
            aioperf_eventfd_release(mgr->signal_fd);
            break;
        case USE_IO:
            break;
        default:
            break;
         
    }
}


int
aioperf_general_mgr_event_add(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository)
{
    switch (aio_type) {
        case USE_AIO:
            break;
            
        case USE_XIO:
            break;
            
        case USE_LIBAIO:
            break;
            
        case USE_LIBEIO:
            event->data.fd = worker->mgr->signal_fd;
            event->events = EPOLLIN | EPOLLET;
            if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, 
                worker->mgr->signal_fd, event) != 0) {
                printf("epoll ctl signal fd error\n");
                return AIOPERF_ERROR;
            }
            return AIOPERF_OK;
            break;

        case USE_IO:
            break;
            
        default:
            return AIOPERF_ERROR;
            break;
         
    }
    
    return AIOPERF_OK;
}

int
aioperf_general_mgr_event_handler(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository)
{
    switch (aio_type) {
        case USE_AIO:
            break;
            
        case USE_XIO:
            break;
            
        case USE_LIBAIO:
            break;
            
        case USE_LIBEIO:
            if (event->data.fd != worker->mgr->signal_fd) {
                return AIOPERF_ERROR;
            }
            aioperf_eio_poll();
            return AIOPERF_OK;
            break;
        case USE_IO:
            break;
            
        default:
            return AIOPERF_ERROR;
            break;
         
    }
    
    return AIOPERF_ERROR;
}

int
aioperf_general_repository_signal_create(aioperf_repository_t *repository)
{ 
    switch (aio_type) {
        case USE_AIO:
            if (aioperf_eventfd_create(&repository->signal_fd) != AIOPERF_OK) {
                printf("aio signal create error\n");
                return AIOPERF_ERROR;
            }
            break;
            
        case USE_XIO:
            if (aioperf_eventfd_create(&repository->signal_fd) != AIOPERF_OK) {
                printf("aio signal create error\n");
                return AIOPERF_ERROR;
            }
            break;
            
        case USE_LIBAIO:
            if (aioperf_eventfd_create(&repository->signal_fd) != AIOPERF_OK) {
                printf("libaio signal1 create error\n");
                return AIOPERF_ERROR;
            }

            if (aioperf_eventfd_create(&repository->signal_fd2) != AIOPERF_OK) {
                printf("libaio signal2 create error\n");
                aioperf_eventfd_release(repository->signal_fd);
                return AIOPERF_ERROR;
            }
            break;
        case USE_LIBEIO:
            if (aioperf_eventfd_create(&repository->signal_fd) != AIOPERF_OK) {
                printf("eio signal create error\n");
                return AIOPERF_ERROR;
            }
            break;
        case USE_IO:
            if (aioperf_eventfd_create(&repository->signal_fd) != AIOPERF_OK) {
                printf("io signal create error\n");
                return AIOPERF_ERROR;
            }
            break;
        default:
            return AIOPERF_ERROR;
            break;
         
    }
    
    
    return AIOPERF_OK;
}

void
aioperf_general_repository_signal_release(aioperf_repository_t *repository)
{
    switch (aio_type) {
        case USE_AIO:
            aioperf_eventfd_release(repository->signal_fd);
            break;
        case USE_XIO:
            aioperf_eventfd_release(repository->signal_fd);
            break;
        case USE_LIBAIO:
            aioperf_eventfd_release(repository->signal_fd);
            aioperf_eventfd_release(repository->signal_fd2);
            break;
        case USE_LIBEIO:
            aioperf_eventfd_release(repository->signal_fd);
            break;
        case USE_IO:
            aioperf_eventfd_release(repository->signal_fd);
            break;
        default:
            break;
         
    }
}

int
aioperf_general_repository_event_add(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository)
{
    switch (aio_type) {
        case USE_AIO:
            event->data.fd = repository->signal_fd;
            event->events = EPOLLIN | EPOLLET;
            if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, 
                repository->signal_fd, event) != 0) {
                printf("epoll ctl signal fd error\n");
                return AIOPERF_ERROR;
            }
            break;
            
        case USE_XIO:
            event->data.fd = repository->signal_fd;
            event->events = EPOLLIN | EPOLLET;
            if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, 
                repository->signal_fd, event) != 0) {
                printf("epoll ctl signal fd error\n");
                return AIOPERF_ERROR;
            }
            break;
            
        case USE_LIBAIO:
            event->data.fd = repository->signal_fd;
            event->events = EPOLLIN | EPOLLET;
            if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, 
                repository->signal_fd, event) != 0) {
                printf("epoll ctl signal fd error\n");
                return AIOPERF_ERROR;
            }

            event->data.fd = repository->signal_fd2;
            event->events = EPOLLIN | EPOLLET;
            if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, 
                repository->signal_fd2, event) != 0) {
                printf("epoll ctl signal fd error\n");
                return AIOPERF_ERROR;
            }
            break;
            
        case USE_LIBEIO:
            event->data.fd = repository->signal_fd;
            event->events = EPOLLIN | EPOLLET;
            if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, 
                repository->signal_fd, event) != 0) {
                printf("epoll ctl signal fd error\n");
                return AIOPERF_ERROR;
            }
            break;
            
        case USE_IO:
            event->data.fd = repository->signal_fd;
            event->events = EPOLLIN | EPOLLET;
            if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, 
                repository->signal_fd, event) != 0) {
                printf("epoll ctl signal fd error\n");
                return AIOPERF_ERROR;
            }
            break;
        default:
            return AIOPERF_ERROR;
            break;
         
    }
    
    return AIOPERF_OK;
}

int
aioperf_general_repository_event_handler(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository)
{
    switch (aio_type) {
        case USE_AIO:
            if (event->data.fd == repository->signal_fd) {
                aioperf_aio_handler(repository);
                return AIOPERF_OK;
            }
            break;
        case USE_XIO:
            if (event->data.fd == repository->signal_fd) {
                aioperf_xio_handler(repository);
                return AIOPERF_OK;
            }
            break;
            
        case USE_LIBAIO:
            if (event->data.fd == repository->signal_fd) {
                aioperf_libaio_efd_handler(repository);
                return AIOPERF_OK;
            } else if (event->data.fd == repository->signal_fd2) {
                aioperf_libaio_efd2_handler(repository);
                return AIOPERF_OK;
            }
            
            break;
        case USE_LIBEIO:
            if (event->data.fd == repository->signal_fd) {
                aioperf_eio_handler(repository);
                return AIOPERF_OK;
            }        
            break;
        case USE_IO:
            if (event->data.fd == repository->signal_fd) {
                aioperf_io_handler(repository);
                return AIOPERF_OK;
            }
            break;
        default:
            break;
         
    }
    
    return AIOPERF_ERROR;
}


