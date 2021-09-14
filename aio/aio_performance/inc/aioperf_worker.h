#ifndef _AIOPERF_WORKER_H
#define _AIOPERF_WORKER_H


int
aioperf_worker_create(aioperf_worker_func_t func, aioperf_manager_t *mgr, 
    aioperf_repository_t *repository);
void
aioperf_worker_release(aioperf_manager_t *mgr);
void *
aioperf_worker_read_recv(void *data);
void *
aioperf_worker_write_recv(void *data);
void *
aioperf_worker_read_send(void *data);
void *
aioperf_worker_write_send(void *data);
aioperf_loop_t*
aioperf_worker_loop_create();
int
aioperf_worker_loop_release(aioperf_loop_t *loop);
int 
aioperf_worker_timeval_subtract(struct timeval *result, struct timeval *t2, 
    struct timeval *t1);


#endif
