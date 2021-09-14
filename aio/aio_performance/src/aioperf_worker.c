#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <execinfo.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/eventfd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/epoll.h>
#include "aioperf_manager.h"
#include "aioperf_worker.h"
#include "aioperf_eventfd.h"
#include "aioperf_file.h"
#include "aioperf_queue.h"
#include "aioperf_general.h"

extern int aio_type;

int
aioperf_worker_create(aioperf_worker_func_t func, aioperf_manager_t *mgr, 
    aioperf_repository_t *repository)
{
    aioperf_worker_t   *worker = NULL;
    int                 ret = 0;
    aioperf_pool_t     *worker_pool = NULL;
    unsigned int        worker_pool_size = 0;


    worker_pool_size = sizeof(aioperf_worker_t);

    if (repository->conf_info->file_num <= 0) {
        printf("worker not run because file num is 0\n");
        return AIOPERF_OK;
    }
    
    if (!(worker_pool = aioperf_memory_pool_create(worker_pool_size, SYSPAGE_SIZE))) {
        printf("worker_pool create error\n");
        return AIOPERF_ERROR;
    }
    
    if (!(worker = (aioperf_worker_t *)aioperf_memory_pool_alloc(worker_pool, 
        sizeof(aioperf_worker_t)))){
        printf("pool alloc error\n");
        goto fuck_pool_release;
    }
 
    worker->tid  = 0;
    worker->worker_release_start = 0;
    worker->worker_release_done = 0;
    worker->mgr = mgr;
    worker->loop_now = 0;
    worker->pool = worker_pool;

    if ((ret = pthread_create(&worker->tid, NULL, func, worker)) != 0) {
        printf("pthread_create error\n");
        goto fuck_pool_release;
    }

    pthread_mutex_lock(&mgr->worker_lock);
    worker->next = mgr->worker_head.next;
    mgr->worker_head.next = worker;
    pthread_mutex_unlock(&mgr->worker_lock);
    
    return AIOPERF_OK;
    
fuck_pool_release:
    aioperf_memory_pool_release(worker_pool);
    
    return AIOPERF_ERROR;
}



void
aioperf_worker_release(aioperf_manager_t *mgr)
{
    aioperf_worker_t   *worker = NULL;
    aioperf_worker_t   *worker_next = NULL;

    worker = mgr->worker_head.next;   
    while (worker) {
        worker->worker_release_start = 1;
        if (worker->evfd) {
            aioperf_eventfd_write(worker->evfd);
        }
        worker = worker->next;
    }

    worker = mgr->worker_head.next;
    while (worker) {
        if (worker->worker_release_done == 1) {
            worker_next = worker->next;
            aioperf_memory_pool_release(worker->pool);

            worker = worker_next;
        } else {
            continue;
        }
    }
}


