#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>
#include "aioperf_manager.h"
#include "aioperf_file.h"
#include "aioperf_eventfd.h"
#include "aioperf_conf.h"
#include "aioperf_worker.h"
#include "aioperf_queue.h"
#include "aioperf_signal.h"
#include "aioperf_general.h"

int process_state;
int aio_type;

int main(int argc, char *argv[])
{
    aioperf_manager_t   *mgr = NULL;
    struct rlimit        limit;

    if (argc != 2) {
        printf("parameter error\n");
        return AIOPERF_ERROR;
    }

    if (aioperf_manager_get_aio_type(argv[1]) != AIOPERF_OK) {
        printf("aiotype error\n");
        return AIOPERF_ERROR;
    }

    limit.rlim_max = AIOPERF_ULIMIT_MAX;
    limit.rlim_cur = AIOPERF_ULIMIT_MAX;

    if (setrlimit(RLIMIT_NOFILE, &limit) < 0) {
       printf("setrlimit error\n");
       goto fuck_release;
    }

    aioperf_signal_setup();
    aioperf_signal_block();

    if (!(mgr = aioperf_manager_create())) {
       goto fuck_release;
    }

    if (aioperf_manager_repository_init(mgr) != AIOPERF_OK) {
       goto fuck_mgr_release;
    }


    if (aioperf_worker_create(aioperf_worker_read_recv, mgr, 
        &mgr->read_repository) != AIOPERF_OK) {
       printf("read_recv_worker create error\n");
       goto fuck_repository_release;
    }

    if (aioperf_worker_create(aioperf_worker_read_send, mgr, 
        &mgr->read_repository) != AIOPERF_OK) {
          printf("read_send_worker create error\n");
          goto fuck_worker_release;
    }


    if (aioperf_worker_create(aioperf_worker_write_recv, mgr, 
        &mgr->write_repository) != AIOPERF_OK) {
       printf("write_recv_worker create error\n");
       goto fuck_worker_release;
    }


    if (aioperf_worker_create(aioperf_worker_write_send, mgr, 
        &mgr->write_repository)
       != AIOPERF_OK) {
       printf("write_send_worker create error\n");
       goto fuck_worker_release;
    }


    while (1) {
       aioperf_signal_wait();

       if (process_state & PROCESS_QUIT || process_state & PROCESS_TERM) {
           printf("\nrecv quit\n");
           break;
       }
    }

fuck_worker_release:
    aioperf_worker_release(mgr);
    
fuck_repository_release:
    aioperf_manager_repository_release(mgr);
    
fuck_mgr_release:
    aioperf_manager_release(mgr);

fuck_release:    
    printf("main quit\n");
    
    return AIOPERF_OK;
}


aioperf_manager_t *
aioperf_manager_create()
{
    aioperf_manager_t *mgr = NULL;
    aioperf_pool_t    *mgr_pool = NULL;
    unsigned int       mgr_pool_size = 0;

    mgr_pool_size = sizeof(aioperf_manager_t);
    if (!(mgr_pool = aioperf_memory_pool_create(mgr_pool_size, SYSPAGE_SIZE))) {
        printf("pool create error\n");
        return NULL;
    }
    
    if (!(mgr = (aioperf_manager_t *)aioperf_memory_pool_alloc(mgr_pool, 
        sizeof(aioperf_manager_t)))) {
        printf("pool alloc error\n");
        goto fuck_pool_release;
    }

    mgr->pool = mgr_pool;
    mgr->worker_head.pre = NULL;
    mgr->worker_head.next = NULL;
    
    if (pthread_mutex_init(&mgr->worker_lock, NULL) != 0) {
        printf("mutex_init error\n");
        goto fuck_pool_release;
    }

    if (aioperf_conf_mgr_init(mgr, AIOPERF_CONF_PATH) != AIOPERF_OK) {
        printf("conf mgr init error\n");
        goto fuck_mutex_release;
    }
    
    if (aioperf_general_init(mgr) != AIOPERF_OK) {
        printf("general init error\n");
        goto fuck_mutex_release;
    }

    if (aioperf_general_mgr_signal_create(mgr) != AIOPERF_OK) {
        printf("general signal create error\n");
        goto fuck_general_release;
    }

    return mgr;
    
fuck_general_release:
    aioperf_general_release(mgr);
    
fuck_mutex_release:
    if (pthread_mutex_destroy(&mgr->worker_lock) != 0) {
        printf("mutex_destroy error\n");
    }
    
fuck_pool_release:
    aioperf_memory_pool_release(mgr_pool);

    return NULL;
}


