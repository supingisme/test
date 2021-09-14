#ifndef _AIOPERF_GENERAL_H
#define _AIOPERF_GENERAL_H

#include <sys/epoll.h>

int
aioperf_general_init(aioperf_manager_t *mgr);
void
aioperf_general_release(aioperf_manager_t *mgr);
int
aioperf_general_repository_init(aioperf_manager_t *mgr);
void
aioperf_general_repository_release(aioperf_manager_t *mgr);
int
aioperf_general_read(aioperf_io_task_t *io_task);
int
aioperf_general_write(aioperf_io_task_t *io_task);
int
aioperf_general_mgr_signal_create(aioperf_manager_t *mgr);
void
aioperf_general_mgr_signal_release(aioperf_manager_t *mgr);
int
aioperf_general_mgr_event_add(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository);
int
aioperf_general_mgr_event_handler(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository);

int
aioperf_general_repository_signal_create(aioperf_repository_t *mgr);
void
aioperf_general_repository_signal_release(aioperf_repository_t *mgr);
int
aioperf_general_repository_event_add(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository);
int
aioperf_general_repository_event_handler(struct epoll_event *event, 
    aioperf_worker_t *worker, aioperf_repository_t *repository);


#endif