void *
aioperf_worker_write_recv(void *data)
{
    aioperf_worker_t        *worker = NULL;
    double                   sec_elapse;
    aioperf_conf_file_t     *file_t = NULL;
    aioperf_conf_file_t     *next = NULL;
    unsigned long            all_files_size = 0;
    struct epoll_event       events[100];
    struct epoll_event       evfd_event;
    struct epoll_event       noty_event;
    struct epoll_event       over_event;
    struct epoll_event       poll_event;
    int                      ret = 0;
    int                      i = 0;
    int                      epoll_out = 0;
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    int                      send_over = 0;
    unsigned long            val = 0;
    

    pthread_detach(pthread_self());

    aioperf_memory_set(&evfd_event, 0, sizeof(struct epoll_event));
    aioperf_memory_set(&noty_event, 0, sizeof(struct epoll_event));
    aioperf_memory_set(&poll_event, 0, sizeof(struct epoll_event));
    
    worker = (aioperf_worker_t *)data;
    repository = &worker->mgr->write_repository;
    conf_info = repository->conf_info;


    if (aioperf_eventfd_create(&worker->evfd) != AIOPERF_OK) {
        printf("aioperf_eventfd_create error\n");
        goto fuck_release;
    }
    
    if ((worker->epoll_fd = epoll_create(1)) < 0) {
        printf("epoll create error\n");
        goto fuck_eventfd_release;
    }
    
    if (aioperf_general_mgr_event_add(&noty_event, worker, repository) 
        != AIOPERF_OK) {
        printf("general event add error\n");
        goto fuck_epoll_release;
    }

    if (aioperf_general_repository_event_add(&poll_event, worker, repository)
        != AIOPERF_OK) {
        printf("repository event add error\n");
        goto fuck_epoll_release;
    }
    
    evfd_event.data.fd = worker->evfd;
    evfd_event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, worker->evfd, &evfd_event) 
        != 0) {
        printf("epoll ctl evfd error\n");
        goto fuck_epoll_release;
    }

    over_event.data.fd = repository->over_evfd;
    over_event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, repository->over_evfd,
        &over_event) != 0) {
        printf("epoll ctl over fd error\n");
        goto fuck_epoll_release;
    }

    if (worker->worker_release_start == 1) {
        goto fuck_epoll_release;
    }
    
    worker->loop_now = 1;

    while (!epoll_out) {
        ret = epoll_wait(worker->epoll_fd, events, 1000, 10);

        if (ret == 0) {
            continue;
        }

        if (ret < 0) {
            printf("epoll_wait error\n");
            continue;
        }

        for (i = 0; i < ret; i++) {
            
            if (aioperf_general_mgr_event_handler(&events[i], worker, repository) 
                == AIOPERF_OK) {
                

            } else if (aioperf_general_repository_event_handler(&events[i], 
                worker, repository) == AIOPERF_OK) {
                /*
                if (send_over &&
                    (repository->io_finish_num == repository->io_req_num)) {
                    printf("WRITE:all io finish\n");
                    epoll_out = 1;
                }*/

            } else if (events[i].data.fd == worker->evfd) {
                aioperf_eventfd_handler(worker);
                epoll_out = 1;
                
            } else if (events[i].data.fd == repository->over_evfd) {
                aioperf_eventfd_read(repository->over_evfd, &val);
                send_over = 1;
                
            }

            if (send_over &&
                (repository->io_finish_num == repository->io_req_num)) {
                printf("WRITE: all io finish\n");
                epoll_out = 1;
            }
        }
    }
    
    gettimeofday(&repository->t_end, NULL);
    printf("WRITE: io task num = %d, io error = %d\n", repository->io_finish_num, 
        repository->io_error_num);
    
    aioperf_worker_timeval_subtract(&repository->t_elapse, &repository->t_end, 
        &repository->t_start);
    
    sec_elapse = (double)repository->t_elapse.tv_sec + 
        (double)repository->t_elapse.tv_usec / (double)1000000;

    file_t = conf_info->conf_file;
    while (file_t) {
        next = file_t->next;
        all_files_size += (unsigned long)file_t->file_size * 
            (unsigned long)file_t->percent * (conf_info->file_num / 100);
        file_t = next;
    }

    printf("WRITE: time elapse %ld.%06ldS, write %ld MB (%lfMB/S %ld/S)\n", 
        repository->t_elapse.tv_sec, repository->t_elapse.tv_usec, 
        (unsigned long)((double)all_files_size / (double)AIOPERF_MBYTE_SIZE),
        ((double)all_files_size / ((double)AIOPERF_MBYTE_SIZE * sec_elapse)),
        (unsigned long)((double)repository->io_finish_num / (double)sec_elapse));

    while (worker->worker_release_start != 1) {
        usleep(10000);
    }

fuck_epoll_release:
    if (close(worker->epoll_fd) < 0) {
        printf("close epoll fd error\n");
    }
    
fuck_eventfd_release:
    aioperf_eventfd_release(worker->evfd);

fuck_release:
    worker->worker_release_done = 1;

    return NULL;
}