int
aioperf_manager_release(aioperf_manager_t *mgr)
{    
    if (!mgr) {
        printf("mgr NULL\n");
        return AIOPERF_ERROR;
    }

    aioperf_general_mgr_signal_release(mgr);
    aioperf_general_release(mgr);

    if (pthread_mutex_destroy(&mgr->worker_lock) != 0) {
        printf("mutex_destroy error\n");
    }
    
    mgr->worker_head.pre = NULL;
    mgr->worker_head.next = NULL;
    
    aioperf_memory_pool_release(mgr->pool);
    return AIOPERF_OK;
}

int
aioperf_manager_repository_init(aioperf_manager_t *mgr)
{
    mgr->read_repository.mgr = mgr;
    mgr->write_repository.mgr = mgr;
    
    if (aioperf_conf_repository_init(mgr, AIOPERF_CONF_PATH) != AIOPERF_OK) {
        printf("conf parse error\n");
        return AIOPERF_ERROR;
    }

    if (aioperf_files_init(mgr) != AIOPERF_OK) {
        printf("aioperf_files_init error\n");
        return AIOPERF_ERROR;
    }

    if (aioperf_general_repository_init(mgr) != AIOPERF_OK) {
        printf("general repository error\n");
        goto fuck_files_release;
    }

    if (aioperf_general_repository_signal_create(&mgr->read_repository) 
        != AIOPERF_OK) {
        printf("repository rsignal create error\n");
        goto fuck_repository_release;
    }

    if (aioperf_general_repository_signal_create(&mgr->write_repository) 
        != AIOPERF_OK) {
        printf("repository wsignal create error\n");
        goto fuck_repository_rsignal_release;
    }

    if (aioperf_queue_init(&mgr->read_repository.que) != AIOPERF_OK) {
        printf("queue init error\n");
        goto fuck_repository_wsignal_release;
    }

    if (aioperf_queue_init(&mgr->write_repository.que) != AIOPERF_OK) {
        printf("queue init error\n");
        goto fuck_read_queue_release;
    }

    if (aioperf_eventfd_create(&mgr->read_repository.over_evfd) != AIOPERF_OK) {
        printf("over evfd create error\n");
        goto fuck_write_queue_release;
    }

    if (aioperf_eventfd_create(&mgr->write_repository.over_evfd) != AIOPERF_OK) {
        printf("over evfd create error\n");
        goto fuck_read_evfd_release;
    }

   return AIOPERF_OK;
   
fuck_read_evfd_release:
    aioperf_eventfd_release(mgr->read_repository.over_evfd);
    
fuck_write_queue_release:
    aioperf_queue_release(&mgr->write_repository.que);
    
fuck_read_queue_release:
    aioperf_queue_release(&mgr->read_repository.que);
    
fuck_repository_wsignal_release:
    aioperf_general_repository_signal_release(&mgr->write_repository);
    
fuck_repository_rsignal_release:
    aioperf_general_repository_signal_release(&mgr->read_repository);
    
fuck_repository_release:
    aioperf_general_repository_release(mgr);
    
fuck_files_release:
    aioperf_files_release(mgr);
    return AIOPERF_ERROR;
}


void
aioperf_manager_repository_release(aioperf_manager_t *mgr)
{
    aioperf_eventfd_release(mgr->read_repository.over_evfd);
    aioperf_eventfd_release(mgr->write_repository.over_evfd);
    aioperf_queue_release(&mgr->read_repository.que);
    aioperf_queue_release(&mgr->write_repository.que);
    aioperf_general_repository_signal_release(&mgr->write_repository);
    aioperf_general_repository_signal_release(&mgr->read_repository);
    aioperf_general_repository_release(mgr);
    aioperf_files_release(mgr);
}

int
aioperf_manager_get_aio_type(const char *type)
{
    if (strcmp(type, "-x") == 0) {
        aio_type = USE_XIO;
        printf("\n*************************XIO TEST START****************\n");
        return AIOPERF_OK;
    } else if (strcmp(type, "-a") == 0) {
        aio_type = USE_AIO;
        printf("\n*************************AIO TEST START****************\n");
        return AIOPERF_OK;
    } else if (strcmp(type, "-e") == 0) {
        aio_type = USE_LIBEIO;
        printf("\n*************************EIO TEST START****************\n");
        return AIOPERF_OK;
    } else if (strcmp(type, "-n") == 0) {
        aio_type = USE_LIBAIO;
        printf("\n*************************LIBAIO TEST START****************\n");
        return AIOPERF_OK;
    } else if (strcmp(type, "-s") == 0) {
        aio_type = USE_IO;
        printf("\n*************************IO TEST START****************\n");
        return AIOPERF_OK;
    }
    return AIOPERF_ERROR;
}

