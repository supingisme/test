#ifndef _AIOPERF_LIBEV_H
#define _AIOPERF_LIBEV_H

#include <eio.h>

extern int aioperf_eio_eventfd;

int
aioperf_eio_init(aioperf_manager_t *mgr);
void
aioperf_eio_release();
int
aioperf_eio_read(aioperf_io_task_t *io_task);
int
aioperf_eio_write(aioperf_io_task_t *io_task);
int
aioperf_eio_callback(eio_req *req);
void
aioperf_eio_want_poll(void);
void
aioperf_eio_done_poll(void);
int
aioperf_eio_poll(void);
int
aioperf_eio_handler(aioperf_repository_t *repository);

#endif