void *
aioperf_worker_read_recv(void *data)
{
    aioperf_worker_t        *worker = NULL;
    double                   sec_elapse;
    aioperf_conf_file_t     *file_t = NULL;
    aioperf_conf_file_t     *next = NULL;
    unsigned long            all_files_size = 0;
    struct epoll_event       events[100];
    struct epoll_event       evfd_event;
    struct epoll_event       noty_event;
    struct epoll_event       over_event;
    struct epoll_event       poll_event;
    int                      ret = 0;
    int                      i = 0;
    int                      epoll_out = 0;
    aioperf_repository_t    *repository = NULL;
    aioperf_conf_info_t     *conf_info = NULL;
    int                      send_over = 0;
    unsigned long            val = 0;


    pthread_detach(pthread_self());

    aioperf_memory_set(&evfd_event, 0, sizeof(struct epoll_event));
    aioperf_memory_set(&noty_event, 0, sizeof(struct epoll_event));
    aioperf_memory_set(&poll_event, 0, sizeof(struct epoll_event));
    
    worker = (aioperf_worker_t *)data;
    repository = &worker->mgr->read_repository;
    conf_info = repository->conf_info;

    if (aioperf_eventfd_create(&worker->evfd) != AIOPERF_OK) {
        printf("aioperf_eventfd_create error\n");
        goto fuck_release;
    }
    
    if ((worker->epoll_fd = epoll_create(1)) < 0) {
        printf("epoll create error\n");
        goto fuck_eventfd_release;
    }   

    if (aioperf_general_mgr_event_add(&noty_event, worker, repository) 
        != AIOPERF_OK) {
        printf("general event add error\n");
        goto fuck_epoll_release;
    }

    if (aioperf_general_repository_event_add(&poll_event, worker, repository)
        != AIOPERF_OK) {
        printf("repository event add error\n");
        goto fuck_epoll_release;
    }
    
    evfd_event.data.fd = worker->evfd;
    evfd_event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, worker->evfd, &evfd_event) 
        != 0) {
        printf("epoll ctl error\n");
        goto fuck_epoll_release;
    }

    over_event.data.fd = repository->over_evfd;
    over_event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(worker->epoll_fd, EPOLL_CTL_ADD, repository->over_evfd,
        &over_event) != 0) {
        printf("epoll ctl over fd error\n");
        goto fuck_epoll_release;
    }


    if (worker->worker_release_start == 1) {
        goto fuck_epoll_release;
    }
    
    worker->loop_now = 1;

    while (!epoll_out) {
        ret = epoll_wait(worker->epoll_fd, events, 100, 10);

        if (ret == 0) {
            continue;
        }

        if (ret < 0) {
            printf("epoll_wait error\n");
        }

        for (i = 0; i < ret; i++) {
            if (aioperf_general_mgr_event_handler(&events[i], worker, repository) 
                == AIOPERF_OK) {
                

            } else if (aioperf_general_repository_event_handler(&events[i], 
                worker, repository) == AIOPERF_OK) {
                /*if (send_over &&
                    (repository->io_finish_num == repository->io_req_num)) {
                    printf("all io finish\n");
                    epoll_out = 1;
                }*/
                
            } else if (events[i].data.fd == worker->evfd) {
                aioperf_eventfd_handler(worker);
                epoll_out = 1;
                
            } else if (events[i].data.fd == repository->over_evfd) {
                aioperf_eventfd_read(repository->over_evfd, &val);
                send_over = 1;
                printf("READ: send over\n");   
            }
            
            if (send_over &&
                (repository->io_finish_num == repository->io_req_num)) {
                printf("READ: all io finish\n");
                epoll_out = 1;
            }
        }        
    }
    
    gettimeofday(&repository->t_end, NULL);
    printf("READ: io task num = %d, io error = %d\n", repository->io_finish_num, 
        repository->io_error_num);
    
    aioperf_worker_timeval_subtract(&repository->t_elapse, &repository->t_end, 
        &repository->t_start);
    
    sec_elapse = (double)repository->t_elapse.tv_sec + 
        (double)repository->t_elapse.tv_usec / (double)1000000;

    file_t = conf_info->conf_file;
    while (file_t) {
        next = file_t->next;
        all_files_size += (unsigned long)file_t->file_size * 
            (unsigned long)file_t->percent * 
            (unsigned long)conf_info->file_num / 100;
        file_t = next;
    }
    
    printf("READ: time elapse %ld.%06ldS, read %ld MB (%lfMB/S %ld/S)\n", 
        repository->t_elapse.tv_sec, repository->t_elapse.tv_usec, 
        all_files_size / AIOPERF_MBYTE_SIZE,
        ((double)all_files_size / ((double)AIOPERF_MBYTE_SIZE * sec_elapse)),
        (unsigned long)((double)repository->io_finish_num / (double)sec_elapse));

    while (worker->worker_release_start != 1) {
        usleep(10000);
    }

fuck_epoll_release:
    if (close(worker->epoll_fd) < 0) {
        printf("close epoll fd error\n");
    }
    
fuck_eventfd_release:
    aioperf_eventfd_release(worker->evfd);

fuck_release:
    worker->worker_release_done = 1;

    return NULL;
}


void *
aioperf_worker_write_send(void *data)
{
    aioperf_worker_t           *worker = NULL;
    aioperf_repository_t       *repository = NULL;
    aioperf_pool_t             *pool = NULL;

    pthread_detach(pthread_self());
    
    worker = (aioperf_worker_t *)data;
    repository = &worker->mgr->write_repository;
    pool = repository->pool;
    
    while (!worker->next->loop_now) {
        if (worker->worker_release_start) {
            goto fuck_release;
        }
        usleep(10000);
    }

    gettimeofday(&repository->t_start, NULL);

    printf("WRITE: send io task start!\n");
    if (aioperf_files_write(worker, repository, pool) != AIOPERF_OK) {
        printf("files write send error\n");
        goto fuck_release;
    }
    printf("WRITE: send io task over!\n");

    
    while (!worker->worker_release_start) {
        usleep(10000);
    }
    
fuck_release:
    worker->worker_release_done = 1;

    return NULL;
}

void *
aioperf_worker_read_send(void *data)
{
    aioperf_worker_t           *worker = NULL;
    aioperf_repository_t       *repository = NULL;
    aioperf_pool_t             *pool = NULL;

    pthread_detach(pthread_self());
    
    worker = (aioperf_worker_t *)data;
    repository = &worker->mgr->read_repository;
    pool = repository->pool;
    
    while (!worker->next->loop_now) {
        if (worker->worker_release_start) {
            goto fuck_release;
        }
        usleep(10000);
    }

    gettimeofday(&repository->t_start, NULL);

    printf("READ: send io task start!\n");
    if (aioperf_files_read(worker, repository, pool) != AIOPERF_OK) {
        printf("files read send error\n");
        goto fuck_release;
    }
    printf("READ: send io task over!\n");

    
    while (!worker->worker_release_start) {
        usleep(10000);
    }
    
fuck_release:
    worker->worker_release_done = 1;

    return NULL;

}


int 
aioperf_worker_timeval_subtract(struct timeval *result, struct timeval *t2, 
    struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 
        1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}


